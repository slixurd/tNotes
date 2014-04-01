// 笔记集合，返回Note集合类实例

define(['NoteModel', 'noteDb', 'util', 'setting', 'syncHelper'],
    function (NoteModel, database, util, setting, syncHelper) {

var NoteCollection = Backbone.Collection.extend({

    model: NoteModel,
    
    database: database,
    storeName: database.storeName,

    visibility: true, // 笔记视图可见性

    current: null, // 当前选中的笔记
    currentNotes: [], // 当前显示的笔记
    currentNotesIds: [], // 当前笔记id列表，可能与folder模型相关联

    // 增加同步创建队列
    addSyncCreated: function (id) {
        var createdList = setting.get('noteSyncCreated');
        createdList.push(id);
        setting.save();
        setting.synchronize();
    },
    removeSyncCreated: function (id) {
        var createdList = setting.get('noteSyncCreated');
        util.removeArrayValue(createdList, id);
        setting.save();
    },

    // 增加同步删除队列
    addSyncDeleted: function (id) {
        var deletedList = setting.get('noteSyncDeleted');
        deletedList.push(id);
        setting.save();
        setting.synchronize();
    },
    removeSyncDeleted: function (id) {
        var deletedList = setting.get('noteSyncDeleted');
        util.removeArrayValue(deletedList, id);
        setting.save();
    },

    // 增加同步更新队列
    addSyncModified: function (id) {
        var modifiedList = setting.get('noteSyncModified');
        util.removeArrayValue(modifiedList, id);
        modifiedList.push(id);
        setting.save();
        setting.synchronize();
    },
    removeSyncModified: function (id) {
        var modifiedList = setting.get('noteSyncModified');
        util.removeArrayValue(modifiedList, id);
        setting.save();
    },

    // 添加note到当前的显示列表
    addNoteToCurrentNotes: function (id) {
        this.currentNotesIds.push(id);
        this.fetchNotes();
    },

    // 清除所有数据
    clear: function () {
        // 清除内存中
        this.each(function (model) {
            model.destroy();
        });
        // 清除数据库中
        var request = indexedDB.open('notes');
        request.onsuccess = function () {
            var db = request.result,
                transaction = db.transaction(["notes"], "readwrite"),
                store = transaction.objectStore('notes');
            store.clear();
        };
        this.setCurrentNotes([]);
        this.setCurrent(null);
    },

    // 清空显示列表
    clearCurrentNotes: function () {
        this.currentNotesIds = [];
        this.fetchNotes();
    },

    // 根据id号删除对应的Model数据
    deleteById: function (id) {
        this.get(id).destroy();
    },

    deleteByIds: function (ids) {
        var i, len;
        for (i = 0, len = ids.length; i < len; i++) {
            this.deleteById(ids[i]);
        }
    },

    // 从数据库中取出数据存入currentNotes中
    fetchNotes: function () {
        var i, len, ids = this.currentNotesIds;
            this.currentNotes = [];
        for (i = 0, len = ids.length; i < len; i++) {
            var note = this.get(ids[i]);
            this.currentNotes[i] = note.toJSON();
        }
        this.trigger('currentNotesChanged');
    },

    // 从远程数据库获取笔记
    fetchRemote: function (folderId) {
        // folderId小于0时直接返回
        if (folderId < 0) {
            return;
        }
        if (syncHelper.isAllSync() === true) {
            this.trigger('fetchRemote', folderId);
        } else {
            setting.syncFinishedHandler = $.proxy(function () {
                this.fetchRemote(folderId);
            }, this);
            setting.synchronize();
        }
    },

    // 从远程数据库获取但单条笔记
    fetchRemoteSingle: function (noteId) {
        // noteId小于0时直接返回
        if (noteId < 0) {
            return;
        }
        if (syncHelper.isAllSync() === true) {
            this.trigger('fetchRemoteSingle', noteId);
        } else {
            setting.syncFinishedHandler = $.proxy(function () {
                this.fetchRemoteSingle(noteId);
            }, this);
            setting.synchronize();
        }
    },

    // 获取当前笔记
    getCurrent: function () {
        return this.current;
    },

    // 获取要显示的笔记内容
    getCurrentNotes: function () {
        return this.currentNotes;
    },

    // 获取当前显示笔记的id
    getCurrentNotesIds: function () {
        return this.currentNotesIds;
    },

    // 获取当前可见性
    getVisibility: function () {
        return this.visibility;
    },

    // 新建笔记
    newNote: function (folderId) {
        var note = this.create({
            folderId: folderId,
            title: '标题',
            content: ''
        });
        this.setCurrent(note.get('id'));
        this.trigger('newNote');
        return note;
    },

    // 删除当前显示列表中的指定id
    removeNoteFromCurrentNotes: function (id) {
        this.currentNotesIds = util.removeArrayValue(this.currentNotesIds, id);
        this.fetchNotes();
    },

    // 设置当前笔记
    setCurrent: function (id, fetchRemote) {
        if (id === null) {
            this.current = null;
        } else {
            this.current = this.get(id);
        }
        if (fetchRemote === true) {
            this.fetchRemoteSingle(id);
        }
        this.trigger('currentChanged');
    },

    // 设置要显示的笔记
    setCurrentNotes: function (ids) {
        this.currentNotesIds = util.singleArrayClone(ids);
        this.fetchNotes();
    },

    // 设置可见性
    setVisibility: function (flag) {
        this.visibility = flag;
        this.trigger('visibilityChanged');
    },

    // 更新folderId
    updateFolderId: function (oldId, newId) {
        var notes = this.where({
            folderId: oldId
        });
        var i, len;
        for (i = 0, len = notes.length; i < len; i++) {
            var note = notes[i];
            note.set('folderId', newId);
            note.save();
        }
    },

    // 更新笔记id，返回所在的folderId
    updateId: function (oldId, newId) {
        // 更新笔记的id
        var note = this.get(oldId),
            newNote = _.clone(note.attributes),
            folderId = note.get('folderId');
        newNote.id = newId;
        this.create(newNote);
        // 如果当前笔记的id与oldId一致，则将其切换到新创建的对象中
        if (this.current && this.current.get('id') === oldId) {
            this.current = this.get(newId);
        }
        // 更新显示视图里的id
        var notesIds = this.currentNotesIds;
        if (util.replaceArrayValue(notesIds, oldId, newId)) {
            this.setCurrentNotes(notesIds);
        }
        note.destroy();
        return folderId;
    }

});

// 创建noteCollection实例并获取数据
var noteCollection = new NoteCollection;
noteCollection.fetch();

return noteCollection;

});
// 文件夹集合，返回Folder集合类实例

define(['FolderModel', 'folderDb', 'setting', 'util', 'syncHelper'],
    function (FolderModel, database, setting, util, syncHelper) {

var FolderCollection = Backbone.Collection.extend({

    model: FolderModel,

    database: database,
    storeName: database.storeName,

    visibility: true, // 文件夹视图可见性

    current: null, // 当前文件夹

    comparator: function (folder) {
        return -folder.get('modifiedTime'); // 按修改日期排序
    },

    // 增加删除同步创建队列
    addSyncCreated: function (id) {
        var createdList = setting.get('folderSyncCreated');
        createdList.push(id);
        setting.save();
        setting.synchronize();
    },
    removeSyncCreated: function (id) {
        var createdList = setting.get('folderSyncCreated');
        util.removeArrayValue(createdList, id);
        setting.save();
    },

    // 增加删除同步删除队列
    addSyncDeleted: function (id) {
        var deletedList = setting.get('folderSyncDeleted');
        deletedList.push(id);
        setting.save();
        setting.synchronize();
    },

    // 增加删除同步更新队列
    addSyncModified: function (id) {
        var modifiedList = setting.get('folderSyncModified');
        modifiedList = util.removeArrayValue(modifiedList, id);
        modifiedList.push(id);
        setting.set('folderSyncModified', modifiedList);
        setting.synchronize();
    },
    removeSyncModified: function (id) {
        var modifiedList = setting.get('folderSyncModified');
        util.removeArrayValue(modifiedList, id);
        setting.save();
    },

    // 清除所有数据
    clear: function () {
        // 清除数据库中
        var request = indexedDB.open('folders'),
            that = this;
        request.onsuccess = function () {
            var db = request.result,
                transaction = db.transaction(["folders"], "readwrite"),
                store = transaction.objectStore('folders');
            var r = store.clear();
            r.onsuccess = function () {
                that.reset();
                that.setCurrent(null);
            }
        };
    },

    // 删除当前文件夹
    deleteCurrent: function () {
        this.current.destroy();
        this.current = null;
    },

    // 删除除此之外的文件夹
    deleteExceptThese: function (remoteList) {
        var local = this.toJSON(), localList = [], i, len, folder;
        for (i = 0, len = local.length; i < len; i++) {
            var localId = local[i].id;
            if (remoteList.indexOf(localId) < 0 && localId > 0) {
                folder = this.get(localId);
                folder.destroy();
            }
        }
    },

    // 从远端获取数据
    fetchRemote: function () {
        if (syncHelper.isAllSync() === true) {
            this.trigger('fetchRemote');
        } else {
            setting.syncFinishedHandler = $.proxy(this.fetchRemote, this);
            setting.synchronize();
        }
    },

    // 获取当前文件夹
    getCurrent: function () {
        return this.current;
    },

    // 获取当前可见性
    getVisibility: function () {
        return this.visibility;
    },

    // 重命名当前文件夹
    renameCurrent: function (name) {
        this.current.set({
            name: name,
            modifiedTime: _.now()
        });
    },

    // 设置当前文件夹
    setCurrent: function (id) {
        if (id === null) {
            this.current = null;
        } else {
            this.current = this.get(id);
        }
        this.trigger('currentChanged'); // 产生当前文件夹改变事件
    },

    // 设置可见性
    setVisibility: function (flag) {
        this.visibility = flag;
        this.trigger('visibilityChanged');
    },

    // 更新文件夹的id
    updateId: function (oldId, newId) {
        // 更新文件夹的id，先创建一个副本，再删除原来的
        var folder = this.get(oldId),
            newFolder = _.clone(folder.attributes);
        newFolder.id = newId;
        this.create(newFolder);
        // 如果当前文件夹的id与oldId一致，则将其切切换到新创建的对象中
        if (this.current && this.current.get('id') === oldId) {
            this.setCurrent(newId);
        }
        folder.destroy();
    }

});

// 创建folderCollection实例并获取数据
var folderCollection = new FolderCollection;
folderCollection.fetch();

return folderCollection;

});

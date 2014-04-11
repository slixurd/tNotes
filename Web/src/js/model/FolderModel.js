// 文件夹模型，返回的是Folder模型类，供Folder集合类使用

define(['setting', 'folderDb', 'util'], function (setting, database, util) {

var FolderModel = Backbone.Model.extend({

    // indexDb存储项
    database : database,
    storeName: database.storeName,

    defaults: {
        id          : 0,    // 本地存储的id
        name        : '',   // 文件夹名
        notes       : [],   // 笔记
        createTime  : 0,    // 创建时间
        modifiedTime: 0     // 修改时间
    },

    initialize: function (value) {
        // 如果传值没有id，则说明是创建新对象，赋予新的id
        if (!value.id) {
            var id        = setting.get('folderId'),
                timeStamp = _.now();
            this.set({
                id          : -id, // 使用负数表明其为本地ip
                createTime  : timeStamp,
                modifiedTime: timeStamp
            });
            setting.set('folderId', id + 1);
        }
    },

    // 添加笔记id
    insertNoteId: function (id) {
        var notes = this.get('notes');
        util.removeArrayValue(notes, id);
        notes.push(id);
        this.set({
            notes: notes
        });
        this.save();
    },

    // 删除笔记id
    removeNoteId: function (id) {
        var notes = this.get('notes');
        notes = util.removeArrayValue(notes, id);
        this.set({
            notes: notes,
            modifiedTimestamp: _.now()
        });
        this.save();
    }

});

return FolderModel;

});

// 文件夹模型，返回的是Folder模型类，供Folder集合类使用

define(['setting', 'folderDb'], function (setting, database) {

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

    initialize: function (val) {
        // 如果传值没有id，则说明是创建新对象，赋予新的id
        if (!value.id) {
            var id        = setting.get('folderId'),
                timeStamp = _.now();
            this.set({
                id          : -id, // 使用负数标明其为本地id
                createTime  : timeStamp,
                modifiedTime: timeStamp
            });
            setting.set('folderId', id + 1);
        }

        // 保证每次数据改变后自动存储
        _.bindAll(this, 'save');
        this.bind('change', function () {
            this.save();
        });
    }

});

return FolderModel;

});
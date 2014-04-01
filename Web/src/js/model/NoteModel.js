// 笔记模型，返回的是Note模型类，供Note集合类使用

define(['setting', 'noteDb'], function (setting, database) {

var NoteModel = Backbone.Model.extend({

    // indexDb存储项
    database : database,
    storeName: database.storeName,

    defaults: {
        id          : 0,    // 本地存储的id
        folderId    : 0,    // 所属文件夹id
        title       : '',   // 笔记标题
        content     : '',   // 笔记内容
        createTime  : 0,    // 创建时间
        modifiedTime: 0     // 修改时间
    },

    initialize: function (value) {
        // 如果传值没有id，则说明是创建新对象，赋予新的id
        if (!value.id) {
            var id        = setting.get('noteId'),
                timeStamp = _.now();
            this.set({
                id          : -id, // 使用负数表明其为本地ip
                createTime  : timeStamp,
                modifiedTime: timeStamp
            });
            setting.set('noteId', id + 1);
        }
    }

});

return NoteModel;

});
// 笔记模型
define(['model/setting', 'util', 'database/note'], function (setting, util, database) {

var Note = Backbone.Model.extend({
    database: database,
    storeName: 'notes',
    defaults: {
        id: 0,
        folderId: 0,
        title: '未命名',
        content: '',
        createTimestamp: 0,
        modifiedTimestamp: 0
    },
    initialize: function (value) {
        // 如果传值中没有id，则说明是创建新对象，赋予新的id
        if (typeof value.id === 'undefined') {
            // 设置初始值
            var lastInsertId = setting.get('noteLastInsertId'),
                timestamp = util.getTimestamp();
            this.set({
                id: lastInsertId,
                createTimestamp: timestamp,
                modifiedTimestamp: timestamp
            });
            // ID自增量加1
            setting.set('noteLastInsertId', lastInsertId + 1);
        }
    }
});

return Note;

});
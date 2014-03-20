// 文件夹模型
define(['model/setting', 'util', 'database/folder'], function (setting, util, database) {

var Folder = Backbone.Model.extend({
    database: database,
    storeName: 'folders',
    defaults: {
        id: 0,
        name: '未命名',
        notes: [],
        createTimestamp: 0,
        modifiedTimestamp: 0
    },
    initialize: function (value) {
        // 如果传值中没有id，则说明是创建新对象，赋予新的id
        if (typeof value.id === 'undefined') {
            // 设置初始值
            var lastInsertId = setting.get('folderLastInsertId'),
                timestamp = util.getTimestamp();
            this.set({
                id: lastInsertId,
                createTimestamp: timestamp,
                modifiedTimestamp: timestamp
            });
            // ID自增量加1
            setting.set('folderLastInsertId', lastInsertId + 1);
        }
    },
    // 插入id
    insertNoteId: function (id) {
        var result = this.get('notes');
        result.push(id);
        this.set({
            notes: result,
            modifiedTimestamp: util.getTimestamp()
        });
        this.save();
        this.trigger('change');
    },
    // 删除id
    removeNoteId: function (id) {
        var result = this.get('notes');
        util.removeArrayValue(result, id);
        this.set({
            notes: result,
            modifiedTimestamp: util.getTimestamp()
        });
        this.save();
        this.trigger('change');
    }
});

return Folder;

});
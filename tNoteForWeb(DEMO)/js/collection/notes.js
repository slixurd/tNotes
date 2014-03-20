// 笔记集合模块
define(['model/Note', 'database/note'], function (Note, database) {

var Notes = Backbone.Collection.extend({
    model: Note,
    database: database,
    storeName: 'notes',
    // localStorage: new Backbone.LocalStorage("Notes"),
    // 根据id号取出相应的Model数组
    getModelsByIds: function (ids) {
        var result = [], i, len;
        for (i = 0, len = ids.length; i < len; i++) {
            result[i] = this.get(ids[i]).toJSON();
        }
        return result;
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
    // 根据id号进行更新
    updateById: function (id, data) {
        var note = this.get(id);
        note.set(data);
        note.save();
    }
});

var notes = new Notes();

notes.fetch();

return notes;

});
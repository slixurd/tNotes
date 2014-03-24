// 笔记集合，返回Note集合类实例

define(['NoteModel', 'noteDb'], function (NoteModel, database) {

var NoteCollection = Backbone.Collection.extend({

    model: NoteModel,
    
    database: database,
    storeName: database.storeName

});

// 创建noteCollection实例并获取数据
var noteCollection = new NoteCollection;
noteCollection.fetch();

return noteCollection;

});
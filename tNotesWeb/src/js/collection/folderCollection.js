// 文件夹集合，返回Folder集合类实例

define(['FolderModel', 'folderDb'], function (FolderModel, database) {

var FolderCollection = Backbone.Collection.extend({

    model: FolderModel,

    database: database,
    storName: database.storeName,

    comparator: function (folder) {
        return -folder.get('modifiedTime'); // 按修改日期排序
    }

});

// 创建folderCollection实例并获取数据
var folderCollection = new FolderCollection;
folderCollection.fetch();

return folderCollection;

});
// 文件夹集合模块
define(['model/Folder', 'database/folder'], function (Folder, database) {

var Folders = Backbone.Collection.extend({
    model: Folder,
    database: database,
    storeName: 'folders',
    // localStorage: new Backbone.LocalStorage("Folders"),
    comparator: function (folder) {
        return -folder.get('modifiedTimestamp'); // 按修改日期排序
    },
    // 删除指定id的文件夹
    deleteById: function (id) {
        this.get(id).destroy();
    },
    // 为指定文件夹插入id
    insertNoteId: function (folderId, id) {
        this.get(folderId).insertNoteId(id);
    },
    // 从指定文件夹中移除指定的笔记id
    removeNote: function (folderId, noteId) {
        var folder = this.get(folderId);
        folder.removeNoteId(noteId);
    }
});

var folders = new Folders();

// 加载本地的数据
folders.fetch();

return folders;

});
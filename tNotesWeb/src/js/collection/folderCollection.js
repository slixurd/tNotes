// 文件夹集合，返回Folder集合类实例

define(['FolderModel', 'folderDb'], function (FolderModel, database) {

var FolderCollection = Backbone.Collection.extend({
    model: FolderModel,

    database: database,
    storeName: database.storeName,

    currentID: 0,
	
	initialize: function(){
	},

    comparator: function (folder) {
        return folder.get('modifiedTime'); // 按修改日期排序
    },

    /* 添加文章 */
    addNote: function(id){
        if(this.currentID != 0)
    	   this.get(this.currentID).addNote(id);
    },

    /* 删除文章 */
    removeNote: function(id){
        if(this.currentID != 0)
           this.get(this.currentID).removeNote(id);
    },

     /* 清空文章 */
    clearNote: function(){
        if(this.currentID != 0)
           this.get(this.currentID).clearNote();
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        if(this.currentID != 0)
           this.get(this.currentID).updateModifiedTime(time);
    }
});

// 创建folderCollection实例并获取数据
var folderCollection = new FolderCollection;

folderCollection.fetch();

return folderCollection;

});
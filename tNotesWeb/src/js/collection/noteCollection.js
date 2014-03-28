// 笔记集合，返回Note集合类实例

define(['NoteModel', 'noteDb', 'setting'], function (NoteModel, database, setting) {

var NoteCollection = Backbone.Collection.extend({

    model: NoteModel,
    
    database: database,
    storeName: database.storeName,
	
	currentFolder: 0,

	//根据Array类型的id序列取出Model数组
	getModelsByIds: function(Ids) {
		var len = Ids.length;
		var models = [], i, len;
		for(i = 0; i < len; i++) {
			models[i] = this.get(Ids[i]).toJSON();
		}
		return models;
	},
	//根据folderId取出Model数组
	getModelsByFolderId: function(folderId) {
		var noteModelList = this.collection.where({folderId: folderId});
		return noteModelList;
	},
	//根据id号删除对应的Model数据
	deleteModelById: function(Id) {
		this.get(Id).destroy();
	},
	//根据Array类型的id序列删除Model数组
	deleteModelsByIds: function(Ids) {
		var len = Ids.length;
		for(i = 0; i < len; i++) {
			deleteModelById(Ids[i]);
		}
	},
	//根据folderId删除Model数组(未完成)
	deleteModelsByFolderId: function(folderId) {
		var noteModelList = getModelsByFolderId(folderId);
		for(var i = 0; i < noteModelList.length; i++) {
			deleteModelById(noteModelList[i].Id);
		}
	},
	//根据id号更新对应的Model数据
	updateModelById: function(id, data) {
		var note = this.get(id);
		note.set(data);
		note.save();
	},
	/**
	  * addedNote将所有add操作写进setting的同步队列
	  * deletedNote：
	  * 当id>0, Note为服务器端的文件，先判断noteUpdatedId[]中是否存在update的操作，若有则删除其字段；再将id加入noteDeletedId[]中;
	  * 当id<0, Note为本地文件，则将noteAddedId[]中的id删除.
	  * updatedNote:
	  * 当id>0, Note为服务器端的文件，先判断noteUpdatedId[]中是否存在update的操作，若有则不用操作；若无则将id加入noteUpdatedId[]中;
	  * 当id<0, Note为本地文件，则add记录将会写在noteAddedId[]中，noteUpdatedId[]中不用写
	  **/
	//记录新建笔记事件
	addedNote: function(id) {
		var noteAddedArray = setting.get('noteAddedId');
		noteAddedArray.push(id);
		setting.set('noteAddedId', noteAddedArray);
	},
	//记录删除笔记事件
	deletedNote: function(id) {
		if( id > 0 ) {
			var noteDeletedArray = setting.get('noteDeletedId');
			var noteUpdatedArray = setting.get('noteUpdatedId');
			var updateNoteLocation = noteUpdatedArray.indexOf(id);
			if( updateNoteLocation >= 0 ) {
				noteUpdatedArray.splice(updateNoteLocation, 1);
			}
			noteDeletedArray.push(id);
			setting.set('noteDeletedId', noteDeletedArray);
			setting.set('noteUpdatedId', noteUpdatedArray);
		} else {
			var noteAddedArray = setting.get('noteAddedId');
			noteAddedArray.splice(noteAddedArray.indexOf(id), 1);
			setting.set('noteAddedId', noteAddedArray);
		}
	},
	//记录修改笔记事件
	updatedNote: function(id) {
		if( id > 0 ) {
			var noteUpdatedArray = setting.get('noteUpdatedId');
			var updateNoteLocation = noteUpdateArray.indexOf(id);
			if( updateNoteLocation < 0 ) {
				noteUpdatedArray.push(id);
				setting.set('noteUpdatedId', noteUpdatedArray);
			}
		}
	}
});

// 创建noteCollection实例并获取数据
var noteCollection = new NoteCollection;
noteCollection.fetch();

return noteCollection;

});
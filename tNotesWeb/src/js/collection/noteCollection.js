// 笔记集合，返回Note集合类实例

define(['NoteModel', 'noteDb', 'setting'], function (NoteModel, database, setting) {

var NoteCollection = Backbone.Collection.extend({

    model: NoteModel,
    
    database: database,
    storeName: database.storeName,
	
	currentFolder: 0,

	//获取当前选中的folderId
	setFolderId: function(folderId) {
		this.currentFolder = folderId;
	},
	
	//将服务器数据存入本地
	storageNote: function(data) {
		var note = this.get(data.id);
		if(typeof(note) === 'undefined') {
			note = this.create({id: data.id, title: data.name, folderId: data.location, brief: data.brief, createTime: data.stamp, modifiedTime: data.stamp});
			note.save();
		} else {
			note.set({title: data.name, folderId: data.location, brief: data.brief, modifiedTime: data.stamp});
			note.save();
		}
	},
	
	//根据选中文件夹id从服务器获取数据
	getNoteListByFolderId: function(folderId) {
		var sessionkey = setting.get('session'); //获取session key
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/fecthbriefs.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + '"' + folderId + '"}'
		}).done(function(data) {
			if(data.length > 0) {
				for(var i = 0; i < data.length; i++) {
					this.collection.storageNote(data[i]);
				}
			}
		}).fail(function(){
		}).always();
	},
	
	//根据选中笔记id从服务器获取数据
	getNoteByNoteId: function(id) {
		var sessionkey = setting.get('session'); //获取session key
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/fectharticles.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + '"' + id + '"}'
		}).done(function(data) {
			if(data.id) {
				this.get(id).set({id: data.id, folderId: data.location, title: data.name, content: data.content, modifiedTime: data.stamp});
			}
		}).fail(function() {
		}).always();
	},
	
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
		var noteModelList = this.where({folderId: folderId});
		return noteModelList;
	},
	
	//根据id号删除对应的Model数据
	deleteModelById: function(id) {
		this.get(id).destroy();
	},
	
	//根据Array类型的id序列删除Model数组
	deleteModelsByIds: function(Ids) {
		var len = Ids.length;
		for(i = 0; i < len; i++) {
			deleteModelById(Ids[i]);
		}
	},
	
	//根据folderId删除Model数组
	deleteModelsByFolderId: function(folderId) {
		var noteModelList = getModelsByFolderId(folderId);
		for(var i = 0; i < noteModelList.length; i++) {
			deleteModelById(noteModelList[i].Id);
		}
	},
	
	//根据id号更新对应的Model数据
	updateModelById: function(id, title, content) {
		var note = this.get(id);
		note.set({title: title, content: content});
		note.save();
	},
	
	//新建笔记
	newNote: function(title, content) {
		//需获取folderId
		var currentNote = this.create({folderId: this.currentFolder, title: title, content: content});
		currentNote.save();
		this.newNotePost(currentNote);
	},
	
	//删除笔记
	deleteNote: function(id) {
		this.deleteModelById(id);
		this.deleteNotePost(id);
	},
	
	//更新笔记
	updateNote: function(id, title, content) {
		updateModelById(id, title, content);
		updateNotePost(id, title, content);
	},
	
	//新建笔记并post 若失败则写入setting中的同步列表
	newNotePost: function(newNote) {
		var sessionkey = setting.get('session'); //获取session key
		var id = newNote.get('id');              //获取需要新建的笔记id
		var name = newNote.get('title');         //获取需要新建的笔记标题
		var content = newNote.get('content');    //获取需要新建的笔记内容
		var location = newNote.get('folderId');  //获取需要新建的笔记所在文件夹
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/createarticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"name":' + '"' + title + '",' + '"content":' + '"' + content + '",' + '"location":' + '"' + location + '"' + '}'
		}).done(function(data){
			if(data.id && data.stamp) {
				this.get(id).set({id: data.id, modifiedTime: data.stamp}); //POST成功则更新indexDB中的笔记id和modifiedTime
			}
			else if(data.exception='Article Handling Failure') {
				this.addedNoteSetting(id);  //POST失败则将新建笔记事件写入setting的noteAddedArray中
			}
		}).fail(function(){
		
		}).always();
	},
	
	//删除笔记并post 若失败则写入setting中的同步列表
	deleteNotePost: function(id) {
		var sessionkey = setting.get('session');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/deletearticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + '"' + id + '"}'
		}).done(function(data) {
			if(data.status) {
			}
			else if(data.exception = 'Article Handling Failure') {
				this.deletedNoteSetting(id);
			}
		}).fail(function() {
		}).always();
	},
	
	//更新笔记并post 若失败则写入setting中的同步列表
	updateNotePost: function(id, name, content) {
		var sessionkey = setting.get('session');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/changearticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + '"' + id + '",' + '"name":' + '"' + name + '",' + '"content":' + content + '"}'
		}).done(function(data) {
			if(data.stamp) {
				this.get(id).set({modifiedTime: data.stamp});
			}
			else if(data.exception = 'Article Handling Failure') {
				this.updatedNoteSetting(id);
			}
		}).fail(function() {
		}).always();
	},
	/**
	  * addedNoteSetting将所有add操作写进setting的同步队列
	  * deletedNoteSetting：
	  * 当id>0, Note为服务器端的文件，先判断noteUpdatedId[]中是否存在update的操作，若有则删除其字段；再将id加入noteDeletedId[]中;
	  * 当id<0, Note为本地文件，则将noteAddedId[]中的id删除.
	  * updatedNoteSetting:
	  * 当id>0, Note为服务器端的文件，先判断noteUpdatedId[]中是否存在update的操作，若有则不用操作；若无则将id加入noteUpdatedId[]中;
	  * 当id<0, Note为本地文件，则add记录将会写在noteAddedId[]中，noteUpdatedId[]中不用写
	  **/
	//记录新建笔记事件
	addedNoteSetting: function(id) {
		var noteAddedArray = setting.get('noteAddedId');
		noteAddedArray.push(id);
		setting.set('noteAddedId', noteAddedArray);
	},
	
	//记录删除笔记事件
	deletedNoteSetting: function(id) {
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
	updatedNoteSetting: function(id) {
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
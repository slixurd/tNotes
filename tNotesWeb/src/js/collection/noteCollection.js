// 笔记集合，返回Note集合类实例

define(['NoteModel', 'noteDb', 'setting', 'folderCollection'], function (NoteModel, database, setting, folderCollection) {

var NoteCollection = Backbone.Collection.extend({

    model: NoteModel,
    
    database: database,
    storeName: database.storeName,
	
	currentFolder: 0,
	
	initialize: function() {
	},
	
	//按修改时间modifiedTime进行排序
	/*
	comparator: function (note) {
		return note.get('modifiedTime');
	},
	*/
	//获取当前选中的folderId
	setFolderId: function(folderId) {
		this.currentFolder = folderId;
	},
	
	//将服务器数据存入本地
	storageNote: function(data) {
		this.create({
			id: data.id, 
			title: data.name, 
			folderId: data.location, 
			brief: data.brief, 
			createTime: data.stamp * 1000, 
			modifiedTime: data.stamp * 1000
		}, {wait: true});
	},
	
	//根据选中文件夹id从服务器获取数据
	getNoteListByFolderId: function() {
		var self = this;
		var sessionkey = setting.get('session'); //获取session key
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/fetchbriefs.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + this.currentFolder + '}'
		}).done(function(data) {
			if(data.article != null) {
				console.log(data);
				for(var i = 0; i < data.article.length; i++) {
					self.storageNote(data.article[i]);
					folderCollection.addNote(data.article[i].id);
				}
			} else {
				console.log('data is null');
			}
		}).fail(function(){
		}).always();
	},
	
	//根据选中笔记id从服务器获取数据
	getNoteByNoteId: function(id) {
		var self = this;
		var sessionkey = setting.get('session'); //获取session key
		var brief = self.get(id).get('brief');
		console.log('brief is ' + brief);
		console.log('Collection get id: ' + id);
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/fetcharticles.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":[' + id + ']}'
		}).done(function(data) {
			console.log(data);
			if(data.article == null) {
				console.log('note data is null');
			} else {
				console.log('brief is ' + brief);
				console.log('content is ' + data.article[0].content);
				console.log('pre id is ' + data.article[0].id);
				self.create({
					id: data.article[0].id,
					folderId: data.article[0].location,
					brief: brief,
					title: data.article[0].name,
					content: data.article[0].content,
					modifiedTime: data.article[0].stamp * 1000
				}, {wait: true});
				
			}
		}).fail(function() {
			console.log('post failed!');
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
		var list = this.toJSON();
		for(var i=0; i < list.length; i++) {
			if(list[i].folderId != folderId) {
				list.splice(i, 1);
				i--;
			}
		}
		return list;
	},
	
	//根据id号删除对应的Model数据
	deleteModelById: function(id) {
		var note = this.get(id);
		if (typeof(note) != 'undefined') {
			this.get(id).destroy();
			console.log('delete note success');
		} else {
			console.log('delete info: failed');
		}
		
		
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
	newNote: function(folderId, title, content) {
		var currentNote = this.create({
			folderId: folderId,
			title: title, 
			content: content
		});
		var newNoteId = currentNote.attributes.id;
		if(this.currentFolder > 0) {
			newNoteId = this.newNotePost(currentNote.attributes);
		} else {
			this.addedNoteSetting(currentNote.attributes.id);
			folderCollection.addNote(currentNote.attributes.id);
		}
		return newNoteId;
	},
	
	//删除笔记
	deleteNote: function(id) {
		this.deleteModelById(id);
		folderCollection.removeNote(id);
		if(id > 0) {
			this.deleteNotePost(id);
		} else {
			this.deletedNoteSetting(id);
		}
	},
	
	//更新笔记
	updateNote: function(id, title, content) {
		this.updateModelById(id, title, content); //写本地
		if(id > 0) {                              //当id大于0，则要执行post
			this.updateNotePost(id, title, content);
		}
	},
	
	//新建笔记并post 若失败则写入setting中的同步列表
	newNotePost: function(newNote) {
		var self = this;
		var sessionkey = setting.get('session'); //获取session key
		var id = newNote.id;              //获取需要新建的笔记id
		console.log(id);
		var name = newNote.title;         //获取需要新建的笔记标题
		var content = newNote.content;    //获取需要新建的笔记内容
		var location = newNote.folderId;  //获取需要新建的笔记所在文件夹
		console.log(newNote);
		console.log('Begin newNotePost');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/createarticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"name":' + '"' + name + '",' + '"content":' + '"' + content + '",' + '"location":' + location + '}'
		}).done(function(data){
			console.log(data);
			if(data.id && data.stamp) {
				console.log('success upload');
				self.create({                                  //POST成功则更新indexDB中的笔记id和modifiedTime
					id: data.id,
					folderId: self.get(id).get('folderId'),
					title: self.get(id).get('title'),
					content: self.get(id).get('content'),
					createTime: self.get(id).get('createTime'),
					modifiedTime: data.stamp * 1000
				}, {wait: true});
				self.get(id).destroy();
				folderCollection.addNote(data.id);
				return data.id;
			} else if(data.exception == 'Session Failure') {
				//session过期，需要重新登录
				self.addedNoteSetting(id);  //POST失败则将新建笔记事件写入setting的noteAddedArray中
				folderCollection.addNote(id);
				return id;
			} else if(data.exception == 'Article Handling Failure') {
				self.addedNoteSetting(id);  //POST失败则将新建笔记事件写入setting的noteAddedArray中
				folderCollection.addNote(id);
				return id;
			} else {
				self.addedNoteSetting(id);  //POST失败则将新建笔记事件写入setting的noteAddedArray中
				folderCollection.addNote(id);
				return id;
			}
		}).fail(function(){
			self.addedNoteSetting(id);  //POST失败则将新建笔记事件写入setting的noteAddedArray中
			folderCollection.addNote(id);
			return id;
		}).always();
	},
	
	//删除笔记并post 若失败则写入setting中的同步列表
	deleteNotePost: function(id) {
		var self = this;
		var sessionkey = setting.get('session');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/deletearticle.cgi',
			type: 'POST',
			data: '{"session":"' + setting.get('session') + '","id":' + id + '}'
		}).done(function(data) {
			console.log(data);
			if(data.status == 'success') {
				//若成功则需要在noteUpdatedId中删除该id
				var noteUpdateArray = setting.get('noteUpdatedId');
				var updateNoteLocation = noteUpdateArray.indexOf(id);
				if(updateNoteLocation >= 0) {
					noteUpdateArray.splice(updateNoteLocation, 1);
				}
				setting.set('noteUpdatedId', noteUpdateArray);
				setting.save();
			}
			else if(data.exception = 'Article Handling Failure') {
				self.deletedNoteSetting(id);
			}
		}).fail(function() {
			self.deletedNoteSetting(id);
		}).always();
	},
	
	//更新笔记并post 若失败则写入setting中的同步列表
	updateNotePost: function(id, name, content) {
		var self = this;
		var sessionkey = setting.get('session');
		console.log('Begin updateNotePost');
		console.log('{"session":' + '"' + sessionkey + '",' + '"id":' + id + ',' + '"name":' + '"' + name + '",' + '"content":"' + content + '"}');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/changearticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + sessionkey + '",' + '"id":' + id + ',' + '"name":' + '"' + name + '",' + '"content":"' + content + '"}'
		}).done(function(data) {
			console.log(data);
			if(data.stamp) {
				self.get(id).save({
					modifiedTime: data.stamp * 1000
				});
			} else if(data.exception = 'Article Handling Failure') {
				console.log('Exception: Article Handling Failure');
				self.updatedNoteSetting(id);
			} else {
				console.log('post failed');
				self.updatedNoteSetting(id);
			}
		}).fail(function() {
			console.log('Post failed');
			self.updatedNoteSetting(id);
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
		console.log(noteAddedArray);
		setting.set('noteAddedId', noteAddedArray);
		setting.save();
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
			setting.save();
		}
		setting.save();
	},
	
	//记录修改笔记事件
	updatedNoteSetting: function(id) {
		if( id > 0 ) {
			var noteUpdatedArray = setting.get('noteUpdatedId');
			var updateNoteLocation = noteUpdatedArray.indexOf(id);
			if( updateNoteLocation < 0 ) {
				noteUpdatedArray.push(id);
				setting.set('noteUpdatedId', noteUpdatedArray);
				setting.save();
			}
		}
	}
	
});

// 创建noteCollection实例并获取数据
var noteCollection = new NoteCollection;
noteCollection.fetch();

return noteCollection;

});
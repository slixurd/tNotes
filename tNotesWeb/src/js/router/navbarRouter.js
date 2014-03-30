// navBar路由模块-1396006789626,-1396008090707,-1396008112146

define(['hint', 'navbarView', 'folderCollection', 'noteCollection', 'setting'], function(hintView, navbarView, folderCollection, noteCollection, setting) {


	var index = 0;
	var count = 0;
	var session = setting.get('session');
	var noteDeletedId = setting.get('noteDeletedId');
	var folderDeletedId = setting.get('folderDeletedId');
	var noteAddedId = setting.get('noteAddedId');
	var folderAddedId = setting.get('folderAddedId');
	var noteUpdatedID = setting.get('noteUpdatedID');
	var folerUpdatedID = setting.get('folerUpdatedID');
	var folderidlength = folderAddedId.length;
	var noteidlength = noteAddedId.length;
	var noteupdatelength = noteUpdatedID.length;
	var folderupdatelength = folerUpdatedID.length;
	var notedeletelength = noteDeletedId.length;
	var folderdeletelength = folderDeletedId.length;

//新建文件夹同步
	function newFolder(nodename, session) {
		var arr = setting.get('folderAddedId')
		console.log(arr);
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/createnode.cgi',
			type: 'POST',
			data: '{"session":' + '"' + session + '",' + '"name":' + '"' + nodename + '"}'
		}).done(function(data) {
			console.log(data);
			if (data.id && data.stamp) {
				console.log('post成功');
				//post成功
				folderCollection.get(arr[index]).set({
					"id": data.id,
					"modifiedTime": data.stamp
				});
				for (var i = 0; i < noteCollection.length; i++) {
					if (noteCollection.get(i).get("folderId") == arr[index]) {
						noteCollection.get(i).set({
							"folderId": data.id
						});
					}

					arr.splice(index, 1);
					console.log(index);
					count++;
					console.log(count);
					index--;
					setting.set({
						"folderAddedId": arr
					});
					setting.save();
					console.log(setting.get('folderAddedId'));

				}

			} else if (data.exception == 'Node Handling Failure') {
				//处理失败
				console.log('处理失败');
			} else if (data.exception == 'Session Failure') {
				//session过期，需要重新登录
				navbarView.showLoginModal();
				console.log('session过期，需要重新登录');
			} else {
				//其他错误
			}
		}).fail(function() {
			console.log('由于网络离线或者其他原因导致请求失败了');
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == folderidlength) {
				folderCollection.fetchFolder();

				//调用同步note的函数
				console.log('newFolder执行完毕');
				index = 0;
				count = 0;
				if (noteidlength != 0)
					newNote(noteCollection.get(0).get("name"), noteCollection.get(0).get("content"), noteCollection.get(0).get("folderId"));


			} else {
				index = index + 1;
				console.log(folderCollection.get(arr[index]).get('name'));
				newFolder(folderCollection.get(arr[index]).get('name'), session);
			}
		});
	};

	//新建笔记同步

	function newNote(notename, content, location) {
		var arr = setting.get("noteAddedId");
		console.log(arr);
		$.ajax({

			url: 'http://tnotes.wicp.net:8080/createarticle.cgi',
			type: 'POST',
			data: '{"session":"' + session + '","name":"' + notename + '","content":"' + content + '","location":' + location + '}'

		}).done(function(data) {
			console.log(data);
			if (data.id && data.stamp) {
				console.log("post成功");
				//post成功
				noteCollection.get(arr[index]).set({
					"id": data.id,
					"modifiedTime": data.stamp
				});
				arr.splice(index, 1);
				count++;
				index--;
				setting.set({
					"noteAddedId": arr
				});
				setting.save();
			} else if (data.exception == 'Node Handling Failure') {
				//处理失败
			} else if (data.exception == 'Session Failure') {
				console.log("session过期，需要重新登录");
				//session过期，需要重新登录
			} else {
				//其他错误
			}
		}).fail(function() {
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == noteidlength) {
				index = 0;
				count = 0;
				//笔记新建同步完成，可以调用其他函数了
			} else {
				index = index + 1;
				console.log(noteCollection.get(arr[index]).get('name'));
				newNote(noteCollection.get(arr[index]).get('name'), noteCollection.get(arr[index]).get('content'), noteCollection.get(arr[index]).get('folderId'));
			}

		});

	};

	//更新笔记同步

	function updateNote(notename, content, noteid) {
		var arr = setting('noteUpdatedID');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/changearticle.cgi',
			type: 'POST',
			data: '{"session":"' + session + '","name":"' + notename + '","content":"' + content + '","id":' + noteid + '}'
		}).done(function(data) {
			console.log(data);
			if (data.stamp) {
				console.log('post成功');
				//post成功
				noteCollection.get(arr[index]).set({
					"modifiedTime": data.stamp
				});
				arr.splice(index, 1);
				count++;
				index--;
				setting.set({
					"noteUpdatedID": arr
				});
				setting.save();
			} else if (data.exception == 'Node Handling Failure') {
				console.log('处理失败');
				//处理失败
			} else if (data.exception == 'Session Failure') {
				navbarView.showLoginModal();
				//session过期，需要重新登录
			} else {
				//其他错误
			}
		}).fail(function() {
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == noteupdatelength) {
				index = 0;
				count = 0;
				//笔记新建同步完成，可以调用其他函数了
			} else {
				index = index + 1;
				console.log(noteCollection.get(arr[index]).get('name'));
				updateNote(noteCollection.get(arr[index]).get('name'), noteCollection.get(arr[index]).get('content'), noteCollection.get(arr[index]).get('id'));
			}
		});
	};

	//更新文件夹同步

	function updateFolder(folderid, newfoldername) {
		var arr = setting.get('folerUpdatedID');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/changenode.cgi',
			type: 'POST',
			data: '{"session":' + '"' + session + '",' + '"id":' + folderid + ',' + '"name":' + '"' + newfoldername + '"' + '}'
		}).done(function(data) {
			console.log(data);
			if (data.stamp) {
				//post成功
				folderCollection.get(arr[index]).set({
					"modifiedTime": data.stamp
				});
				arr.splice(index, 1);
				count++;
				index--;
				setting.set({
					"folerUpdatedID": arr
				});
				setting.save();
			} else if (data.exception = 'Node Handling Failure') {
				//处理失败
			} else if (data.exception = 'Session Failure') {
				//session过期，需要重新登录
			} else {
				//其他错误
			}
		}).fail(function() {
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == folderupdatelength) {
				index = 0;
				count = 0;
				//笔记新建同步完成，可以调用其他函数了
			} else {
				index = index + 1;
				console.log(folderCollection.get(arr[index]).get('name'));
				updateFolder(folderCollection.get(arr[index]).get('id'), folderCollection.get(arr[index]).get('name'));
			}
		});
	};

	//删除一个note

	function deleteNote(noteid) {
		var arr = setting.get('noteDeletedId');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/deletearticle.cgi',
			type: 'POST',
			data: '{"session":' + '"' + session + '",' + '"id":' + noteid + '}'
		}).done(function(data) {
			console.log(data);
			if (data.status == 'success') {
				console.log('笔记删除成功');
				//post成功
				arr.splice(index, 1);
				count++;
				index--;
				setting.set({
					"noteDeletedId": arr
				});
				setting.save();
			} else if (data.exception == 'Node Handling Failure') {
				console.log('处理失败');
				//处理失败
			} else if (data.exception == 'Session Failure') {
				console.log('session过期，需要重新登录');
				//session过期，需要重新登录
			} else {
				//其他错误
			}
		}).fail(function() {
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == notedeletelength) {
				index = 0;
				count = 0;
				//笔记新建同步完成，可以调用其他函数了
			} else {
				index = index + 1;
				console.log(noteCollection.get(arr[index]).get('name'));
				deleteNote(noteCollection.get(arr[index]).get('id'));
			}
		});
	};

	//删除一个文件夹

	function deleteFolder(folderid) {
		var arr = setting.get('folderDeletedId');
		$.ajax({
			url: 'http://tnotes.wicp.net:8080/deletenode.cgi',
			type: 'POST',
			data: '{"session":' + '"' + session + '",' + '"id":' + folderid + '}'
		}).done(function(data) {
			console.log(data);
			if (data.status == 'success') {
				console.log('post成功');
				//post成功
				arr.splice(index, 1);
				count++;
				index--;
				setting.set({
					"folderDeletedId": arr
				});
				setting.save();
			} else if (data.exception == 'Node Handling Failure') {
				console.log('处理失败');
				//处理失败
			} else if (data.exception == 'Session Failure') {
				navbarView.showLoginModal();
				//session过期，需要重新登录
			} else {
				//其他错误
			}
		}).fail(function() {
			//由于网络离线或者其他原因导致请求失败了
		}).always(function() {
			if (count == folderdeletelength) {
				index = 0;
				count = 0;
				//笔记新建同步完成，可以调用其他函数了
			} else {
				index = index + 1;
				console.log(folderCollection.get(arr[index]).get('name'));
				deleteFolder(folderCollection.get(arr[index]).get('id'));
			}
		});
	};

	var Router = Backbone.Router.extend({

		routes: {
			'synchro': 'synchro',
			'search': 'searchNote'
		},

		//同步函数
		synchro: function() {
			index = 0;

			if (session != '') {
				if (navigator.onLine) {
					console.log("当前在线");
					console.log("同步开始");
					if (folderAddedId.length)
						newFolder(folderCollection.get(folderAddedId[index]).get('name'), session);
					else if (noteidlength) {
						newNote(noteCollection.get(noteAddedId[index]).get('name'), noteCollection.get(noteAddedId[index]).get('content'), noteCollection.get(noteAddedId[index]).get('folderId'));
					}
					if (folderupdatelength) {
						updateFolder(folderCollection.get(folerUpdatedID[index]).get('id'), folderCollection.get(folerUpdatedID[index]).get('name'));
					}
					if (noteupdatelength) {
						updateNote(noteCollection.get(noteUpdatedID[index]).get('name'), noteCollection.get(noteUpdatedID[index]).get('content'), noteCollection.get(noteUpdatedID[index]).get('id'));
					}
					if (folderdeletelength) {
						console.log("folderdeletelength"+folderdeletelength);
						deleteFolder(folderCollection.get(folderDeletedId[index]).get('id'));
					}
					if (notedeletelength) {
						deleteNote(noteCollection.get(noteDeletedId[index]).get('id'));
					}

				} else {
					console.log("当前离线");
				}

			} else {
				$("#loginModal h4").html("请先登录！");
				navbarView.showLoginModal();
			}
		},

		//新建folder



		//获取搜索结果并更新笔记列表视图
		searchNote: function() {
			console.log("点击了搜索");
			console.log(navbarView.$searchContent.val());

		}

	});

	var router = new Router;

	return router;

});
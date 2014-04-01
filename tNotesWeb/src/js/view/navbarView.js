define(["setting", "hint", 'noteCollection', "folderCollection", "contentViewer"], function(setting, hintview, noteCollection, folderCollection, contentViewer) {
	function tongbu(session, noteDeletedId, folderDeletedId, noteAddedId, folderAddedId, noteUpdatedId, folderUpdatedId, folderidlength, noteidlength, noteupdatelength, folderupdatelength, notedeletelength, folderdeletelength) {
		//var obj = new Object();
		var index = 0;
		var count = 0;
		var session = session;
		var noteDeletedId = noteDeletedId;
		var folderDeletedId = folderDeletedId;
		var noteAddedId = noteAddedId;
		var folderAddedId = folderAddedId;
		var noteUpdatedId = noteUpdatedId;
		var folderUpdatedId = folderUpdatedId;
		var folderidlength = folderidlength;
		var noteidlength = noteidlength;
		var noteupdatelength = noteupdatelength;
		var folderupdatelength = folderupdatelength;
		var notedeletelength = notedeletelength
		var folderdeletelength = folderdeletelength;

		//新建文件夹同步


		this.newFolder = function(nodename, session, newFolder) {
			var arr = setting.get('folderAddedId');
			console.log(arr);
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/createnode.cgi',
				type: 'POST',
				data: '{"session":' + '"' + setting.get('session') + '",' + '"name":' + '"' + nodename + '"}'
			}).done(function(data) {
				console.log(data);
				if (data.id && data.stamp) {
					console.log('post成功');
					console.log(index);
					console.log(arr[index]);
					folderCollection.create({
						id: data.id,
						name: folderCollection.get(arr[index]).get('name'),
						notes: folderCollection.get(arr[index]).get('notes'), // 笔记
						createTime: folderCollection.get(arr[index]).get('createTime'), // 创建时间
						modifiedTime: data.stamp * 1000
					})
					folderCollection.get(arr[index]).destroy();

					noteCollection.each(function(note) {
						if (note.get("folderId") == arr[index]) {
							note.save({
								"folderId": data.id
							});
						}
					});


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



				} else if (data.exception == 'Node Handling Failure') {
					//处理失败
					console.log('处理失败');
				} else if (data.exception == 'Session Failure') {
					//session过期，需要重新登录

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

					this.newNote = function(notename, content, location, newNote) {
						var arr = setting.get("noteAddedId");
						console.log(arr);
						$.ajax({

							url: 'http://tnotes.wicp.net:8080/createarticle.cgi',
							type: 'POST',
							data: '{"session":"' + setting.get('session') + '","name":"' + notename + '","content":"' + content + '","location":' + location + '}'

						}).done(function(data) {
							console.log(data);
							if (data.id && data.stamp) {
								console.log("post成功");
								//post成功
								// noteCollection.get(arr[index]).set({
								// 	"id": data.id,
								// 	"modifiedTime": data.stamp
								// });

								noteCollection.create({
									id: data.id,
									folderId: noteCollection.get(arr[index]).get('folderId'),
									title: noteCollection.get(arr[index]).get('title'),
									content: noteCollection.get(arr[index]).get('content'), // 笔记
									createTime: noteCollection.get(arr[index]).get('createTime'), // 创建时间
									modifiedTime: data.stamp * 1000
								})
								noteCollection.get(arr[index]).destroy();
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
								newNote(noteCollection.get(arr[index]).get('name'), noteCollection.get(arr[index]).get('content'), noteCollection.get(arr[index]).get('folderId'), newNote);
							}

						});

					};
					if (noteidlength != 0)
						this.newNote(noteCollection.get(setting.get('noteAddedId')[0]).get("name"), noteCollection.get(setting.get('noteAddedId')[0]).get("content"), noteCollection.get(setting.get('noteAddedId')[0]).get("folderId"), this.newNote);


				} else {
					console.log(typeof newFolder);


					index = index + 1;

					newFolder(folderCollection.get(arr[index]).get('name'), setting.get('session'), newFolder);
				}
			});
		};



		//新建笔记同步


		this.newNote = function(notename, content, location, newNote) {
			var arr = setting.get("noteAddedId");
			console.log(arr);
			$.ajax({

				url: 'http://tnotes.wicp.net:8080/createarticle.cgi',
				type: 'POST',
				data: '{"session":"' + setting.get('session') + '","name":"' + notename + '","content":"' + content + '","location":' + location + '}'

			}).done(function(data) {
				console.log(data);
				if (data.id && data.stamp) {
					console.log("post成功");
					//post成功
					// noteCollection.get(arr[index]).set({
					// 	"id": data.id,
					// 	"modifiedTime": data.stamp
					// });

					noteCollection.create({
						id: data.id,
						folderId: noteCollection.get(arr[index]).get('folderId'),
						title: noteCollection.get(arr[index]).get('name'),
						content: noteCollection.get(arr[index]).get('content'), // 笔记
						createTime: noteCollection.get(arr[index]).get('createTime'), // 创建时间
						modifiedTime: data.stamp * 1000
					})
					noteCollection.get(arr[index]).destroy();
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
					console.log(noteCollection.get(arr[index]).get('title'));
					newNote(noteCollection.get(arr[index]).get('title'), noteCollection.get(arr[index]).get('content'), noteCollection.get(arr[index]).get('folderId'), newNote);
				}

			});

		};



		//更新笔记同步

		this.updateNote = function(notename, content, noteid,updateNote) {
			var arr = setting.get('noteUpdatedId');
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/changearticle.cgi',
				type: 'POST',
				data: '{"session":"' + setting.get('session') + '","name":"' + notename + '","content":"' + content + '","id":' + noteid + '}'
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
					this.showLoginModal();
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
					updateNote(noteCollection.get(arr[index]).get('name'), noteCollection.get(arr[index]).get('content'), noteCollection.get(arr[index]).get('id'), updateNote);
				}
			});
		};




		//更新文件夹同步

		this.updateFolder = function(folderid, newfoldername, updateFolder) {
			var arr = setting.get('folderUpdatedId');
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/changenode.cgi',
				type: 'POST',
				data: '{"session":' + '"' + setting.get('session') + '",' + '"id":' + folderid + ',' + '"name":' + '"' + newfoldername + '"' + '}'
			}).done(function(data) {
				console.log(data);
				if (data.stamp) {
					//post成功
					console.log(arr[index]);
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
					updateFolder(folderCollection.get(arr[index]).get('id'), folderCollection.get(arr[index]).get('name'), updateFolder);
				}
			});
		};




		//删除一个note

		this.deleteNote = function(noteid, deleteNote) {
			var arr = setting.get('noteDeletedId');
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/deletearticle.cgi',
				type: 'POST',
				data: '{"session":' + '"' + setting.get('session') + '",' + '"id":' + noteid + '}'
			}).done(function(data) {
				console.log('{"session":' + '"' + setting.get('session') + '",' + '"id":' + noteid + '}');
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
					//笔记删除同步完成，可以调用其他函数了
					console.log("笔记删除同步完成");
				} else {
					index = index + 1;
					deleteNote(arr[index], deleteNote);
				}
			});
		};




		//删除一个文件夹
		this.deleteFolder = function(folderid, deleteFolder) {
			var arr = setting.get('folderDeletedId');
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/deletenode.cgi',
				type: 'POST',
				data: '{"session":' + '"' + setting.get('session') + '",' + '"id":' + folderid + '}'
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
					this.showLoginModal();
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

					deleteFolder(arr[index], deleteFolder);
				}
			});



		};



	};
	NavBar = Backbone.View.extend({
		el: $("#navbar"),
		$loginModal: $("#loginModal"),
		$login: $("#login"),
		$regist: $("#regist"),
		$logout: $("#logout"),
		$rememberme: $("#rememberme"),
		$loginUsername: $("#login_username"),
		$loginPassword: $("#login_password"),
		$registUsername: $("#regist_username"),
		$registPassword: $("#regist_password"),
		$searchContent: $("#searchContent"),
		initialize: function() {

			//页面开启时尝试自动登录
			this.autoLogin();
			//登录后自动尝试同步
			this.startSynchro();
			//读取全局样式
			var globalStyle = setting.get('globalStyle');
			this.changeGlobalStyleByNmae(globalStyle);


		},
		events: {
			'click #synchro': 'startSynchro',
			'click #loginButton': 'manuallyLogin',
			'click #logout': 'logout',
			'click .change-Allstyle': 'changeGlobalStyle',
			'click #registButton': 'regist'
		},

		//检测特殊字符
		checkSpecialWord: function(str) {
			re = /insert|select|update|delete|exec|count|'|"|=|;|>|<|%/i;
			if (re.test(str)) {
				return true;
			} else return false;
		},


		//post登录信息,登录成功则保存session到本地，否则提示错误信息http://tnotes.wicp.net:8080/signin.cgi
		postLogin: function(username, password) {
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/signin.cgi',
				type: 'POST',
				data: '{"user":' + '"' + username + '",' + '"pass":' + '"' + password + '"}',
			})
				.done(function(data) {
					var dataInfoJson = data;
					//登录成功，保存登录session
					if (dataInfoJson.status == 'success') {
						setting.set({
							session: dataInfoJson.session
						});

						if ($("#rememberme").prop("checked")) {
							//貌似jquery2.1.0只能用prop('checked')返回true or false，不能用attr('checked')   
							setting.set({
								lastUsername: username,
								lastPassword: password
							});
						}
						$("#login").hide();
						$("#logout").show();
						$("#regist").hide();
						$("#hint").removeClass('alert-danger');
						$("#hint").addClass('alert-success');
						$("#hint h4").html("恭喜");
						hintview.setContent("登录成功！").show();
						console.log('你的用户名：' + username);
						$("#currentUser").html(username);
						folderCollection.fetchFolder();

					} else {
						$("#hint h4").html("抱歉");
						$("#hint").removeClass('alert-success');
						if (dataInfoJson.status == 'incorrect_password') {
							hintview.setContent("登录密码错误！").show();
						} else {
							hintview.setContent("服务器出错！").show();
						}
					}
				})
				.fail(function() {
					hintview.setContent("登录请求失败！").show();
					$("#login").show();
				})
				.always(function() {
					console.log("complete");
				});

		},



		//判断是否可以自动登录
		checkAutoLogin: function(username, password) {
			if (username == '' && password == '') {
				return false;
			} else {
				return true;

			}
		},

		//显示登录modal
		showLoginModal: function() {
			this.$login.click();
		},

		//如果可以则自动登录，自动登录并隐藏登录按钮，否则隐藏退出按钮，
		autoLogin: function() {
			console.log('asdf');
			var lastUsername = setting.get('lastUsername');
			var lastPassword = setting.get('lastPassword');
			if (this.checkAutoLogin(lastUsername, lastPassword)) {
				if (this.checkSpecialWord(lastUsername, lastPassword)) {
					$("#hint h4").html("抱歉");
					hintview.setContent('用户名或者密码不能包含特殊字符！').show();
				} else {
					this.postLogin(lastUsername, lastPassword);
					this.$login.hide();
				}
			} else {
				console.log("不可以自动登录");
				this.$logout.hide();
			}
		},

		//手动登录
		manuallyLogin: function() {
			//console.log('asdf');
			var username = this.$loginUsername.val();
			var password = this.$loginPassword.val();
			$("#hint").removeClass('alert-success');
			$("#hint").addClass('alert-danger');
			$("#hint h4").html("抱歉");
			if (username == '' || password == '') {

				hintview.setContent('用户名或者密码不能为空！').show();
			} else if (this.checkSpecialWord(username, password)) {
				hintview.setContent('用户名或者密码不能包含特殊字符！').show();

			} else
				this.postLogin(username, password);

		},

		//注册POST
		registPost: function(username, password) {

			$.ajax({
				url: 'http://tnotes.wicp.net:8080/signup.cgi',
				type: 'POST',
				data: '{"user":' + '"' + username + '",' + '"pass":' + '"' + password + '"}'

			}).done(function(data) {
				if (data.status == 'success') {
					$("#regist").hide();
					$("#hint").removeClass('alert-danger');
					$("#hint").addClass('alert-success');
					$("#hint h4").html("恭喜");
					hintview.setContent("注册成功！").show();
				} else if (data.status == 'used_username') {
					$("#hint h4").html("抱歉");
					$("#hint").removeClass('alert-success');
					hintview.setContent("用户名已经被占用").show();
				}
			}).fail(function() {
				$("#hint h4").html("抱歉");
				$("#hint").removeClass('alert-success');
				hintview.setContent("注册请求失败").show();
			}).always(function() {
				console.log('complete');
			});
		},

		//注册
		regist: function() {
			var username = this.$registUsername.val();
			var password = this.$registPassword.val();
			$("#hint").removeClass('alert-success');
			$("#hint").addClass('alert-danger');
			$("#hint h4").html("抱歉");

			if (!this.checkSpecialWord(username, password)) {
				if (!(username == '' || password == ''))
					this.registPost(username, password);
				else {
					hintview.setContent('用户名或者密码不能为空！').show();
				}

			} else {
				hintview.setContent('用户名或者密码不能包含特殊字符！').show();

			}



		},

		//同步函数
		startSynchro: function() {
			var index = 0;
			var count = 0;
			var session = setting.get('session');
			var noteDeletedId = setting.get('noteDeletedId');
			var folderDeletedId = setting.get('folderDeletedId');
			var noteAddedId = setting.get('noteAddedId');
			var folderAddedId = setting.get('folderAddedId');
			var noteUpdatedId = setting.get('noteUpdatedId');
			var folderUpdatedId = setting.get('folderUpdatedId');
			var folderidlength = folderAddedId.length;
			var noteidlength = noteAddedId.length;
			var noteupdatelength = noteUpdatedId.length;
			var folderupdatelength = folderUpdatedId.length;
			var notedeletelength = noteDeletedId.length;
			var folderdeletelength = folderDeletedId.length;
			var tongbuObj = new tongbu(session, noteDeletedId, folderDeletedId, noteAddedId, folderAddedId, noteUpdatedId, folderUpdatedId, folderidlength, noteidlength, noteupdatelength, folderupdatelength, notedeletelength, folderdeletelength);
			console.log("........");
			console.log(tongbuObj);
			index = 0;

			if (setting.get('session') != "") {
				if (navigator.onLine) {
					console.log("当前在线");
					console.log("同步开始");
					if (setting.get('folderAddedId').length) {
						console.log(folderCollection.get(setting.get('folderAddedId')[0]));
						tongbuObj.newFolder(folderCollection.get(setting.get('folderAddedId')[0]).get('name'), setting.get('session'), tongbuObj.newFolder);
					}else if (noteidlength) {
						tongbuObj.newNote(noteCollection.get(setting.get('noteAddedId')[0]).get('name'), noteCollection.get(setting.get('noteAddedId')[0]).get('content'), noteCollection.get(setting.get('noteAddedId')[0]).get('folderId'), tongbuObj.newNote);
					}
					if (folderupdatelength) {
						tongbuObj.updateFolder(folderCollection.get(setting.get('folderUpdatedId')[0]).get('id'), folderCollection.get(setting.get('folderUpdatedId')[0]).get('name'), tongbuObj.updateFolder);
					}
					if (noteupdatelength) {
						tongbuObj.updateNote(noteCollection.get(setting.get('noteUpdatedId')[0]).get('name'), noteCollection.get(setting.get('noteUpdatedId')[0]).get('content'), noteCollection.get(setting.get('noteUpdatedId')[0]).get('id'), tongbuObj.updateNote);
					}
					if (folderdeletelength) {
						console.log("folderdeletelength" + folderdeletelength);
						console.log(setting.get('folderDeletedId')[0]);
						tongbuObj.deleteFolder(setting.get('folderDeletedId')[0], tongbuObj.deleteFolder);
					}
					if (notedeletelength) {
						tongbuObj.deleteNote(setting.get('noteDeletedId')[0], tongbuObj.deleteNote);
					}

				} else {
					console.log("当前离线");
				}

			} else {
				$("#loginModal h4").html("请先登录！");
				this.showLoginModal();
			}
		},


		//退出账号
		logout: function() {
			console.log('退出了');
			$.ajax({
				url: 'http://tnotes.wicp.net:8080/signout.cgi',
				type: 'POST',
				data: '{"session":' + '"' + setting.get('session') + '"}'
			}).done(function(data) {
				console.log(data);
				if (data.status == 'success') {
					setting.set({
						lastUsername: '',
						lastPassword: '',
						session: '',
						noteDeletedId: [],
						folderDeletedId: [],
						noteAddedId: [],
						folderAddedId: [],
						noteUpdatedId: [],
						folderUpdatedId: []
					});
					// indexedDB.deleteDatabase("folders");
					// indexedDB.deleteDatabase("notes");
					var folderindexeddb = indexedDB.open('folders');
					folderindexeddb.onsuccess = function() {
						var re = folderindexeddb.result;
						transaction = re.transaction(["folders"], "readwrite");
						store = transaction.objectStore("folders");
						store.clear();
					};
					var noteindexeddb = indexedDB.open('notes');
					noteindexeddb.onsuccess = function() {
						var re = noteindexeddb.result;
						transaction = re.transaction(["notes"], "readwrite");
						store = transaction.objectStore("notes");
						store.clear();
					};
					folderCollection.reset();
					folderCollection.trigger('change');
					noteCollection.reset();
					noteCollection.trigger('change');
					contentViewer.reset();
					// setting.clear();

					$("#login").show();
					$("#logout").hide();
					$("#regist").show();
					$("#hint").removeClass('alert-danger');
					$("#hint").addClass('alert-success');
					$("#hint h4").html("");
					hintview.setContent("已经退出当前账号！").show();
					$("#currentUser").html('离线');

				} else {
					$("#hint").addClass('alert-danger');
					$("#hint h4").html("");
					hintview.setContent("服务器异常！").show();
				}
			}).fail(function() {
				$("#hint").addClass('alert-danger');
				$("#hint h4").html("抱歉");
				hintview.setContent("请求失败！").show();
			}).always(function() {
				folderCollection.fetchFolder();
			});

		},

		//更改全局样式
		changeGlobalStyle: function(e) {
			var $item = $(e.target);
			var globalStyle = $item.attr("data-style");
			this.changeGlobalStyleByNmae(globalStyle);
		},

		changeGlobalStyleByNmae: function(globalStyle) {
			$("body").attr('class', globalStyle);
			setting.set({
				globalStyle: globalStyle
			});
		}

	});
	var navbar = new NavBar;
	return navbar;
});
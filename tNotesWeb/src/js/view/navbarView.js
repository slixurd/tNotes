define(["setting", "hint"], function(setting, hintview) {
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
				alert("不可以自动登录");
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
			//到时做好接口以后判断条件应该为如果当前在线，也就是判断服务器有没有返回session
			if (setting.get('session') != '') {
				//已经登录，开始同步操作不用判断联网状况，如果没有网络，同步自动失败


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
					// setting.set({
					// 	lastUsername: '',
					// 	lastPassword: '',
					// 	session: ''
					// });
					indexedDB.deleteDatabase("folders");
					indexedDB.deleteDatabase("notes");
					setting.clear();

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
			}).always();

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
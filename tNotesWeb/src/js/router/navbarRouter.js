// navBar路由模块-1396006789626,-1396008090707,-1396008112146

define(['hint', 'navbarView', 'folderCollection', 'noteCollection', 'setting'], function(hintView, navbarView, folderCollection, noteCollection, setting) {
	var Router = Backbone.Router.extend({

		routes: {
			'search': 'searchNote'
		},



		//获取搜索结果并更新笔记列表视图
		searchNote: function() {
			console.log("点击了搜索");
			hintView.setContent("搜索功能有待完善！").show();

		}

	});

	var router = new Router;

	return router;

});
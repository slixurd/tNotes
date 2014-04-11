// noteList路由模块

define(['noteList', 'contentViewer'], function (noteViewer, contentViewer) {

var Router = Backbone.Router.extend({

    routes: {
		'newNote': 'newNote',
		'note/:noteId': 'showNote'
    },

	//新建笔记
	newNote: function () {
		contentViewer.newNote();
		noteViewer.selectNote(null);
	},
	
	//选择笔记
	showNote: function (id) {
		noteViewer.storageNote(id);
		contentViewer.setNote(id);
		noteViewer.selectNote(id);
	}
});

var router = new Router;

return router;

});
// noteList路由模块

define(['noteList', 'contentViewer'], function (noteViewer, contentViewer) {

var Router = Backbone.Router.extend({

    routes: {
		'newNote': 'newNote',
		'note/:noteId': 'showNote'
    },

	//新建笔记
	newNote: function () {
		contentViewerRouter.newNote();
		noteList.selectNote(null);
	},
	
	//选择笔记
	showNote: function (id) {
		contentViewer.setNote(id);
		noteViewer.selectNote(id);
	},
	
	//接收folder传来的数组对象并显示到Note列表中
	setSelectedFolder: function (NotesList) {
		noteViewer.setSelectedFolder(NotesList);
	}
});

var router = new Router;

return router;

});
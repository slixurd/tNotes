// 笔记列表显示视图

define(['noteCollection', 'folderCollection', 'setting'],function (noteCollection, folderCollection, setting) {

var NoteList = Backbone.View.extend({

    el: $('#note'),
	$noteList: $('#note-list'),
	$newNoteBtn: $('#new-note-btn'),
	currentNoteId: null, //当前选中笔记id
	currentFolderId: null, //当前选中文件夹id
	currentNoteList: null,
	displayIds: [], //正在显示的笔记列表
    collection: noteCollection,
	template: _.template($("#note-template").html()),

	/* Click事件 */
    events: {
		'click #new-note-btn' : 'highlightNewBtn', //新建笔记事件
		'click .note' : 'clickNote' //选中笔记事件
    },

    initialize: function () {
		
    },
	
	/*
		render函数可用于重新渲染noteList的HTML
	*/
	render: function () {
		this.$noteList.html(this.template({notes: this.currentNoteList}));
		if (this.currentNoteId) {
			this.$noteList.find('[data-id="' + this.currentNoteId + '"]').addClass('active');
		}
		return this;
	},
	
	//高亮新建笔记按钮
	highlightNewBtn: function (flag) {
		if (flag === false) {
			this.$newNoteBtn.removeClass('active');
		}
		else {
			this.$newNoteBtn.addClass('active');
		}
	},
	
	//点击笔记事件
	clickNote: function (e) {
		var $currentNote = $(e.target);
		this.selectNote($currentNote.attr('data-id'));
	},
	
	//选中笔记事件
	selectNote: function (id) {
		this.currentNoteId = id;
		this.render();
		if(id !== null) {
			this.highlightNewBtn(false);
		}
	},
		
	// 设置要显示笔记的文件夹
	setFolder: function (folderId) {
		this.collection.getNoteListByFolderId(folderId);
		this.currentNoteList = this.collection.getModelsByFolderId(folderId);
		this.render();
	},
	
	//从服务器拉取对应id的Note
	storageNote: function (id) {
		this.collection.getNoteByNoteId(id);
	}
});

var noteList = new NoteList;

noteList.render();

return noteList;

});
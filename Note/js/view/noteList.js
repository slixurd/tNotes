// 笔记列表显示视图

define(['noteCollection', 'folderCollection'],function (noteCollection, folderCollection) {

var NoteList = Backbone.View.extend({

    el: $('#note'),
	$noteList: $('#note-list'),
	$newNoteBtn: $('#new-note-btn'),
	currentNoteId: null, //当前选中笔记id
	currentFolderId: null, //当前选中文件夹id
	displayIds: [], //正在显示的笔记列表
    collection: noteCollection,
	template: _.template($("#note-template").html()),

	/* Click事件 */
    events: {
		'click #new-note-btn' : 'newNote', //新建笔记事件
		'click .note' : 'selectNote' //选中笔记事件
    },

    initialize: function () {
		
    },
	
	/*
		render函数可用于重新渲染noteList的HTML
	*/
	render: function () {
		this.$noteList.html(this.template({notes: this.collection.getModelsByIds(this.displayIds)}));
		if (this.currentNoteId) {
			this.$noteList.find('[data-id="' + this.currentNoteId + '"]').addClass('active');
		}
		return this;
	}
	
	//高亮新建笔记按钮
	highlightNewBtn: function (flag) {
		if (flag === false) {
			this.$newNoteBtn.removeClass('active');
		} 
		else {
			this.$newNoteBtn.addClass('active');
		}
	},
	
	//选中笔记事件
	selectNote: function (e) {
		var $currentNote = $(e.target);
		this.currentNoteId = $currentNote.attr('data-id'));
		this.render();
		//非新建笔记时，新建笔记按钮取消高亮
		if(id !== null) {
			this.highlightNewBtn(false);
		}
	},
		
	//显示选中文件夹的笔记
	setSelectedFolder: function(NotesList) {
		this.$noteList.html(this.template({notes: NotesList});
	},
	
	// 设置要显示笔记的文件夹
    setFolder: function (folderId) {
        this.currentFolderId = folderId;
        var folder = this.folderCollection.get(folderId);
        if (folder) {
            this.setDisplayNotes(folder.get('notes'));
        }
    },
	
	//通过Array类型的id来显示笔记
	setDisplayNotes: function (ids) {
		this.displayIds = ids;
		this.render();
	}
});

var noteList = new NoteList;

noteList.render();

return noteList;

});
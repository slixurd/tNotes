// 笔记列表显示视图

define(['noteCollection', 'folderCollection', 'setting'],function (noteCollection, folderCollection, setting) {

var NoteList = Backbone.View.extend({

    el: $('#note'),
	$noteList: $('#note-list'),
	$newNoteBtn: $('#new-note-btn'),
	currentNoteId: null, //当前选中笔记id
	currentFolderId: 0, //当前选中文件夹id
	currentNoteList: [],
	displayIds: [], //正在显示的笔记列表
    collection: noteCollection,
	
	template: _.template($("#note-template").html()),

	/* Click事件 */
    events: {
		'click #new-note-btn' : 'highlightNewBtn', //新建笔记事件
		'click .note' : 'clickNote' //选中笔记事件
    },

    initialize: function () {
		_.bindAll(this, 'render');
		_.bindAll(this, 'setFolder');
		
		this.setFolder();
		
		this.collection.bind('add', this.render);
		this.collection.bind('add', this.setFolder);
		this.collection.bind('change', this.render);
		this.collection.bind('change', this.setFolder);
		this.collection.bind('remove', this.render);
		this.collection.bind('remove', this.setFolder);
		
		folderCollection.bind('add', this.render);
		folderCollection.bind('change', this.render);
		folderCollection.bind('change', this.setFolder);
		folderCollection.bind('remove', this.render);
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
	
	//测试
	testNewNote: function () {
		this.collection.updateNotePost(80, 'C++', 'C# is so good!');
		//this.collection.deleteNote(85);
		/*
		noteCollection.create({
			title: 'Html',
			brief: 'Summary',
			folderId: 590,
			content: 'Html CSS JAVASCRIPT'
		});
		*/
	},
	
	//高亮新建笔记按钮
	highlightNewBtn: function (flag) {
		if (flag === false) {
			this.$newNoteBtn.removeClass('active');
		}
		else {
			if(this.currentFolderId != 0) {
				this.$newNoteBtn.addClass('active');
			}
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
	setFolder: function () {
		this.currentFolderId = parseInt(folderCollection.getSelectedID());
		if(this.currentFolderId != 0)
		{
			this.$newNoteBtn.removeClass('disabled');
			this.collection.setFolderId(this.currentFolderId);
			this.collection.getNoteListByFolderId();
			this.currentNoteList = this.collection.getModelsByFolderId(this.currentFolderId);
			this.render();
		} else {
			this.$newNoteBtn.addClass('disabled');
			
			var list = this.collection.toJSON();
			this.currentNoteList.splice(0, this.currentNoteList.length);
			if(list.length <= 10) {
				for(var i = list.length - 1; i >= 0; i--) {
					this.currentNoteList.push(list[i]);
				}
			} else {
				for(var i = 9; i >= 0; i--) {
					this.currentNoteList.push(list[i]);
					console.log(i);
				}
			}
			this.render();
		}
	},
	
	//从服务器拉取对应id的Note
	storageNote: function (id) {
		console.log('List get id ' + id);
		this.collection.getNoteByNoteId(id);
	}
});

var noteList = new NoteList;

noteList.render();

return noteList;

});
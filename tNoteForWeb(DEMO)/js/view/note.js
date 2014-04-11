// 笔记视图
define(['collection/notes', 'collection/folders'], function (notes, folders) {

var Note = Backbone.View.extend({
    el: $('#note'),
    $noteList: $('#note-list'),
    $newNoteBtn: $('#new-note-btn'),
    currentNoteId: null, // 当前选中笔记id
    currentFolderId: null,
    collection: notes,
    folderCollection: folders,
    displayNotes: [], // 正在显示的笔记列表
    template: _.template($('#note-template').html()),
    events: {
        'click .note': 'clickNote',
        'click #new-note-btn': 'hightlightNewNoteBtn'
    },
    initialize: function () {

    },
    render: function () {
        this.$noteList.html(this.template({folder: this.currentFolderId, notes: this.collection.getModelsByIds(this.displayNotes)}));
        if (this.currentNoteId) {
            this.$noteList.find('[data-id="' + this.currentNoteId + '"]').addClass('active');
        }
    },
    // 点击笔记
    clickNote: function (e) {
        var $currentNote = $(e.target);
        this.selectNote($currentNote.attr('data-id'));
    },
    // 高亮新笔记按钮
    hightlightNewNoteBtn: function (flag) {
        if (flag === false) {
            this.$newNoteBtn.removeClass('active');
        } else {
            this.$newNoteBtn.addClass('active');
        }
    },
    // 选择笔记
    selectNote: function (id) {
        this.currentNoteId = id;
        this.render();
        if (id !== null) {
            this.hightlightNewNoteBtn(false);
        }
    },
    // 设置要显示笔记的文件夹
    setFolder: function (folderId) {
        this.currentFolderId = folderId;
        var folder = this.folderCollection.get(folderId);
        if (folder) {
            this.setDisplayNotes(folder.get('notes'));
        }
    },
    // 设置要显示的笔记的id号
    setDisplayNotes: function (ids) {
        this.displayNotes = ids;
        this.render();
    }
});

var note = new Note();

note.render();

return note;

});
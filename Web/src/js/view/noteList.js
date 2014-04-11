// 笔记列表显示视图

define(['noteCollection', 'folderCollection', 'hint'], function (noteCollection, folderCollection, hint) {

var NoteList = Backbone.View.extend({

    el: $('#note'),
    $noteList: $('#note-list'),

    newNoteProcessing: false,

    template: _.template($('#note-template').html()),

    collection: noteCollection,
    folderCollection: folderCollection,

    events: {
        'click #new-note-btn': 'newNote'
    },

    initialize: function () {
        _.bindAll(this, 'render', 'changeVisibility');
        this.collection.bind('currentNotesChanged', this.render); // 当前显示笔记列表改变
        this.collection.bind('currentChanged', this.render); // 当前选中笔记改变
        this.collection.bind('visibilityChanged', this.changeVisibility); // 可见性改变
    },

    render: function () {
        this.$noteList.html(this.template({notes: this.collection.getCurrentNotes()}));
        var note = this.collection.getCurrent();
        if (note) {
            this.$noteList.find('[data-id="' + note.get('id') + '"]').addClass('active');
        }
    },

    // 改变视图可见性
    changeVisibility: function () {
        var visibility = this.collection.getVisibility();
        if (visibility === true) {
            this.$el.fadeIn('fast');
        } else {
            this.$el.fadeOut('fast');
        }
    },

    // 新建笔记
    newNote: function () {
        var folder = this.folderCollection.getCurrent();
        if (folder === null) {
            hint.setType('warning').setTitle('请选择一个文件夹')
                .setContent('你必须选择一个文件夹后方可创建新笔记').show();
        } else {
            // 使其半秒种才能执行一次操作，暂时修复连续插入时的bug
            if (this.newNoteProcessing === true) {
                return;
            }
            this.newNoteProcessing = true;
            setTimeout($.proxy(function () {
                this.newNoteProcessing = false;
            }, this), 500);
            var note = this.collection.newNote(folder.get('id'));
            folder.insertNoteId(note.get('id'));
            folder.save();
            this.collection.addNoteToCurrentNotes(note.get('id'));
            // 同步新增创建队列
            this.collection.addSyncCreated(note.get('id'));
        }
    },

    // 选择笔记
    selectNote: function (id) {
        this.collection.setCurrent(id, true);
    }

});

var noteList = new NoteList;

return noteList;

});
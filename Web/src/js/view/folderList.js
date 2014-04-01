// 文章列表显示视图

define(['folderCollection', 'noteCollection'],
    function (folderCollection, noteCollection) {

var FolderList = Backbone.View.extend({

    el: $('#folder'),
    $folderList: $('#folder-list'),
    $newFolderName: $('#new-folder-name'),
    $renameFolderBtn: $('#rename-folder-btn'),
    $deleteFolderBtn: $('#delete-folder-btn'), // 删除文件夹按钮

    template: _.template($('#folder-template').html()),

    collection: folderCollection,
    noteCollection: noteCollection,

    events: {
        'click #new-folder-confirm-btn' : 'newFolder',
        'click #delete-folder-confirm-btn': 'deleteFolder',
        'click #rename-folder-confirm-btn': 'renameFolder'
    },

    initialize: function () {
        _.bindAll(this, 'render', 'changeVisibility');
        this.collection.bind('add', this.render); // 新增文件夹
        this.collection.bind('change', this.render); // 改变文件夹内容
        this.collection.bind('remove', this.render); // 移除文件夹
        this.collection.bind('currentChanged', this.render); // 当前文件夹改变
        this.collection.bind('visibilityChanged', this.changeVisibility); // 可见性改变
    },

    render: function () {
        this.$folderList.html(this.template({folders: this.collection.toJSON()}));
        // 如果有选中文件夹则将其高亮
        if (this.collection.current) {
            // 禁用部分按钮
            this.toggleBtn(true);
            this.$folderList.find('[data-id="' + this.collection.current.get('id') + '"]').addClass('active');
        } else {
            this.toggleBtn(false);
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

    // 删除文件夹
    deleteFolder: function () {
        // 删除文件夹中的笔记
        var folder = this.collection.getCurrent(),
            notes = folder.get('notes'),
            folderId = folder.get('id'), i, len;
        this.collection.setCurrent(null);
        if (folderId < 0) {
            // 如果小于0，说明文件夹还未更新到服务器端，直接从created队列中去除
            this.collection.removeSyncCreated(folderId);
        } else {
            this.collection.addSyncDeleted(folderId);
            this.collection.removeSyncModified(folderId);
        }
        // 删除视图及数据库中与该文件夹相关联的笔记
        this.noteCollection.deleteByIds(notes);
        this.noteCollection.clearCurrentNotes();
        this.noteCollection.setCurrent(null);
        // 去除当前文件夹下的所有笔记更新
        for (i = 0, len = notes.length; i < len; i++) {
            var noteId = notes[i];
            this.noteCollection.removeSyncCreated(noteId);
            this.noteCollection.removeSyncModified(noteId);
            this.noteCollection.removeSyncDeleted(noteId);
        }
        // 删除当前文件夹
        folder.destroy();
    },

    // 新建文件夹
    newFolder: function () {
        // 不传入notes的话会有不明Bug
        var folder = this.collection.create({name: this.$newFolderName.val(), notes: []});
        this.collection.addSyncCreated(folder.get('id'));
    },

    // 重命名文件夹
    renameFolder: function () {
        var newName = $('#rename-folder-name').val(),
            folder = this.collection.getCurrent(),
            folderId = folder.get('id');
        this.collection.renameCurrent(newName);
        if (folderId > 0) {
            this.collection.addSyncModified(folderId);
        }
    },

    // 选中文件夹
    selectFolder: function (id) {
        this.collection.setCurrent(id);
        var folder = this.collection.getCurrent();
        if (folder === undefined) {
            return;
        }
        this.noteCollection.setCurrentNotes(folder.get('notes'));
        this.noteCollection.fetchRemote(folder.get('id'));
    },

    // 开启关闭部分按钮
    toggleBtn: function (flag) {
        if (flag === true) {
            this.$deleteFolderBtn.removeClass('disabled').attr('data-toggle', 'modal');
            this.$renameFolderBtn.removeClass('disabled').attr('data-toggle', 'modal');
        } else {
            this.$deleteFolderBtn.addClass('disabled').removeAttr('data-toggle');
            this.$renameFolderBtn.addClass('disabled').removeAttr('data-toggle');
        }
    }
});

var folderList = new FolderList;

return folderList;

});

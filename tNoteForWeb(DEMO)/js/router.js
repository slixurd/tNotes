// 路由模块
define(['view/folder', 'view/note', 'view/content', 'view/hint'], function (folderView, noteView, contentView, hintView) {

var Router = Backbone.Router.extend({
    routes: {
        'deleteFolder': 'deleteFolder',
        'deleteNote': 'deleteNote',
        'editNote': 'editNote',
        'folder/:id': 'showNotesOfFolder',
        'note/:noteId': 'showNote',
        'newNote': 'newNote',
        'saveNote': 'saveNote'
    },
    // 删除文件夹
    deleteFolder: function () {
        var folderId = folderView.currentFolderId;
        folder = folderView.collection.get(folderId);
        notes = folder.get('notes');
        noteView.collection.deleteByIds(notes);
        folderView.deleteFolder();
        noteView.displayNotes = [];
        noteView.render();
        this.navigate('#');
    },
    // 删除笔记
    deleteNote: function () {
        var noteId = contentView.currentNoteId,
            note = noteView.collection.get(noteId),
            folderId = note.get('folderId');
        noteView.collection.deleteById(noteId);
        folderView.collection.removeNote(folderId, noteId);
        this.navigate('folder/' + folderId, {trigger: true});
        contentView.reset();
    },
    // 编辑笔记
    editNote: function () {
        contentView.enableEdit();
        contentView.reloadRawContent();
    },
    // 新建笔记
    newNote: function () {
        contentView.newNote();
        noteView.selectNote(null);
    },
    // 显示笔记内容
    showNote: function (id) {
        contentView.showNote(id);
        noteView.selectNote(id);
    },
    // 显示指定文件夹下的笔记
    showNotesOfFolder: function (id) {
        folderView.selectFolder(id);
        noteView.setFolder(id);
    },
    // 保存笔记
    saveNote: function () {
        var currentNoteId = contentView.currentNoteId;
        if (contentView.currentNoteId === null) {
            // 新建笔记
            var currentFolderId = folderView.currentFolderId;
            if (currentFolderId !== null) {
                // 如果有选中文件夹
                var data = contentView.getTitleAndContent();
                var result = noteView.collection.create({
                    folderId: currentFolderId,
                    title: data.title,
                    content: data.content
                });
                var id = result.get('id');
                folderView.collection.insertNoteId(currentFolderId, id);
                contentView.disableEdit();
                this.navigate('note/' + id, {trigger: true});
            } else {
                hintView.set('请选择一个分类用于保存新笔记').show();
                this.navigate('');
            }
        } else {
            // 更新现有笔记
            console.log('fuck');
            var data = contentView.getTitleAndContent();
            noteView.collection.updateById(currentNoteId, contentView.getTitleAndContent());
            contentView.disableEdit();
            this.showNote(currentNoteId);
            this.navigate('');
        }
    }
});

var router = new Router();

// 开启路由功能
Backbone.history.start();

return router;

});
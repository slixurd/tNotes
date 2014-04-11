// 文件夹视图
define(['collection/folders'], function (folders) {

var Folder = Backbone.View.extend({
    el: $('#folder'),
    $folderList: $('#folder-list'), // 文件列表容器
    $newFolderName: $('#new-folder-name'), // 新文件名
    currentFolderId: null, // 当前选中文件夹id
    $deleteFolderBtn: $('#delete-folder-btn'), // 删除文件夹按钮
    collection: folders,
    template: _.template($('#folder-template').html()),
    events: {
        'click #new-folder-confirm-btn' : 'newFolder',
        'click #delete-folder-confirm-btn': 'closeDeleteFolderModal',
        'click .folder': 'clickFolder'
    },
    initialize: function() {
        // 绑定模型，当模型改变时，视图做出相应的响应
        _.bindAll(this, 'render');
        this.collection.bind('add', this.render);
        this.collection.bind('remove', this.render);
        this.collection.bind('change', this.render);
    },
    render: function () {
        this.$folderList.html(this.template({folders: this.collection.toJSON()}));
        // 如果有选中文件夹则将其高亮
        if (this.currentFolderId) {
            this.$folderList.find('[data-id="' + this.currentFolderId + '"]').addClass('active');
        }
    },
    // 点击文件夹
    clickFolder: function (e) {
        var $currentFolder = $(e.target);
        this.selectFolder($currentFolder.attr('data-id'));
    },
    // 关闭删除文件夹模态框
    closeDeleteFolderModal: function () {
        $('#deleteFolderModal').modal('hide');
    },
    // 删除文件夹
    deleteFolder: function () {
        this.collection.deleteById(this.currentFolderId);
        this.currentFolderId = null;
        // 禁用部分按钮
        this.$deleteFolderBtn.addClass('disabled').removeAttr('data-toggle');
    },
    // 新建文件夹
    newFolder: function () {
        this.collection.create({name: this.$newFolderName.val()});
    },
    // 选中文件夹
    selectFolder: function (id) {
        this.currentFolderId = id;
        this.render();
        // 恢复部分不可用按钮
        this.$deleteFolderBtn.removeClass('disabled').attr('data-toggle', 'modal');
    }
});

var folder = new Folder();

folder.render();

return folder;

});
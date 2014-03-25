// 文章列表显示视图

define(['folderCollection'], function (folderCollection) {

var FolderView = Backbone.View.extend({
	//引用#folder,相当于View的关联对象
    el: $('#folder'),
    collection: folderCollection,
    template: _.template($('#folder-template').html()),

    /*事件*/
    events: {
    	
    	'click #new-folder-confirm-btn' : 'newFolder',  //新建文件夹事件
        'click #delete-folder-confirm-btn': 'deleteFolder', //删除文件夹事件
        'click #rename-folder-confirm-btn': 'renameFolder',  //重命名文件夹事件
        'click .folder': 'selectFolder',  //选中文件夹事件

    },

    initialize: function () {
    	_.bindAll(this, 'render');
        this.collection.bind('add', this.render);
        this.collection.bind('change', this.render);
        this.collection.bind('remove', this.render);
    },

	/* 
	   render默认实现是没有操作的。
	   重载本函数可以实现从模型数据渲染视图模板，并可用新的 HTML 更新 this.el。
	   在 render 函数的末尾 return this 实现链式调用。
	*/
    render: function(){
    	$('#folder-list').html(this.template({folders: this.collection.toJSON()}));
    	$('#folder-list').find('[data-id="' + this.collection.currentID + '"]').addClass('active');
    	return this;
    },

    /* 新建文件夹 */
    newFolder: function(){
    	var newFolderInput = $('#new-folder-name');

    	this.collection.create({name: newFolderInput.val()}); //将new-floder-name获取到的名字插入collection
    	newFolderInput.val("");
    },

    /* 重命名文件夹 */
    renameFolder: function(){
    	var renameFolderInput = $('#rename-folder-name');

    	this.collection.get(this.collection.currentID).set({name:(renameFolderInput.val()=="")?"重命名文件夹":renameFolderInput.val()});
        this.collection.updateModifiedTime();
        renameFolderInput.val("");
    },

    /* 删除文件夹 */
    deleteFolder: function(){
    	this.collection.get(this.collection.currentID).destroy();
    	this.collection.currentID = 0;
    	
    	// 删除对话框隐藏
    	$('#deleteFolderModal').modal('hide');

    	// 禁用删除按钮
    	$('#rename-folder-button').addClass('disabled').removeAttr('data-toggle', 'modal');
        $('#delete-folder-btn').addClass('disabled').removeAttr('data-toggle');
    },

	/* 选中文件夹 */
    selectFolder: function (event) {
        if(this.collection.currentID == 0){
	        // 恢复部分不可用按钮
	        $('#rename-folder-button').removeClass('disabled').attr('data-toggle', 'modal');
	        $('#delete-folder-btn').removeClass('disabled').attr('data-toggle', 'modal');
        }

        this.collection.currentID = $(event.target).attr('data-id');

        this.render();
    },

    /* 清空所有文件夹 */
    clearFolder: function(){
        this.collection.reset();
    },

    /* 淡出事件 */
    fadeToggle: function(){
        this.$el.fadeToggle();
    },

    /* 添加文章 */
    addNote: function(id){
        this.collection.addNote(id);
    },

    /* 删除文章 */
    removeNote: function(id){
        this.collection.removeNote(id);
    },

     /* 清空文章 */
    clearNote: function(){
        this.collection.clearNote();
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        this.collection.updateModifiedTime(time);
    },

});

var folderView = new FolderView;
folderView.render();

return FolderView;

});
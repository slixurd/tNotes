// 文章列表显示视图

define(['folderCollection', 'noteCollection', 'setting'], function (folderCollection, noteCollection, setting) {

var FolderView = Backbone.View.extend({
	//引用#folder,相当于View的关联对象
    el: $('#folder'),
    folders: folderCollection,
    notes: noteCollection,

    setting: setting,

    template: _.template($('#folder-template').html()),

    test: 0,

    /*事件*/
    events: {
    	
    	'click #new-folder-confirm-btn' : 'newFolder',  //新建文件夹事件
        'click #delete-folder-confirm-btn': 'deleteFolder', //删除文件夹事件
        'click #rename-folder-confirm-btn': 'renameFolder',  //重命名文件夹事件
        'click .folder': 'selectFolder',  //选中文件夹事件
    },

    initialize: function () {
    	_.bindAll(this, 'render');

        this.folders.bind('add', this.render);
        this.folders.bind('change', this.render);
        this.folders.bind('remove', this.render);

        this.notes.bind('add', this.render);
        this.notes.bind('change', this.render);
        this.notes.bind('remove', this.render);
    },

	/* 
	   render默认实现是没有操作的。
	   重载本函数可以实现从模型数据渲染视图模板，并可用新的 HTML 更新 this.el。
	   在 render 函数的末尾 return this 实现链式调用。
	*/
    render: function(){
        if(this.folders.toggle){
            this.$el.removeClass('hide');
            $('#folder-list').html(this.template({folders: this.folders.toJSON()}));
            $('#folder-list').find('[data-id="' + this.folders.selectedID + '"]').addClass('active');       
        }
        else
            this.$el.addClass('hide');
    	return this;
    },

    /* 新建文件夹 */
    newFolder: function(){
        console.log('FolderView NewFolder');
        
    	var newFolderInput = $('#new-folder-name');

    	var folder = this.folders.create({name: newFolderInput.val()}); //将new-floder-name获取到的名字插入collection

        this.folders.postNewFolder(folder.get('id'));

    	newFolderInput.val("");
    },

    /* 重命名文件夹 */
    renameFolder: function(){
    	var renameFolderInput = $('#rename-folder-name');

        var selectedID = this.folders.getSelectedID();

        var name = (renameFolderInput.val()=="")?"重命名文件夹":renameFolderInput.val();

        this.folders.get(selectedID).save({name:name});
        this.folders.updateModifiedTime();
        
        if(selectedID>0)
            this.folders.postUpdatedFolder(selectedID); //ID是本地的，不用Post
        
        this.folders.sort(); //手动排序

        renameFolderInput.val("");
    },

    /* 删除文件夹 */
    deleteFolder: function(){
        var selectedID = this.folders.getSelectedID();
        var notesID = this.folders.get(selectedID).get('notes');

        // 后删除目录
        this.folders.get(selectedID).destroy();
        if(selectedID>0)
            this.folders.postDeletedFolder(selectedID);
        else{
            //如果ID<0，则为本地文章，将其从新建列表中删除
            var addList = this.setting.get('folderAddedId');
            addList.splice(addList.indexOf(selectedID), 1);
            this.setting.save({folderAddedId: addList});
        }

        this.folders.setSelectedID(0);

        //先删除文章
        for(var i=0; i<notesID.length; ++i){
            console.log(notesID[i]);
            this.notes.get(notesID[i]).destroy();
        }
    	
    	// 删除对话框隐藏
    	$('#deleteFolderModal').modal('hide');

    	// 禁用删除按钮
        $('#rename-folder-button').addClass('disabled').removeAttr('data-toggle', 'modal');
        $('#delete-folder-btn').addClass('disabled').removeAttr('data-toggle', 'modal');
    },

	/* 选中文件夹 */
    selectFolder: function (event) {
        this.folders.setSelectedID(parseInt($(event.target).attr('data-id')));

        if(this.folders.selectedID != 0){
            // 恢复部分不可用按钮
            $('#rename-folder-button').removeClass('disabled').attr('data-toggle', 'modal');
            $('#delete-folder-btn').removeClass('disabled').attr('data-toggle', 'modal');
        }
        else{
            $('#rename-folder-button').addClass('disabled').removeAttr('data-toggle', 'modal');
            $('#delete-folder-btn').addClass('disabled').removeAttr('data-toggle', 'modal');
        }
    },

    /* 清空所有文件夹 */
    clearFolder: function(){
        this.folders.reset();
    },

});

var folderView = new FolderView;
folderView.render();

return FolderView;

});
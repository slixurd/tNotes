// 文章列表显示视图

define(['folderCollection', 'noteCollection', 'setting'], function (folderCollection, noteCollection, setting) {

var FolderView = Backbone.View.extend({
	//引用#folder,相当于View的关联对象
    el: $('#folder'),
    collection: folderCollection,
    notes: noteCollection,

    setting: setting,

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
    	$('#folder-list').html(this.template({folders: this.collection.toJSON()}));
    	$('#folder-list').find('[data-id="' + this.collection.selectedID + '"]').addClass('active');
    	return this;
    },

    /* 新建文件夹 */
    newFolder: function(){
    	var newFolderInput = $('#new-folder-name');

    	var folder = this.collection.create({name: newFolderInput.val()}); //将new-floder-name获取到的名字插入collection

        //将新建文章添加到新建列表
        var addList = this.setting.get('folderAddedID');
        addList.push(folder.get('id'));
        this.setting.set({folderAddedID: addList});

    	newFolderInput.val("");
    },

    /* 重命名文件夹 */
    renameFolder: function(){
    	var renameFolderInput = $('#rename-folder-name');

        var selectedID = this.collection.getSelectedID();

    	this.collection.get(selectedID).set({name:(renameFolderInput.val()=="")?"重命名文件夹":renameFolderInput.val()});
        this.collection.updateModifiedTime();

        
        if(selectedID > 0){
            var updateList = this.setting.get('folderUpdatedID');
            if(updateList.indexOf(selectedID) < 0){
                updateList.push(selectedID); //如果是服务器的目录才需要添加到 更改目录列表
                this.setting.set({folderUpdatedID: updateList});
            }
        }

        renameFolderInput.val("");

    },

    /* 删除文件夹 */
    deleteFolder: function(){
        var selectedID = this.collection.getSelectedID();

    	this.collection.get(selectedID).destroy();

        //将删除文章添加到列表
        if(selectedID>0){
            //如果ID>0，则为服务器文章，将其添加到删除列表
            var updateList = this.setting.get('folderUpdatedID');
            var index = updateList.indexOf(selectedID)
            if(index > 0){
                updateList.splice(index, 1);//如果修改列表中有该文章，也要删除
                this.setting.set({folderUpdatedID: updateList});
            }

            var delelteList = this.setting.get('folderDeletedID');
            delelteList.push(floder.get('id'));
            this.setting.set({folderDeletedID: delelteList});
        }
        else if(this.collection.getCurrentFloderID()<0){
            //如果ID<0，则为本地文章，将其从新建列表中删除
            var addList = this.setting.get('folderAddedID');
            addList.splice(addList.indexOf(floder.get('id')), 1);
            this.setting.set({folderAddedID: addList});
        }

        this.collection.selectedID = 0;
    	
    	// 删除对话框隐藏
    	$('#deleteFolderModal').modal('hide');

    	// 禁用删除按钮
    	$('#rename-folder-button').addClass('disabled').removeAttr('data-toggle', 'modal');
        $('#delete-folder-btn').addClass('disabled').removeAttr('data-toggle');
    },

	/* 选中文件夹 */
    selectFolder: function (event) {
        if(this.collection.selectedID == 0){
	        // 恢复部分不可用按钮
	        $('#rename-folder-button').removeClass('disabled').attr('data-toggle', 'modal');
	        $('#delete-folder-btn').removeClass('disabled').attr('data-toggle', 'modal');
        }

        this.collection.selectedID = $(event.target).attr('data-id');

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
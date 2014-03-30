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

        this.folders.fetchFolder();
    },

	/* 
	   render默认实现是没有操作的。
	   重载本函数可以实现从模型数据渲染视图模板，并可用新的 HTML 更新 this.el。
	   在 render 函数的末尾 return this 实现链式调用。
	*/
    render: function(){
    	$('#folder-list').html(this.template({folders: this.folders.toJSON()}));
    	$('#folder-list').find('[data-id="' + this.folders.selectedID + '"]').addClass('active');
    	return this;
    },

    fetchFolder: function(){
        this.folders.fetchFolder();
    },

    
    /* 从服务器获取Folder列表 */
    /*fetchFolder: function(){
        var self = this;

        $.ajax({
            url: this.host+"fetchnodes.cgi",
            type: 'POST',
            data: '{"session":"'+this.setting.get('session')+'"}'
        }).done(function(data){
            if(data){
                console.log('Success');
                //console.log(data.node.length);
                for(var i=0; i<data.node.length; ++i){
                    self.folders.create(data.node[i]);
                }
                console.log('S-Render');
                self.render();
            }
            else if(data.exception='Node Handling Failure'){
                //处理失败
                console.log('Node Handling Failure');
            }
            else if(data.exception='Session Failure'){
                //session过期，需要重新登录
                console.log('Session Failuer');
            }
            else{
                console.log('Post Else Error!');
                //其他错误
            }
        }).fail(function(){ //由于网络离线或者其他原因导致请求失败了
            console.log('Fail');
        }).always();

        console.log('AJAX-Render');

        //this.render();
    },
    */

    /* 新建文件夹 */
    newFolder: function(){
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

    	//this.folders.get(selectedID).set({name:name, modifiedTime:_.now()});
        this.folders.get(selectedID).set({name:name});
        this.folders.updateModifiedTime();
        
        if(selectedID>0)
            this.folders.postUpdatedFolder(selectedID); //ID是本地的，不用Post

        renameFolderInput.val("");
    },

    /* 删除文件夹 */
    deleteFolder: function(){
        var folderID = this.folders.getSelectedID();
        //先删除文章
        var notesID = this.folders.get(folderID).get('notes');
        for(var i=0; i<notesID.length; ++i){
            this.notes.get(notesID[i]).destroy();
        }

        // 后删除目录
        this.folders.get(folderID).destroy();
        this.folders.postDeletedFolder(folderID);
        this.folders.setSelectedID(0);
    	
    	// 删除对话框隐藏
    	$('#deleteFolderModal').modal('hide');

    	// 禁用删除按钮
        $('#rename-folder-button').addClass('disabled').removeAttr('data-toggle', 'modal');
        $('#delete-folder-btn').addClass('disabled').removeAttr('data-toggle', 'modal');
    },

	/* 选中文件夹 */
    selectFolder: function (event) {

        this.folders.setSelectedID($(event.target).attr('data-id'));

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

    /* 淡出事件 */
    fadeToggle: function(){
        this.$el.fadeToggle();
    },

    /* 添加文章 */
    addNote: function(id){
        this.folders.addNote(id);
    },

    /* 删除文章 */
    removeNote: function(id){
        this.folders.removeNote(id);
    },

     /* 清空文章 */
    clearNote: function(){
        this.folders.clearNote();
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        this.folders.updateModifiedTime(time);
    },

});

var folderView = new FolderView;
folderView.render();

return FolderView;

});
// 文件夹集合，返回Folder集合类实例

define(['FolderModel', 'folderDb', 'setting'], function (FolderModel, database, setting) {

var FolderCollection = Backbone.Collection.extend({
    model: FolderModel,

    database: database,
    storeName: database.storeName,

    setting: setting,

    host: "http://tnotes.wicp.net:8080/",

    selectedID: 0,

    toggle: true,
	
	initialize: function(){

	},

    comparator: function (folder) {
        return folder.get('modifiedTime'); // 按修改日期排序
    },

    /* 添加文章 */
    addNote: function(id){
        if(this.selectedID != 0)
    	   this.get(this.selectedID).addNote(id);
    },

    /* 删除文章 */
    removeNote: function(id){
        if(this.selectedID != 0)
           this.get(this.selectedID).removeNote(id);
    },

     /* 清空文章 */
    clearNote: function(){
        if(this.selectedID != 0)
           this.get(this.selectedID).clearNote();
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        this.get(this.selectedID).updateModifiedTime(time);
    },

    /* 设置选中文件夹的ID */
    setSelectedID: function(id){
        this.selectedID = id;
        this.trigger('change');
    },

    /* 获取选中文件夹的ID */
    getSelectedID: function(){
        return this.selectedID;
    },

     /* 从服务器获取Folder列表 */
    fetchFolder: function(){
        var self = this;

        $.ajax({
            url: this.host+"fetchnodes.cgi",
            type: 'POST',
            data: '{"session":"'+this.setting.get('session')+'"}'
        }).done(function(data){
            if(data.node!=null){
                var addList = self.setting.get('folderAddedId');
                var updateList = self.setting.get('folderUpdatedId');
                var deleteList = self.setting.get('folderDeletedId');

                for(var i=0; i<data.node.length; ++i){
                    var id = data.node[i].id;
                    console.log(typeof(self.get(id)));
                    if(addList.indexOf(id)<0 && updateList.indexOf(id)<0 && deleteList.indexOf(id)<0){
                        self.create({
                            id: data.node[i].id,
                            name: data.node[i].name,
                            notes       : (typeof(self.get(id))==='undefined') ? [] : self.get(id).get('notes'),   // 笔记
                            createTime  : (typeof(self.get(id))==='undefined') ? data.node[i].stamp*1000 : self.get(id).get('createTime'), // 创建时间
                            modifiedTime: data.node[i].stamp*1000    
                        }); //只有三个列表中的都没有这个ID，才创建。
                    }
                }
            }
            else if(data.exception=='Node Handling Failure'){
                //处理失败
            }
            else if(data.exception=='Session Failure'){
                //session过期，需要重新登录
            }
            else{
                //其他错误
            }
        }).fail(function(){ //由于网络离线或者其他原因导致请求失败了
        }).always();
    },

    /* Post新建文件夹 */
    postNewFolder: function(id){
        //获取ID对应文件夹
        var folder = this.get(id);
        var self = this;

        //向服务器发送POST
        $.ajax({
            url: this.host+"createnode.cgi",
            type: 'POST',
            data: '{"session":"'+this.setting.get('session')+'","name":"'+folder.get('name')+'"}'
        }).done(function(data){
            if(data.id&&data.stamp){
                self.create({
                    id: data.id,
                    name: self.get(id).get('name'),
                    notes: self.get(id).get('notes'),   // 笔记
                    createTime: self.get(id).get('createTime'),    // 创建时间
                    modifiedTime: data.stamp*1000
                })
                self.get(id).destroy();
            }
            else if(data.exception=='Node Handling Failure'){
                //处理失败
                self.insertAddList(id);
            }
            else if(data.exception=='Session Failure'){
                //session过期，需要重新登录
                self.insertAddList(id);
            }
            else{
                //其他错误
                self.insertAddList(id);
            }
        }).fail(function(){ //由于网络离线或者其他原因导致请求失败了
            self.insertAddList(id);
        }).always();
    },

    /* Post更新文件夹 */
    postUpdatedFolder: function(id){
        //获取ID对应文件夹
        var folder = this.get(id);
        var self = this;

        //向服务器发送POST
        $.ajax({
            url: this.host+"changenode.cgi",
            type: 'POST',
            data: '{"session":"'+this.setting.get('session')+'","id":'+id+',"name":"'+folder.get('name')+'"}'
        }).done(function(data){
            if(data.stamp){
                folder.save({modifiedTime:data.stamp*1000}); //更新文件夹ID和修改时间
            }
            else if(data.exception=='Node Handling Failure'){
                //处理失败
                self.insertUpdatedList(id);
            }
            else if(data.exception=='Session Failure'){
                //session过期，需要重新登录
                self.insertUpdatedList(id);
            }
            else{
                //其他错误
                self.insertUpdatedList(id);
            }
        }).fail(function(){ //由于网络离线或者其他原因导致请求失败了
            self.insertUpdatedList(id);
        }).always();
    },

    /* Post删除文件夹 */
    postDeletedFolder: function(id){
        var self = this;

        //向服务器发送POST
        $.ajax({
            url: this.host+"deletenode.cgi",
            type: 'POST',
            data: '{"session":"'+this.setting.get('session')+'","id":'+id+'}'
        }).done(function(data){
            if(data.status == 'success'){
                var updateList = self.setting.get('folderUpdatedId');
                var index = updateList.indexOf(id);
                if(index >= 0){
                    updateList.splice(index, 1);//如果修改列表中有该文章，也要删除
                    this.setting.save({folderUpdatedID: updateList});
                }
            }
            else if(data.exception='Node Handling Failure'){
                //处理失败
                self.insertDeletedList(id);
            }
            else if(data.exception='Session Failure'){
                //session过期，需要重新登录
                self.insertDeletedList(id);
            }
            else{
                //其他错误
                self.insertDeletedList(id);
            }
        }).fail(function(){ //由于网络离线或者其他原因导致请求失败了
            self.insertDeletedList(id);
        }).always();
    },

    /* 将未POST成功的FolderID添加到 新增队列 */
    insertAddList: function(id){
        //将新建文章添加到新建列表
        var addList = this.setting.get('folderAddedId');
        addList.push(id);
        this.setting.save({folderAddedId: addList});
    },

    /* 将未POST成功的FolderID添加到 更新队列 */
    insertUpdatedList: function(id){
        var updateList = this.setting.get('folderUpdatedId');
        if(updateList.indexOf(id) < 0){
            updateList.push(id); //如果是服务器的目录才需要添加到 更改目录列表
            this.setting.save({folderUpdatedId: updateList});
        }
    },

    /* 将未POST成功的FolderID添加到 删除队列 */
    insertDeletedList: function(id){
        //如果ID>0，则为服务器文章，将其添加到删除列表
        var updateList = this.setting.get('folderUpdatedId');
        var index = updateList.indexOf(id);
        if(index >= 0){
            updateList.splice(index, 1);//如果修改列表中有该文章，也要删除
            this.setting.save({folderUpdatedId: updateList});
        }

        var deleteList = this.setting.get('folderDeletedId');
        deleteList.push(id);
        this.setting.save({folderDeletedId: deleteList});
    },

    toggleSize: function(){
        if(this.toggle)
            this.toggle = false;
        else
            this.toggle = true;
        this.trigger('change');
    },

});

// 创建folderCollection实例并获取数据
var folderCollection = new FolderCollection;

folderCollection.fetch({success: function(){ folderCollection.fetchFolder() }});

return folderCollection;

});
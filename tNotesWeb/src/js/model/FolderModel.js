// 文件夹模型，返回的是Folder模型类，供Folder集合类使用

define(['setting', 'folderDb'], function (setting, database) {

FolderModel = Backbone.Model.extend({

    // indexDb存储项
    database: database,
    storeName: database.storeName,

    defaults: {
        id          : 0,    // 本地存储的id
        name        : '',   // 文件夹名
        notes       : [],   // 笔记
        createTime  : 0,    // 创建时间
        modifiedTime: 0     // 修改时间
    },

    initialize: function (value) {
        // 如果传值没有id，则说明是创建新对象，赋予新的id
        if(typeof(value.id) === 'undefined'){
            var timeStamp = _.now();
            this.save({
                id: -timeStamp,
                name: (value.name == "") ? "新建文件夹" : value.name,
                createTime: timeStamp,
                modifiedTime: timeStamp
            });
        }

        // 保证每次数据改变后自动存储
        _.bindAll(this, 'save');
        /*this.bind('change', function () {
            console.log("Folder Change");
        });*/
    },

    /* 添加文章 */
    addNote: function(id){
        console.log('Folder AddNote');
        var notes = get('notes');
        notes.push(id);
        this.save({ notes: notes });
        this.updateModifiedTime();
        this.trigger('change');
    },

    /* 删除文章 */
    removeNote: function(id){
        console.log('Folder RemoveNote');
        if(this.get('notes').indexOf(id) >= 0){
            var notes = get('notes').splice(notes.indexOf(id), 1);
            this.save({ notes: notes });
            this.updateModifiedTime();
            this.trigger('change');
        }
    },

    /* 清空文章 */
    clearNote: function(){
        this.save({ notes: [] });
        this.updateModifiedTime();
        this.trigger('change');
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        time = (typeof(time) === 'undefined') ? _.now() : time;
        this.save({modifiedTime: time}); //更新修改时间, silent:true 不引起change事件
    }
});

return FolderModel;

});
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
            this.set({
                id: -timeStamp,
                name: (value.name == "") ? "新建文件夹" : value.name,
                createTime: timeStamp,
                modifiedTime: timeStamp
            });
        }

        // 保证每次数据改变后自动存储
        _.bindAll(this, 'save');
        this.bind('change', function () {
            this.save();
        });
    },

    /* 添加文章 */
    addNote: function(id){
        this.get('notes').push(id);
        this.updateModifiedTime();
        this.trigger('change');
    },

    /* 删除文章 */
    removeNote: function(id){
        var notes = this.get('notes');
        if(notes.indexOf(id) >= 0){
            notes.splice(notes.indexOf(id), 1);
            this.updateModifiedTime();
            this.trigger('change');
        }
        
    },

    /* 清空文章 */
    clearNote: function(){
        var notes = this.get('notes');
        notes.splice(0, notes.length);
        this.updateModifiedTime();
        this.trigger('change');
    },

    /* 更新修改时间 */
    updateModifiedTime: function(time){
        time = (typeof(time) === 'undefined') ? _.now() : time;
        this.set({modifiedTime: time}); //更新修改时间, silent:true 不引起change事件
    }
});

return FolderModel;

});
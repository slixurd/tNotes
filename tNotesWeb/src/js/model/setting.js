// 设置模型，返回的是Setting模型类实例，保存在localStorage中

define(function () {

var SettingModel = Backbone.Model.extend({

    localStorage: new Backbone.LocalStorage("setting"), // 本地localStorage存取实例

    defaults: {
        id                : 0,         // 设置实例的id，不可修改
        folderId          : 1,         // 文件夹自增id
        noteId            : 1,         // 本地笔记自增id
        style             : 'default', // 整站样式
        contentViewerStyle: 'default'  // 编辑框样式
    },

    initialize: function () {
        // 保证每次数据改变后自动存储
        this.bind('change', function () {
            this.save();
        });
    }

});

// 创建setting实例并获取数据
var setting = new SettingModel;
if (localStorage.setting) {
    setting.fetch();
} else {
    setting.save();
}

return setting;

});
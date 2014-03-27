// 设置模型
define(function () {

var Setting = Backbone.Model.extend({
    defaults: {
        folderLastInsertId: 1, // 文件夹自增id记录
        noteLastInsertId: 1, // 笔记自增id记录
        id: 0, // 设置的id，不可修改
        contentStyle: 'default', // 编写框样式
        lastUsername: '',//上次用户登录名
        lastPassword: '',//登录密码
        globalStyle: '',//全局样式
        session: ''  ,   //登录session
        noteDeletedId: '',
        folderDeletedId:'',
        noteAddedId:'',
        folderAddedId:'',
        noteUpdatedID:'',
        folerUpdatedID: ''

    },
    localStorage: new Backbone.LocalStorage("Setting"),
    initialize: function () {
        // 绑定事件
        this.bind('change', function () {
            setting.save();
        });
    }
});

var setting = new Setting();

// 如果没有初始化过则进行初始化
if (!localStorage.Setting) {
    setting.save();
}

setting.fetch();

return setting;

});
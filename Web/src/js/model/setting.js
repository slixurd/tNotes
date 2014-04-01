// 设置模型，返回的是Setting模型类实例，保存在localStorage中

define(function () {

var SettingModel = Backbone.Model.extend({

    url: 'http://tnotes.wicp.net:8080/',
    syncFinishedHandler: null, // 同步完成后的回调函数
    beginTime: _.now(), // 程序的开启时间戳
    isSyncing: false, // 是否正在同步

    localStorage: new Backbone.LocalStorage("setting"), // 本地localStorage存取实例

    defaults: {
        id                : 0,           // 设置实例的id，不可修改
        folderId          : 1,           // 文件夹自增id
        noteId            : 1,           // 本地笔记自增id
        isLogined         : false,       // 是否处于登录状态
        username          : '',          // 当前用户名
        password          : '',          // 当前用户密码，暂不考虑加密
        session           : '',          // 用于通信
        style             : 'bs-black',  // 整站样式
        bg                : '',          // 背景图片地址
        contentViewerStyle: 'default',   // 编辑框样式
        autoSyncInterval  : 5,           // 自动同步时间间隔
        folderSyncDeleted : [],          // 文件夹同步队列
        folderSyncModified: [],
        folderSyncCreated : [],
        noteSyncDeleted   : [],            // 笔记队列
        noteSyncModified  : [],
        noteSyncCreated   : []
    },

    initialize: function () {
        // 保证每次数据改变后自动存储
        this.bind('change', function () {
            console.log('Setting Saved!');
            this.save();
        });
    },

    // 清除数据
    clear: function () {
        this.set({
            isLogined: false,
            username: '',
            password: '',
            session: '',
            folderSyncDeleted : [],
            folderSyncModified: [],
            folderSyncCreated : [],
            noteSyncDeleted   : [],
            noteSyncModified  : [],
            noteSyncCreated   : []
        });
    },

    // 触发同步事件，执行同步模块
    synchronize: function (displayHint) {
        this.trigger('synchronize', displayHint);
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

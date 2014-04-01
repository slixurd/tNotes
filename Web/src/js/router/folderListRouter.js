// folderList路由模块

define(['folderList', 'setting'], function (folderList, setting) {

var Router = Backbone.Router.extend({

    routes: {
        'folder/:id': 'selectFolder'
    },

    // 选择文件夹
    selectFolder: function (id) {
        // 避免刷新时由于数据库连接未完成设置当前文件夹失败
        if ((_.now() - setting.beginTime) > 500) {
            folderList.selectFolder(id);
        } else {
            setTimeout(function () {
                folderList.selectFolder(id);
            }, 500);
        }
    }

});

var router = new Router;

return router;

});
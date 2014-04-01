// noteList路由模块

define(['noteList', 'setting'], function (noteList, setting) {

var Router = Backbone.Router.extend({

    routes: {
        'note/:id': 'selectNote'
    },

    // 选择笔记
    selectNote: function (id) {
        // 避免刷新时由于数据库连接未完成设置当前文件夹失败
        if ((_.now() - setting.beginTime) > 500) {
            noteList.selectNote(id);
        } else {
            setTimeout(function () {
                noteList.selectNote(id);
            }, 500);
        }
    }

});

var router = new Router;

return router;

});
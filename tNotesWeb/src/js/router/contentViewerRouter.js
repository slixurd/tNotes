// contentView路由模块

define(['contentViewer', 'hint'], function (contentViewer, hint) {

var Router = Backbone.Router.extend({

    routes: {
        'deleteNote': 'deleteNote',
        'saveNote': 'saveNote',
        'saveAndQuitEditing': 'saveAndQuitEditing',
        'toggleContentViewerSize': 'toggleSize'
    },

    // 清除hash
    clearNav: function () {
        this.navigate('', {trigger: false});
    },

    // 删除笔记
    deleteNote: function () {
        contentViewer.deleteNote();
        this.clearNav();
    },

    // 保存笔记
    saveNote: function () {
        contentViewer.saveNote();
        this.clearNav();
    },

    // 保存并退出编辑模式
    saveAndQuitEditing: function () {
        this.saveNote();
        contentViewer.disableEdit();
        contentViewer.showNote();
    },

    // 扩展页面
    toggleSize: function () {
        contentViewer.toggleSize();
        this.clearNav();
    }

});

var router = new Router;

return router;

});
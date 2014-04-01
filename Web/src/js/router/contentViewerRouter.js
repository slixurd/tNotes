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
        var validate = contentViewer.validate();
        // 对数据合法性进行检测，目前是标题不能为空
        if (validate === true) {
            contentViewer.saveNote();
            this.clearNav();
            return true;
        } else {
            hint.setType('warning').setTitle('警告').setContent(validate).show();
            this.clearNav();
        }
    },

    // 保存并退出编辑模式
    saveAndQuitEditing: function () {
        var result = this.saveNote();
        if (result === true) {
            contentViewer.disableEdit();
            contentViewer.showNote();
        }
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
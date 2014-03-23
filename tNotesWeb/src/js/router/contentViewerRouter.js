// contentView路由模块

define(['contentViewer', 'hint'], function (contentViewer, hint) {

var Router = Backbone.Router.extend({

    routes: {
        'toggleContentViewerSize': 'toggleSize'
    },

    // 扩展页面
    toggleSize: function () {
        contentViewer.toggleSize();
        this.navigate('', {trigger: false});
    }

});

var router = new Router;

return router;

});
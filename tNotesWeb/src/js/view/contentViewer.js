// 文章内容显示视图

define(['setting'], function (setting) {

var ContentViewer = Backbone.View.extend({

    el: $('#content'),
    $noteContent: $('#note-content'),

    events: {
        'click .change-style': 'changeStyleClicked'
    },

    initialize: function () {
        // 加载样式
        var style = setting.get('contentViewerStyle');
        this.changeStyle(style);
    },

    // 改变样式
    changeStyle: function (style) {
        this.$noteContent.attr('class', 'panel-body ' + style);
        // 保存样式设置
        setting.set('contentViewerStyle', style);
    },

    // 点击改变样式按钮处理函数
    changeStyleClicked: function (e) {
        var $item = $(e.target);
            style = $item.attr('data-style');
        this.changeStyle(style);
    }

});

var contentViewer = new ContentViewer;

return contentViewer;

});
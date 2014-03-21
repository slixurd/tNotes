// 提示信息显示视图

define(function () {

var Hint = Backbone.View.extend({

    el: $('#hint'),
    $hintContent: $('#hint-content'),
    $hintTitle: $('#hint-title'),

    autoDismiss: true,

    events: {
        'click .close': 'close'
    },

    initialize: function () {
        this.setType('info').setTitle('提示').setContent('提示信息');
    },

    // 隐藏Hint视图
    close: function () {
        this.$el.slideUp('fast');
        return this;
    },

    // 设置是否自动关闭
    setAutoDismiss: function (flag) {
        this.autoDismiss = flag;
        return this;
    },

    // 设置内容
    setContent: function (str) {
        this.$hintContent.html(str);
        return this;
    },

    // 设置标题
    setTitle: function (str) {
        this.$hintTitle.html(str);
        return this;
    },

    // 设置样式，可选值有warning，danger，success，info
    setType: function (type) {
        this.$el.attr('class', 'alert alert-dismissable display-none ' + 'alert-' + type);
        return this;
    },

    // 显示Hint视图
    show: function () {
        this.$el.slideDown('fast');
        if (this.autoDismiss) {
            setTimeout($.proxy(this.close, this), 3000);
        }
        return this;
    }

});

var hint = new Hint;

return hint;

});
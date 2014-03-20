// 提示信息视图
define(function () {

var Hint = Backbone.View.extend({
    el: $('#hint'),
    $content: $('#hint-content'),
    events: {
        'click .close': 'close'
    },
    // 设置信息
    set: function (html) {
        this.$content.html(html);
        return this;
    },
    // 显示提示
    show: function () {
        this.$el.slideDown('fast');
        setTimeout($.proxy(this.close, this), 3000);
        return this;
    },
    // 隐藏提示
    close: function () {
        this.$el.slideUp('fast');
    }
});

var hint = new Hint();

return hint;

});
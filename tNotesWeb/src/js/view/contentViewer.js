// 文章内容显示视图

define(['setting'], function (setting) {

var ContentViewer = Backbone.View.extend({

    el: $('#content'),
    $noteTitle: $('#note-title'),
    $noteContent: $('#note-content'),
    $noteFooter: $('#note-footer'),
    $saveBtn: $('#save-btn'),
    $editBtn: $('#edit-btn'),
    $deleteBtn: $('#delete-btn'),
    $exportBtn: $('#export-btn'),
    $expandBtn: $('#expand-btn'),
    $imgPreview: $('#img-preview'),

    markdownConverter: new Showdown.converter(),
    defaultTitle: 'tNotes',
    defaultContent: '![intro](img/intro.jpg)\n\n' +
                    '- *离线存储*：断开网络也能使用\n' +
                    '- *远程同步*：将本地数据备份到远程服务器\n' +
                    '- *Markdown支持*：支持基本的Markdown语法，多种显示样式\n\n' +
                    '> Developed By *腾讯广研创新班邮箱组*',
    size: -1, // -1表示小，1表示大

    currentNote: null, // 存放当前Note模型，如果为null，则表示没有与任何Note相关联

    events: {
        'click .change-style': 'changeStyleClicked',
        'click #img-preview': 'closeImgPreview',
        'click #note-content img': 'showImgPreview'
    },

    initialize: function () {
        // 加载样式
        var style = setting.get('contentViewerStyle');
        this.changeStyle(style);

        this.reset();
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
    },

    // 关闭图片预览
    closeImgPreview: function () {
        this.$imgPreview.fadeOut('fast');
    },

    // 重置
    reset: function () {
        this.currentNote = null,
        this.setTitleAndContent({
            title: this.defaultTitle,
            content: this.markdownConverter.makeHtml(this.defaultContent)
        });
        this.setFooter('版本号：V1.0，更新于2014年3月24日');
        this.setBtnState({
            'save': false,
            'edit': false,
            'delete': false,
            'export': false,
        });
    },

    // 设置按钮可用性
    setBtnState: function (o) {
        function setState($e, state, modalOrNot) {
            if (state === false) {
                $e.addClass('disabled');
                if (modalOrNot === true) {
                    $e.removeAttr('data-toggle');
                }
            } else if (state === true) {
                $e.removeClass('disabled');
                if (modalOrNot === true) {
                    $e.attr('data-toggle', 'modal');
                }
            }
        }
        if (o['save']) {
            setState(this.$saveBtn, o['save'], false);
        }
        if (o['edit']) {
            setState(this.$editBtn, o['edit'], false);
        }
        if (o['delete']) {
            setState(this.$deleteBtn, o['delete'], true);
        }
        if (o['export']) {
            setState(this.$exportBtn, o['export'], false);
        }
    },

    // 设置页脚内容
    setFooter: function (str) {
        this.$noteFooter.html(str);
    },

    // 设置标题和内容
    setTitleAndContent: function (o) {
        this.$noteTitle.html(o.title);
        this.$noteContent.html(o.content);
    },

    // 显示图片预览
    showImgPreview: function (e) {
        var $img = $(e.target);
        this.$imgPreview.find('img').attr('src', $img.attr('src'));
        this.$imgPreview.fadeIn('fast');
    },

    // 改变页面大小
    toggleSize: function () {
        if (this.size === -1) {
            // 最大化
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-small"></span> 收缩');
            this.size = 1;
            this.$el.toggleClass('fill');
            return true;
        } else {
            // 最小化
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-full"></span> 展开');
            this.size = -1;
            this.$el.toggleClass('fill');
            return false;
        }
    }

});

var contentViewer = new ContentViewer;

return contentViewer;

});
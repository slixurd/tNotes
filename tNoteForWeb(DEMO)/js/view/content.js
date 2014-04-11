// 文章内容显示视图
define(['collection/notes', 'util', 'model/setting'], function (notes, util, setting) {

var Content = Backbone.View.extend({
    el: $('#content'),
    $noteTitle: $('#note-title'),
    $noteContent: $('#note-content'),
    $saveBtn: $('#save-btn'),
    $editBtn: $('#edit-btn'),
    $deleteBtn: $('#delete-btn'),
    $exportBtn: $('#export-btn'),
    $expandBtn: $('#expand-btn'),
    $folder: $('#folder'),
    $note: $('#note'),
    converter: new Showdown.converter(),
    collection: notes,
    currentNoteId: null,
    defaultTitle: 'tNotes',
    defaultContent: 'tNotes Web端 By 腾讯广研创新班',
    size: -1, // 当前窗口大小，-1为小，1为大
    events: {
        'click #expand-btn': 'toggleSize',
        'click #delete-note-confirm-btn': 'closeDeleteNoteModal',
        'click .change-style': 'changeStyle'
    },
    initialize: function () {
        // 加载设置
        var style = setting.get('contentStyle');
        this.changeStyleByName(style);

        this.reset();
    },
    // 改变样式
    changeStyle: function (e) {
        var $item = $(e.target),
            style = $item.attr('data-style');
        this.changeStyleByName(style);
    },
    changeStyleByName: function (style) {
        this.$noteContent.attr('class', 'panel-body ' + style);
        setting.set('contentStyle', style);
    },
    // 清除内容
    clear: function () {
        this.$noteTitle.html('标题');
        this.$noteContent.html('内容');
    },
    // 关闭删除笔记模态框
    closeDeleteNoteModal: function () {
        $('#deleteNoteModal').modal('hide');
    },
    // 关闭编辑模式
    disableEdit: function () {
        this.$noteTitle.removeAttr('contentEditable');
        this.$noteContent.removeAttr('contentEditable');
    },
    // 开启编辑模式
    enableEdit: function () {
        this.$noteTitle.attr('contentEditable', 'true').html();
        this.$noteContent.attr('contentEditable', 'true');
        this.setBtnState({
            'save': true,
            'edit': false,
            'delete': false,
            'export': false,
        });
    },
    // 获取标题和内容
    getTitleAndContent: function () {
        return {
            title: this.$noteTitle.text(),
            content: util.htmlToText(this.$noteContent.html())
        }
    },
    // 新建笔记
    newNote: function () {
        this.currentNoteId = null;
        this.clear();
        this.enableEdit();
    },
    // 重新加载数据
    reloadRawContent: function () {
        var note = this.collection.get(this.currentNoteId);
        this.$noteTitle.html(note.get('title'));
        this.$noteContent.html(util.textToHtml(note.get('content')));
    },
    // 重置
    reset: function () {
        this.currentNoteId = null,
        this.setTitleAndContent({
            title: this.defaultTitle,
            content: this.defaultContent
        });
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
        setState(this.$saveBtn, o['save'], false);
        setState(this.$editBtn, o['edit'], false);
        setState(this.$deleteBtn, o['delete'], true);
        setState(this.$exportBtn, o['export'], false);
    },
    // 设置标题和内容
    setTitleAndContent: function (o) {
        this.$noteTitle.html(o.title);
        this.$noteContent.html(o.content);
    }, 
    // 显示指定id的笔记
    showNote: function (id) {
        this.currentNoteId = Number(id);
        this.disableEdit();
        var note = this.collection.get(id);
        if (!note) {
            return;
        }
        this.setTitleAndContent({
            title: note.get('title'),
            content: this.converter.makeHtml(note.get('content'))
        });
        // 加载下载数据
        this.$exportBtn.attr('download', note.get('title') + '.md')
            .attr('href', URL.createObjectURL(new Blob([note.get('content').replace(/\n/g, '\r\n')], {type: 'text/plain'})));
        this.setBtnState({
            'save': false,
            'edit': true,
            'delete': true,
            'export': true,
        });
    },
    // 改变内容框的大小
    toggleSize: function () {
        if (this.size === -1) {
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-small"></span> 收缩');
            this.$folder.fadeOut('fast');
            this.$note.fadeOut('fast');
            this.size = 1;
        } else {
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-full"></span> 展开');
            this.$folder.fadeIn('fast');
            this.$note.fadeIn('fast');
            this.size = -1;
        }
        this.$el.toggleClass('fill');
    }
});

var content = new Content();

return content;

});
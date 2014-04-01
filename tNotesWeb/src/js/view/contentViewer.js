// 文章内容显示视图

define(['setting', 'noteCollection', 'folderCollection', 'util'], function (setting, noteCollection,folderCollection, util) {

var ContentViewer = Backbone.View.extend({

    el: $('#content'),
    $noteTitle: $('#note-title'),
    $noteContent: $('#note-content'),
    $noteFooter: $('#note-footer'),
    $saveBtn: $('#save-btn'),
    $editBtn: $('#edit-btn'),
    $saveQuitBtn: $('#save-quit-btn'),
    $deleteBtn: $('#delete-btn'),
    $exportBtn: $('#export-btn'),
    $expandBtn: $('#expand-btn'),
    $imgPreview: $('#img-preview'),
    $editTool: $('#edit-tool'),

    markdownConverter: new Showdown.converter(),
    defaultTitle: 'tNotes',
    defaultContent: '![intro](img/intro.jpg)\n\n' +
                    '- *离线存储*：断开网络也能使用\n' +
                    '- *远程同步*：将本地数据备份到远程服务器\n' +
                    '- *Markdown支持*：支持基本的Markdown语法，多种显示样式\n\n' +
                    '> Developed By *腾讯广研创新班邮箱组*',
    size: -1, // -1表示小，1表示大
    selectedText: '', // 选中的文本内容
    range: null, // 替换选中域
    isEditing: false, // 是否正处于编辑状态

    currentNote: null, // 存放当前Note模型，如果为null，则表示没有与任何Note相关联
    noteCollection: noteCollection,

    events: {
        'click .change-style': 'changeStyleClicked',
        'click #img-preview': 'closeImgPreview',
        'click #note-content img': 'showImgPreview',
        'click #print-btn': 'print',
        'click #edit-btn:not(.disabled)': 'editNote',
        'click #delete-note-confirm-btn': 'closeDeleteNoteModal',
        'keyup #note-content': 'updateOnTyping'
    },

    initialize: function () {
        // 加载样式
        var style = setting.get('contentViewerStyle');
        this.changeStyle(style);
        this.initEditor();
        this.reset();

        // 测试用
        setTimeout($.proxy(function () {
            var models = this.noteCollection.where({
                folderId: "5"
            });
            console.log(models);
        }, this), 2000);
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

    // 清除内容
    clear: function () {
        this.$noteTitle.html('');
        this.$noteContent.html('');
    },

    // 关闭删除笔记模态框
    closeDeleteNoteModal: function () {
        $('#deleteNoteModal').modal('hide');
    },

    // 关闭图片预览
    closeImgPreview: function () {
        this.$imgPreview.fadeOut('fast');
    },

    // 删除笔记
    deleteNote: function () {
        this.currentNote.destroy();
        this.reset();
    },

    // 关闭编辑模式
    disableEdit: function () {
        this.$noteTitle.removeAttr('contentEditable');
        this.$noteContent.removeAttr('contentEditable');
        this.isEditing = false;
        this.$saveQuitBtn.addClass('hidden');
        this.$editBtn.removeClass('hidden');
    },

    // 编辑笔记
    editNote: function () {
        var note = this.currentNote;
        this.isEditing = true;
        this.enalbleEdit();
        this.$noteTitle.html(note.get('title'));
        this.$noteContent.html(util.textToHtml(note.get('content')));
    },

    // 开启编辑模式
    enalbleEdit: function () {
        this.$noteTitle.attr('contentEditable', 'true');
        this.$noteContent.attr('contentEditable', 'true');
        this.isEditing = true;
        this.$saveQuitBtn.removeClass('hidden');
        this.$editBtn.addClass('hidden');
        this.setBtnState({
            'save': false,
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

    // 初始化编辑器
    initEditor: function () {
        // 改变div编辑时回车加<div>的默认形为，变成添加<br/>，方便转换
        this.$noteContent.on('keypress', function (e) {
            if (e.which === 13) {
                e.preventDefault();
                if (window.getSelection) {
                  var selection = window.getSelection(),
                      range = selection.getRangeAt(0),
                      br = document.createElement("br");
                  range.deleteContents();
                  range.insertNode(br);
                  range.setStartAfter(br);
                  range.setEndAfter(br);
                  selection.removeAllRanges();
                  selection.addRange(range);
                }
            }
        }).on('mouseup', $.proxy(function () {
            // 选中文字时弹出编辑工具
            if (this.isEditing === true) {
                this.selectedText = util.getSelectionHtml();
                if ($.trim(this.selectedText) !== '') {
                    var pos = util.getSelectionPos();
                    this.$editTool.css('left', (pos.x - 78) + 'px')
                        .css('top', (pos.y - 70) + 'px')
                        .fadeIn('fast');
                    this.range = util.getSelectionRange();
                }
            }
        }, this)).on('mousedown blur', $.proxy(function () {
            this.$editTool.fadeOut('fast');
        }, this));

        // 编辑按钮功能
        $('#bold-btn').on('click', $.proxy(function () {
            var replacement = '**' + this.selectedText + '**';
            this.replaceSelectionText(replacement);
        }, this));
        $('#italic-btn').on('click', $.proxy(function () {
            var replacement = '*' + this.selectedText + '*';
            this.replaceSelectionText(replacement);
        }, this));
        $('#insert-link-confirm-btn').on('click', $.proxy(function () {
            var replacement = '[' + this.selectedText + ']' + '(' + $('#link').val() +')';
            // 如果勾选了图片选项则添叹号
            if ($('#is-img-link').is(':checked') === true) {
                replacement = '!' + replacement;
            }
            this.replaceSelectionText(replacement);
        }, this));

        // 辅助按钮
        $('.scroll').on('click', function () {
            $.smoothScroll({
                scrollTarget: $(this).attr('data-target'),
                speed: 300,
                easing: 'linear'
            }); 
        });
    },

    // 新笔记
    newNote: function () {
        this.currentNote = null;
        this.clear();
        this.enalbleEdit();
    },

    // 打印
    print: function () {
        window.print();
    },

    // 替换选中文字
    replaceSelectionText: function (str) {
        this.range.deleteContents();
        this.range.insertNode(document.createTextNode(str));
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

    // 保存笔记
    saveNote: function () {
        this.currentNote.set({
            title: this.$noteTitle.text(),
            content: util.htmlToText(this.$noteContent.html()),
            modifiedTime: _.now()
        });
        this.setBtnState({
            'save': false
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
        if (typeof o['save'] !== 'undefined') {
            setState(this.$saveBtn, o['save'], false);
        }
        if (typeof o['edit'] !== 'undefined') {
            setState(this.$editBtn, o['edit'], false);
        }
        if (typeof o['delete'] !== 'undefined') {
            setState(this.$deleteBtn, o['delete'], true);
        }
        if (typeof o['export'] !== 'undefined') {
            setState(this.$exportBtn, o['export'], false);
        }
    },

    // 设置页脚内容
    setFooter: function (str) {
        this.$noteFooter.html(str);
    },

    // 设置笔记
    setNote: function (id) {
        this.currentNote = this.noteCollection.get(id);
        this.showNote();
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

    // 显示笔记
    showNote: function () {
        var note = this.currentNote;

        this.disableEdit();
        this.setTitleAndContent({
            title: note.get('title'),
            content: this.markdownConverter.makeHtml(_.unescape(note.get('content')))
        });
        this.setFooter('修改时间：' + util.timestampToTime(note.get('modifiedTime')));
        // 加载下载数据
        this.$exportBtn.attr('download', note.get('title') + '.md')
            .attr('href', URL.createObjectURL(new Blob([note.get('content').replace(/\n/g, '\r\n')],
            {type: 'text/plain'})));

        this.setBtnState({
            'save': false,
            'edit': true,
            'delete': true,
            'export': true,
        });

        // 代码高亮
        this.$noteContent.find('pre').addClass('prettyprint linenums');
        prettyPrint();
    },

    // 改变页面大小
    toggleSize: function () {
        folderCollection.toggleSize();
        if (this.size === -1) {
            // 最大化
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-small"></span> 收缩');
            this.size = 1;
            this.$el.toggleClass('fill');
            $('#note').fadeOut('fast');
            return true;
        } else {
            // 最小化
            this.$expandBtn.html('<span class="glyphicon glyphicon-resize-full"></span> 展开');
            this.size = -1;
            this.$el.toggleClass('fill');
            $('#note').fadeIn('fast');
            return false;
        }
    },

    // 更改文字时触发
    updateOnTyping: function () {
        if (this.isEditing === true) {
            var charNum = this.$noteContent.text().length;
            this.setFooter('字数：' + charNum);
            this.setBtnState({
                'save': true
            });
        }
    },

    // 内容格式验证
    validate: function () {
        // 判断标题是否为空
        if ($.trim(this.$noteTitle.text()) === '')  {
            return '标题不能为空';
        }
        return true;
    }

});

var contentViewer = new ContentViewer;

return contentViewer;

});
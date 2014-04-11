// 导航栏视图

define(['setting', 'syncHelper', 'login', 'signup', 'folderCollection', 'noteCollection'],
    function (setting, syncHelper, login, signup, folderCollection, noteCollection) {

var Navbar = Backbone.View.extend({

    el: $('#navbar'),
    $body: $('body'),
    $settingBtn: $('#setting-btn'),

    collection: null,

    events: {
        'click .change-bg': 'changeBgClicked',
        'click .change-style': 'changeStyleClicked',
        'click #set-custom-bg-btn': 'setCustomBg',
        'click #sync-btn': 'synchronize',
        'click #login-btn': 'login',
        'click #logout-confirm-btn': 'logout',
        'click #signup-btn': 'signup',
        'click #sync-interval-confirm-btn': 'setAutoSyncInterval'
    },

    initialize: function () {
        // 加载背景
        var bg = setting.get('bg');
        if (bg !== '') {
            this.changeBg(bg);
        }
        // 加载颜色主题
        var style = setting.get('style');
        this.changeStyle(style);
        // 如果已登录，显示设置按钮并开始间隔同步
        if (setting.get('isLogined') === true) {
            this.toggleSettingBtn(true);
            $('#auto-sync-val').val(setting.get('autoSyncInterval'));
            setTimeout($.proxy(function () {
                this.autoSync();
            }, this), 200);
        }
    },

    // 自动同步
    autoSync: function () {
        console.log('自动同步');
        this.synchronize();
        if (setting.get('isLogined') === true) {
            setTimeout($.proxy(function () {
                this.autoSync();
            }, this), setting.get('autoSyncInterval') * 60000);
        }
    },

    // 改变背景
    changeBg: function (bg) {
        this.$body.css('background-image', 'url(' + bg + ')');
        setting.synchronize();
    },

    // 点击改变背景
    changeBgClicked: function (e) {
        var $item = $(e.target),
            bg = $item.attr('data-src');
        this.changeBg(bg);
        // 保存背景设置
        setting.set('bg', bg);
    },

    // 改变颜色主题
    changeStyle: function (style) {
        this.$body.attr('class', style);
    },

    // 点击改变颜色主题
    changeStyleClicked: function (e) {
        var $item = $(e.target),
            style = $item.attr('data-style');
        this.changeStyle(style);
        // 保存颜色主题设置
        setting.set('style', style);
    },

    // 登录
    login: function () {
        var username = $('#input-username').val(),
            password = $('#input-password').val();
        login(username, password, true, $.proxy(function() {
            this.toggleSettingBtn(true);
            this.autoSync();
            folderCollection.fetchRemote();
        }, this));
    },

    // 退出帐号
    logout: function () {
        setting.clear();
        this.toggleSettingBtn(false);
        noteCollection.clear();
        folderCollection.clear();
        location.hash = '';
    },

    // 设置自定义背景
    setCustomBg: function () {
        var bg = $('#bg-url').val();
        this.changeBg(bg);
        setting.set('bg', bg);
    },

    // 显示设置按钮
    toggleSettingBtn: function (flag) {
        if (flag === true) {
            this.$settingBtn.removeClass('hidden');
        } else {
            this.$settingBtn.addClass('hidden');
        }
    },

    // 设置同步间隔
    setAutoSyncInterval: function () {
        setting.set('autoSyncInterval', Number($('#auto-sync-val').val()));
    },

    // 注册
    signup: function () {
        var username = $('#input-username').val(),
            password = $('#input-password').val();
        signup(username, password);
    },

    // 同步
    synchronize: function () {
        // 若已经登录了帐号就尝试进行同步，否则弹出登录框
        if (syncHelper.isLogined() === false) {
            $('#loginModal').modal('show');
        } else {
            setting.syncFinishedHandler = function () {
                folderCollection.fetchRemote();
            };
            setting.synchronize(true);
        }
    }

});

var navbar = new Navbar;

return navbar;

});
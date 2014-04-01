// Requirejs配置文件，主要是各模块路径的缩短
require.config({

    paths: {
        'Database': 'db/Database',
        'folderDb': 'db/folderDb',
        'noteDb'  : 'db/noteDb',

        'FolderModel': 'model/FolderModel',
        'NoteModel'  : 'model/NoteModel',
        'setting'    : 'model/setting',

        'folderCollection': 'collection/folderCollection',
        'noteCollection'  : 'collection/noteCollection',

        'contentViewer': 'view/contentViewer',
        'folderList'   : 'view/folderList',
        'noteList'     : 'view/noteList',
        'navbar'       : 'view/navbar',
        'hint'         : 'view/hint',

        'contentViewerRouter': 'router/contentViewerRouter',
        'folderListRouter'   : 'router/folderListRouter',
        'noteListRouter'     : 'router/noteListRouter',
        'navbarRouter'       : 'router/navbarRouter',

        'util'      : 'utils/util',
        'htmlToText': 'utils/htmlToText',
        'login'     : 'utils/login',
        'signup'    : 'utils/signup',
        'sync'      : 'utils/sync',
        'fetch'     : 'utils/fetch',
        'syncHelper': 'utils/syncHelper'
    }

});

// 程序的主入口，加载各视图的Router模块，同时作一些通用性的初始化
require(['contentViewerRouter', 'folderListRouter',
        'noteListRouter', 'navbarRouter', 'utils/test', 'sync', 'fetch', 'login', 'setting', 'folderCollection'], 
        function (contentViewerRouter, folderListRouter,
        noteListRouter, navbarRouter, test, sync, fetch, login, setting, folderCollection) {

// 开启路由功能
Backbone.history.start();

// 绑定一般处理事件
$('body').on('click', 'a.disabled', function (e) {
    // 阻止被设置为disabled的链接产生作用
    e.preventDefault();
});

// 如果登录，自动获取新Session
if (setting.get('isLogined') === true) {
    login(setting.get('username'), setting.get('password'), false, function () {
        // 延迟同步，保证先连上数据库
        if ((_.now() - setting.beginTime) > 500) {
            folderCollection.fetchRemote();
        } else {
            setTimeout(function () {
                folderCollection.fetchRemote();
            }, 500);
        }
    });
}

});
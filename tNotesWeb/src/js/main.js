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

        'util': 'util/util'
    }

});

// 程序的主入口，加载各视图的Router模块，同时作一些通用性的初始化
require(['contentViewerRouter', 'folderListRouter',
        'noteListRouter', 'navbarRouter'], 
        function (contentViewerRouter, folderListRouter,
        noteListRouter, navbarRouter) {

// 开启路由功能
Backbone.history.start();

// 绑定一般处理事件
$('body').on('click', 'a.disabled', function (e) {
    // 阻止被设置为disabled的链接产生作用
    e.preventDefault();
});

});
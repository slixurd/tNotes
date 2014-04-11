require.config({

});

// 主程序入口
define(['router'], function (router) {
    
// 绑定一般处理事件
$('body').on('click', 'a.disabled', function (e) {
    // 阻止被设置为disabled的链接产生作用
    e.preventDefault();
});

});
// 登录模块
define(['setting', 'hint'], function (setting, hint) {

var url = setting.url + 'signup.cgi';

// 注册
function signup(username, password) {
    $.post(url,
    '{"user": "' + username + '","pass": "' + password + '"}', function (data) {
        var type = '',
            title = '',
            content = '';
        if (data.status === 'success') {
            // 注册成功
            type = 'success';
            title = '尊敬的' + username + ':';
            content = '您已经成功注册了帐号，请点击同步按钮登录帐号';
        } else if (data.status === 'used_username') {
            // 用户名被占用
            type = 'warning';
            title = '警告';
            content = '抱歉，该用户名已被注册过，请重新填写一个新的用户名';
        } else if (data.exception) {
            // 服务器端发生异常
            type = 'danger';
            title = '出错';
            content = '抱歉！服务器端暂时无法处理您的请求，请稍后再进行尝试';
        }
        hint.setType(type).setTitle(title).setContent(content).show();
    }, 'json').error(function () {
        hit.setType('danger').setTitle('出错').setContent('发生请求出错，请确保你已经连接了网络').show();
    });
}

return signup;

});
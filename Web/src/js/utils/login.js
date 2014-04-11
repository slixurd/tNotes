// 登录模块
define(['setting', 'hint'], function (setting, hint) {

var url = setting.url + 'signin.cgi';

// 登录，成功设置session等一切参数
function login(username, password, displayHint, callback) {
    $.post(url,
    '{"user": "' + username + '","pass": "' + password + '"}', function (data) {
        var type = '',
            title = '',
            content = '';
        if (data.status === 'success') {
            // 登录成功
            setting.set('isLogined', true);
            setting.set('username', username);
            setting.set('password', password);
            setting.set('session', data.session);
            type = 'success';
            title = '尊敬的' + username + ':';
            content = '您现在已处于登录状态，接下来将自动为您进行同步';
            setting.synchronize();
            if (typeof callback === 'function') {
                callback();
            }
        } else if (data.status === 'incorrect_password') {
            // 密码填写错误
            type = 'warning';
            title = '警告';
            content = '密码填写错误';
        } else if (data.exception) {
            // 服务器端发生异常
            type = 'danger';
            title = '出错';
            content = '抱歉！服务器端暂时无法处理您的请求，请稍后再进行尝试';
        }
        if (displayHint === true) {
            hint.setType(type).setTitle(title).setContent(content).show();
        }
    }, 'json').error(function () {
        if (displayHint === true) {
            hint.setType('danger').setTitle('出错').setContent('发出请求出错，可能是服务器发生故障或者你没有连接到网络').show();
        }
    });
}

return login;

});
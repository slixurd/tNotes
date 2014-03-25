// 公共方法模块

define(function () {

var exports = {};

// 获取选择文字
exports.getSelectionHtml = function () {
    var sel = window.getSelection();
    if (sel.rangeCount) {
        var container = document.createElement("div");
        for (var i = 0, len = sel.rangeCount; i < len; ++i) {
            container.appendChild(sel.getRangeAt(i).cloneContents());
        }
        html = container.innerHTML;
    }
    return html;
};

// 获取选区位置
exports.getSelectionPos = function () {
    var sel = window.getSelection(),
        range = sel.getRangeAt(0),
        boundary = range.getBoundingClientRect(),
        x = boundary.left + (boundary.right - boundary.left) / 2,
        y = boundary.top;
    return {
        x: x,
        y: y
    }
};

// 获取替换选中域
exports.getSelectionRange = function () {
    var sel = window.getSelection(), range;
    if (sel.rangeCount) {
        range = sel.getRangeAt(0);
    }
    return range;
};

// 将html转为txt
exports.htmlToText = function (str) {
    return str.replace(/<br>/g, '\n').replace(/&nbsp;/g, ' ');
};

// 将txt转为html（将\n替换为<br>）
exports.textToHtml = function (str) {
    return str.replace(/\n/g, '<br>').replace(/\s/g, '&nbsp;');
};

// 将timeStamp转换为时间
exports.timestampToTime = function (timestamp) {
    var t = new Date(timestamp);
    return t.getFullYear() + '-' + (t.getMonth() + 1) +
           '-' + t.getDate() + ' ' + t.getHours() + ':'
           + t.getMinutes() + ':' + t.getSeconds(); 
};

return exports;

});
// 公共方法模块

define(['htmlToText'], function (htmlToText) {

var exports = {};

// 单层数组复制
exports.singleArrayClone = function (array) {
    var result = [], i, len;
    for (i = 0, len = array.length; i < len; i++) {
        result[i] = array[i];
    }
    return result;
};

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
    return htmlToText(str);
};

// 从数组中移除指定值
exports.removeArrayValue = function (array, val) {
    var pos = array.indexOf(val);
    if (pos >= 0) {
        array.splice(pos, 1);
    }
    return array;
};

// 从数组中替换指定值，如果有进行替换返回true，否则false
exports.replaceArrayValue = function (array, value, replacement) {
    var pos = array.indexOf(value), flag = false;
    while (pos >= 0) {
        flag = true;
        array[pos] = replacement;
        pos = array.indexOf(value);
    }
    return flag;
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
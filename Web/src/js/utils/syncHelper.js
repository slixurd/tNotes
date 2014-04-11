// 同步需要的函数
define(['setting'], function (setting) {

var exports = {};

// 判断是否已经登录
exports.isLogined = function () {
    return setting.get('isLogined');
};

// 判断是否在线
exports.isOnline = function () {
    if (navigator.onLine) {
        return true;
    } else {
        return false;
    }
};

// 本地更改是否已经全部上传
exports.isAllSync = function () {
    if (setting.get('folderSyncDeleted').length !== 0) {
        return false;
    } else if (setting.get('folderSyncModified').length !== 0) {
        return false;
    } else if (setting.get('folderSyncCreated').length !== 0) {
        return false;
    } else if (setting.get('noteSyncDeleted').length !== 0) {
        return false;
    } else if (setting.get('noteSyncModified').length !== 0) {
        return false;
    } else if (setting.get('noteSyncCreated').length !== 0) {
        return false;
    }
    return true;
};

return exports;

});
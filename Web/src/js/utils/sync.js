// 同步模块
define(['syncHelper', 'setting', 'noteCollection', 'folderCollection', 'util', 'login', 'hint'],
    function (helper, setting, noteCollection, folderCollection, util, login, hint) {

var createFolderUrl = setting.url + 'createnode.cgi',
    deleteFolderUrl = setting.url + 'deletenode.cgi',
    modifyFolderUrl = setting.url + 'changenode.cgi',
    createNoteUrl = setting.url + 'createarticle.cgi',
    deleteNoteUrl = setting.url + 'deletearticle.cgi',
    modifyNoteUrl = setting.url + 'changearticle.cgi';

var text = {
    serverException: '抱歉！服务器端暂时无法处理您的请求，请稍后再进行尝试',
    noConnection: '发出请求出错，可能是服务器发生故障或者你没有连接到网络'
};

var displayHintOrNot = false;

function startSync() {
    if (setting.get('isSyncing') === true) {
        return false;
    }
    setting.set('isSyncing', true);
    return true;
}

function endSync(str) {
    setting.set('isSyncing', false);
    if (displayHintOrNot === true) {
        hint.setType('info').setTitle('提示').setContent(str).show();
    } else {
        console.log(str);
    }
}

// 监听setting中的synchronize事件
setting.bind('synchronize', sync);

// 同步函数
function sync(displayHint) {
    if (startSync() === false) {
        return;
    }
    // 设置是否要显示提示
    if (displayHint === true) {
        displayHintOrNot = true;
    } else {
        displayHintOrNot = false;
    }
    if (helper.isLogined() === false) {
        // 没有登录
        endSync('未登录，无法同步');
    } else if (helper.isOnline() === false) {
        // 没有联网
        endSync('无法连接网络');
    } else if (helper.isAllSync() === true) {
        // 没有数据需要同步时直接执行最后一步
        syncModifiedNote();
        endSync('没有数据需要同步');
    } else {
        syncCreatedFolder();
    }
}

// 同步创建文件夹
function syncCreatedFolder() {
    var createdList = setting.get('folderSyncCreated');
    if (createdList.length === 0) {
        // 无文件夹未创建时执行同步删除文件夹
        setTimeout(function () {
            syncDeletedFolder();
        }, 0);
    } else {
        var folderId = createdList[0],
            folder = folderCollection.get(folderId);
        $.post(createFolderUrl,
        '{"session":"' + setting.get('session') + '", "name":' + JSON.stringify(folder.get('name')) + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Node Handling Failure') {
                // 无错误
                createdList.shift();
                setting.save();
                setTimeout(function () {
                    updateFolderId(folderId, data.id);
                    syncCreatedFolder();
                }, 0);
            } else if (exception === 'Session Failure') {
                // Session失效，只有在这里会发生，重新登录获取session
                endSync('Session失效');
                login(setting.get('username'), setting.get('password'), sync);
            } else {
                // 其它错误
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 同步删除文件夹
function syncDeletedFolder() {
    var deletedList = setting.get('folderSyncDeleted');
    if (deletedList.length === 0) {
        // 无文件夹未删除时执行同步修改文件夹
        setTimeout(function () {
            syncModifiedFolder();
        }, 0);
    } else {
        var folderId = deletedList[0];
        $.post(deleteFolderUrl,
        '{"session":"' + setting.get('session') + '", "id":' + folderId + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Node Handling Failure') {
                deletedList.shift();
                setting.save();
                setTimeout(function () {
                    syncDeletedFolder();
                }, 0);
            } else {
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 同步修改文件夹
function syncModifiedFolder() {
    var modifiedList = setting.get('folderSyncModified');
    if (modifiedList.length === 0) {
        // 无文件夹未修改时执行同步创建笔记
        setTimeout(function () {
            syncCreatedNote();
        }, 0);
    } else {
        var folderId = modifiedList[0],
            folder = folderCollection.get(folderId);
        $.post(modifyFolderUrl,
        '{"session":"' + setting.get('session') + '", "id":' + folderId + ', "name":' + JSON.stringify(folder.get('name')) + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Node Handling Failure') {
                modifiedList.shift();
                setting.save();
                setTimeout(function () {
                    syncModifiedFolder();
                }, 0);
            } else {
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 同步创建笔记
function syncCreatedNote() {
    var createdList = setting.get('noteSyncCreated');
    if (createdList.length === 0) {
        // 无笔记未创建时执行同步删除笔记
        setTimeout(function () {
            syncDeletedNote();
        }, 0);
    } else {
        var noteId = createdList[0],
            note = noteCollection.get(noteId);
        $.post(createNoteUrl,
        '{"session":"' + setting.get('session') + '","name":' + JSON.stringify(note.get('title')) + ',"content":' + JSON.stringify(note.get('content')) + ',"location":' + note.get('folderId') + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Article Handling Failure') {
                createdList.shift();
                setting.save();
                setTimeout(function () {
                    updateNoteId(noteId, data.id);
                    syncCreatedNote();
                }, 0);
            } else {
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 同步删除笔记
function syncDeletedNote() {
    var deletedList = setting.get('noteSyncDeleted');
    if (deletedList.length === 0) {
        // 无笔记未删除时执行同步修改笔记
        setTimeout(function () {
            syncModifiedNote();
        }, 0);
    } else {
        var noteId = deletedList[0];
        $.post(deleteNoteUrl,
        '{"session":"' + setting.get('session') + '", "id":' + noteId + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Article Handling Failure') {
                deletedList.shift();
                setting.save();
                setTimeout(function () {
                    syncDeletedNote();
                }, 0);
            } else {
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 同步修改笔记
function syncModifiedNote() {
    var modifiedList = setting.get('noteSyncModified');
    if (modifiedList.length === 0) {
        // 无笔记未修改时执行回调函数（保存在setting中）
        endSync('同步成功！');
        var finishHandler = setting.syncFinishedHandler;
        if (finishHandler !== null) {
            setTimeout(function () {
                finishHandler();
            }, 0);
        }
    } else {
        var noteId = modifiedList[0],
            note = noteCollection.get(noteId);
        $.post(modifyNoteUrl,
        '{"session":"' + setting.get('session') + '", "id":' + noteId + ', "name":' + JSON.stringify(note.get('title')) + ', "content":' + JSON.stringify(note.get('content')) + '}',
        function (data) {
            var exception = data.exception;
            if (exception === undefined || exception === 'Article Handling Failure') {
                modifiedList.shift();
                setting.save();
                setTimeout(function () {
                    syncModifiedNote();
                }, 0);
            } else {
                endSync(text.serverException);
            }
        }).error(function () {
            endSync(text.noConnection);
        });
    }
}

// 更新文件夹id
function updateFolderId(oldId, newId) {
    folderCollection.updateId(oldId, newId);
    // 更新文件夹下面属于该文件夹的笔记的folderId
    noteCollection.updateFolderId(oldId, newId);
}

// 更新笔记id
function updateNoteId(oldId, newId) {
    var folderId = noteCollection.updateId(oldId, newId);
    // 更新所属文件夹的notes属性
    var folder = folderCollection.get(folderId);
    folder.removeNoteId(oldId);
    folder.insertNoteId(newId);
}

return sync;

});
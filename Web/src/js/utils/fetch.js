// 从远端获取数据
define(['setting', 'folderCollection', 'noteCollection'],
    function (setting, folderCollection, noteCollection) {

var fetchFoldersUrl = setting.url + 'fetchnodes.cgi',
    fetchNotesUrl = setting.url + 'fetchbriefs.cgi',
    fetchNoteUrl = setting.url + 'fetcharticles.cgi';

var text = {
    serverException: '抱歉！服务器端暂时无法处理您的请求，请稍后再进行尝试',
    noConnection: '发出请求出错，可能是服务器发生故障或者你没有连接到网络'
};

// 监听事件
folderCollection.bind('fetchRemote', fetchFolders);
noteCollection.bind('fetchRemote', fetchNotes);
noteCollection.bind('fetchRemoteSingle', fetchNote);

// 获取远程文件夹
function fetchFolders() {
    $.post(fetchFoldersUrl,
    '{"session":"' + setting.get('session') + '"}', function (data) {
        if (data.exception) {
            console.log(text.serverException);
            console.log(data.exception);
        } else {
            var folders = data.node, i, len, folderList = [];
            // 如果没有文件列表，则为null
            if (folders === null) {
                return;
            }
            for (i = 0, len = folders.length; i < len; i++) {
                var folder = folders[i];
                folderList.push(folder.id);
                // 如果本地无该文件夹，重建一个，有的话则只更改名字
                var localFolder = folderCollection.get(folder.id);
                if (localFolder === undefined) {
                    folderCollection.create({
                        id: folder.id,
                        name: folder.name,
                        notes: []
                    });
                } else {
                    localFolder.set('name', folder.name);
                    localFolder.save();
                }
            }
            folderCollection.deleteExceptThese(folderList);
        }
    }).error(function () {
        console.log(text.noConnection);
    });
}

// 获取远程笔记
function fetchNotes(folderId) {
    $.post(fetchNotesUrl,
    '{"session":"' + setting.get('session') + '","id":' + folderId + '}', function (data) {
        if (data.exception) {
            console.log(text.serverException);
            console.log(data.exception);
        } else {
            var notes = data.article, i, len;
            var folder = folderCollection.get(folderId);
            // 如果没有笔记列表，则为null
            if (notes === null) {
                return;
            }
            var remoteList = [];
            for (i = 0, len = notes.length; i < len; i++) {
                var note = notes[i];
                remoteList.push(note.id);
                noteCollection.create({
                    id: note.id,
                    title: note.name,
                    folderId: folderId,
                    modifiedTime: note.stamp
                });
                // 将笔记id存入文件夹中
                folder.insertNoteId(note.id);
            }
            folder.save();
            // 删除掉服务器端没有但本地有的笔记
            var currentIds = noteCollection.getCurrentNotesIds(), note;
            for (i = 0, len = currentIds.length; i < len; i++) {
                var currentId = currentIds[i];
                if (remoteList.indexOf(currentId) < 0 && currentId > 0) {
                    note = noteCollection.get(currentId);
                    folder = folderCollection.get(note.get('folderId'));
                    folder.removeNoteId(currentId);
                    folder.save();
                    note.destroy();
                }
            }
            // 判断当前视图是否还是之前请求时的folder，不然不更新视图
            folder = folderCollection.getCurrent();
            if (folder.get('id') !== folderId) {
                return;
            }
            // 刷新笔记视图
            noteCollection.setCurrentNotes(folder.get('notes'));
        }
    }).error(function () {
        console.log(text.noConnection);
    });
}

// 远程获取单条笔记
function fetchNote(noteId) {
    $.post(fetchNoteUrl,
    '{"session":"' + setting.get('session') + '","id":[' + noteId + ']}', function (data) {
        if (data.exception) {
            console.log(text.serverException);
            console.log(data.exception);
        } else {
            var article = data.article[0],
                note = noteCollection.getCurrent();
            if (note.get('id') !== article.id) {
                return;
            }
            note.set({
                title: article.name,
                content: article.content,
                modifiedTime: article.stamp
            });
            note.save();
            // 刷新编辑器视图
            noteCollection.setCurrent(noteId, false);
        }
    }).error(function () {
        console.log(text.noConnection);
    });
}

return;

});
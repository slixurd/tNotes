## NoteCollection API

- [setFolderId](#setFolderId)
- [getNoteListByFolderId](#getNoteListByFolderId)
- [getNoteByNoteId](#getNoteByNoteId)
- [getModelsByIds](#getModelsByIds)
- [deleteModelById](#deleteModelById)
- [deleteModelsByIds] (#deleteModelsByIds)
- [deleteModelsByFolderId](#deleteModelsByFolderId)
- [updateModelById](#updateModelById)
- [addedNote] (#addedNote)
- [deletedNote] (#deletedNote)
- [updatedNote] (#updatedNote)
- [newNote](#newNote)
- [deleteNote](#deleteNote)
- [updateNote](#updateNote)

---------------------------------
### setFolderId

概要：‘setFolderId(folderId)’

描述：获取当前选中的folderId

参数：

- folderId(number): 选中的folderId

### getNoteListByFolderId

概要：'getNoteListByFolderId(folderId)'

描述: 根据选中文件夹id从服务器获取数据

参数：

- folderId(number): 选中文件夹的id

### getNoteByNoteId

概要：‘getNoteByNoteId(id)’

描述：根据选中笔记id从服务器获取数据

参数：

- id(number): 选中文件的id

### getModelsByIds

概要：`getModelsByIds(Ids)`

描述：根据Array类型的id序列取出Model数组

参数：

- Ids(number[])：对应Note的Id序列

### deleteModelById

概要：`deleteModelById(id)`

描述：根据id号删除对应的Model数据

参数：

- id(number)：要删除笔记的id

### deleteModelsByIds

概要：`deleteModelsByIds(Ids)`

描述：根据Array类型的id序列删除Model数组

参数：

- Ids(number[])：要删除笔记的id序列

### deleteModelsByFolderId

概要：‘deleteModelsByFolderId(folderId)’

描述：根据文件夹id删除对应的笔记

参数：

- folderId(number): 要删除笔记的文件夹id

### updateModelById

概要：`updateModelById(id, data)`

描述：根据id号更新对应的Model数据

参数：

- id(number)：对应Note的Id
- data(JSON): 更新的数据

### addedNote

概要：`addedNote(id)`

描述：新建笔记时将用户操作写入setting的同步队列中

参数：

- id(number)：对应Note的Id

### deletedNote

概要：`deletedNote(id)`

描述：删除笔记时将用户操作写入setting的同步队列中

参数：

- id(number)：对应Note的Id

### updatedNote

概要：`updatedNote(id)`

描述：更新笔记时将用户操作写入setting的同步队列中

参数：

- id(number)：对应Note的Id

### newNote

概要： ‘newNote(title, content)’

描述：新建笔记，传入笔记标题、内容

参数：

- title(string): 笔记标题
- content(string): 笔记内容

### deleteNote

概要： deleteNote(id)’

描述：删除笔记，传入笔记id

参数：

- id(number): 笔记id

### updateNote

概要： updateNote(id, title, content)’

描述：更新笔记，传入笔记id、笔记标题、笔记内容

参数：

- id(number): 笔记id
- title(string): 笔记标题
- content(string): 笔记内容
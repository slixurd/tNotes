## NoteCollection API

- [getModelsByIds](#getModelsByIds)
- [deleteModelById](#deleteModelById)
- [deleteModelsByIds] (#deleteModelsByIds)
- [updateModelById](#updateModelById)
- [addedNote] (#addedNote)
- [deletedNote] (#deletedNote)
- [updatedNote] (#updatedNote)

---------------------------------
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
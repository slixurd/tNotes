## ContentViewer视图API

### 列表
- [newNote](#newnote)
- [reset](#reset)
- [setNote](#setnote)
- [toggleSize](#togglesize)

---------------------------

### newNote
概要：`newNote()`

描述：新建笔记

### reset
概要：`reset()`

描述：重置为初始状态

### setNote
概要：`setNote(id)`

描述：设置并显示指定id的笔记

参数：
- id(number): 笔记的id

### toggleSize
概要：`toggleSize()`

描述：切换大小

返回（boolean）：true表示最大化，false表示最小化
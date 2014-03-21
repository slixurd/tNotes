## Hint视图API

所有方法都返回调用对象本身，即Hint视图，可进行链式调用。

### 列表
- [close](#close)
- [setAutoDismiss](#setAutoDismiss)
- [setContent](#setContent)
- [setTitle](#setTitle)
- [setType](#setType)
- [show](#show)

-----------------------------------

### close
概要：`close()`

描述：关闭Hint视图

### setAutoDismiss
概要：`setAutoDismiss(flag)`

描述：设置Hint视图在显示后是否自动关闭

参数：
- flag(boolean)：是否开启

### setContent
概要：`setContent(str)`

描述：设置内容

参数：
- str(string)：要设置的内容

### setTitle
概要：`setTitle(str)`

描述：设置标题

参数：
- str(string)：要设置的标题

### setType
概要：`setType(type)`

描述：设置提示样式

参数：
- type(string)：要设置的样式，可选值有（warning | danger | success | info）

### show
概要：`show()`

描述：显示Hint视图，若开启了自动关闭功能，则会在一定时间后自行关闭
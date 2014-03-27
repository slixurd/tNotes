## 上传说明
1 Navbar模块直接调用了hintView以及setting（MODEL）
2 同步操作要通过router来调用folder以及note的collection
3 navbarView不提供接口获取session，而是通过setting（modal）的接口来获取当前用户的session
4 现在已经实现了了用户登录以及注册

##登录流程
上线先检测本地是否记录了用户密码，如果保存了且数据合法，则自动登录，成功以后保存服务器返回的session，否则不登陆


同步策略：
1 folder以及note模块维护一个记录，将需要更新，删除，增加的folder或者note保存在记录setting当中
2 同步时检测这个记录，获取到内容然后上传到服务器
3 每次上线会自动同步，之后间隔一定时间同步一次




#数据交换格式
无论是web端还是客户端统一采用JSON作为数据交换格式

与后台进行数据传输的时候发起GET/POST请求

可以先参考[JSON标准](http://www.json.org/json-zh.html),并找到对应需要的JSON解析库.(JS可以直接解析JSON,不需要另外使用JSON库)

##基本数据格式

###初始化所有数据

```
{
  'type':'init',
  'node':{
    'name':'current node name',
    'id':id,
    'child':[
    	{
        'name':'child name',
        'id':'id'
        'child':null
      },{
        'name':'child name',
        'id':id
        'child':[
        	{...},{...}
        ]
      }
    ]
  }
  'article':[
    {
      'name':'name',
      'id':id,
      'location':nodeId,
      'content':"content"
    },{
     ...
    }
  
  ]
}
```
###提交用户注册信息
提交URL:未定

不采用JSON,直接通过表单进行数据POST.需要两个值,username以及pass

###提交用户登陆信息
提交URL:未定

同上,不采用JSON,直接通过表单进行数据POST.需要两个值,username以及pass

###临时备份单条笔记数据
隔固定时间段自动上传备份数据

如果按下保存按钮的时候,需要额外发送一条消息清空备份条目
###保存结点创建数据
每次新建结点的同时就提交创建信息
###保存单条笔记数据
在切换到其他笔记的时候,提醒是否要保存.避免同时编辑多个文件的问题

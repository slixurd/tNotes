#数据交换格式
无论是web端还是客户端统一采用JSON作为数据交换格式

与后台进行数据传输的时候发起GET/POST请求

可以先参考[JSON标准](http://www.json.org/json-zh.html),并找到对应需要的JSON解析库.(JS可以直接解析JSON,不需要另外使用JSON库)

##基本数据格式

###提交用户注册信息
提交URL:未定

不采用JSON,直接通过表单进行数据POST.需要两个值,username以及pass

返回数据:
```
{
	'status':'status'
  //有以下几种状态:1."user_name_not_unique",用户名已被占用
  //2.success.注册成功
  //本地还需要判断没有网络响应的情况
}
```

###提交用户登陆信息
提交URL:未定

同上,不采用JSON,直接通过表单进行数据POST.需要两个值,username以及pass

```
{
	'status':'status'
  //有以下几种状态:1."pass_wrong",密码不匹配
  //2.success.登陆成功
}
```

###初始化所有数据
请求URL:
这里需要考虑一次性传输所有数据,数据量太大的问题

采用一次性初始化所有目录结构.笔记一次取出前N个字作为brief,其余的在点击的时候加载.

客户端可以继续轮询读取所有的笔记内容

```
{
  
  'node':[
    {
      'name':"name",
      'id':id
    },{
      'name':"name",
      'id':id
    },{
     ...
    }
  ],
  'article':[
    {
      'name':"name",
      'id':id,
      'time':"time"
      'location':nodeId,
      'brief':"short brief here"
    },{
     ...
    }
  ]
}
```
###拉取笔记
提交URL:
```
//提交数据.可以一次请求多条,例如点开笔记发现没有下载,现场拖笔记到本地,又例如客户端初始化之后,隔一段时间一次拉取10条,直到下载全部数据.这里数量需要有上限.否则数据量一样太大.
{
  'articleId':[
  	id1,id2,id3
  ]
}
```
> 用途:

> 1.继续下载没有下载的文章


```
{
  'article':[
    {
      'name':"name",
      'id':id,
      'time':"time"
      'location':nodeId,
      'content':"content"
    },{
    	...
    }
  ]

}
```
###临时备份单条笔记数据
隔固定时间段自动上传备份数据
```
//提交格式
{
  'article':
   {
     'name':"name",
     'id':id,
     'location':nodeId,
     'content':"content"
   }
}
```

###创建笔记
创建一次提交一次请求.如果当前没有网络就随后提交

如果遇到结点和笔记都同时创建的情况.请务必先创建结点!!!并且在收到服务器返回信息以后再上传笔记.否则结点数据会出错!!!
```
//请求数据
{
  'create':'article',
  'content':'content here',
  'createTime':'time_stamp',  //最后保存仅为服务器时间.本地时间要加上时间差
  'currentTime':'time_stamp' //用于正确匹配时间.提供时间差
  'nodeId':nodeId
}
//返回数据
{
  'create':'article',
  'status':'success',
  'id':id,
  'createTime':'time_stamp'
}

```

###保存单条笔记
web不提供一次性编辑多条的功能.切换到其他笔记的时候提示保存当前笔记,否则丢失数据

客户端自行解决.反正这边只提供保存单条笔记的接口.此外保存的时候会清空临时保存的数据
```
{
  'article':
   {
     'name':"name",
     'id':id,
     'location':nodeId,
     'content':"content"
   }
}
```



###创建结点
每次新建结点的同时就提交创建信息.一个结点作一次请求发送,接收到id以后客户端/web端各自保存数据
```
//提交格式
{
  'create':'node',
  'name':'node name here'
}
//返回格式
{
  'create':'node',
  'status':'success',
  'time':'SERVER_TIME_STAMP',
  'id':nodeId,
}
```

###同步数据
全局同步
```
{
	//等先做完前面再来做这里吧= =

}
```

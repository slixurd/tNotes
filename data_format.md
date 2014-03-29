#数据交换格式#

web端和客户端统一采用JSON作为数据交换格式

与后台进行数据传输的时候向后台CGI接口POST数据


##基本数据格式定义##


**文中所有SERVER_TIME_STAMP在C++中定义为unsigned int**

**所有id相关在C++中定义为unsigned int**

**其他Json结构类型为string**


###0. 定义服务器异常返回###
向服务器POST数据时，当所发送数据有误或因服务器原因无法处理时，服务器会将异常返回。
服务器异常返回格式，如下

	{
		"exception":"exception description"	
	}


exception description所有类型：

1. "Undefined Exception" 未定义的错误。
1. "Unimplemented Method" 服务器上相应接口未实现 
1. "Incorrect URL" 访问了错误的URL
1. "Incorrect Data Format" 错误的Json数据格式 
1. "Session Failure" 无效的Session
1. "Article Handling Failure" 处理文章失败，一般是增/删/改发生失败，如文章不存在
1. "Node Handling Failure" 处理目录失败，同上


>每个cgi接口都可能返回异常提示
>
>建议对服务器返回先检查Json有没有exception这个值，判断session是不是有效或者有无其他异常发生


###1. 用户注册###

>URL: host/signup.cgi

使用如下数据结构：

	{
		"user":"user",
  		"pass":"pass"
	}

返回数据:

	{
		"status":"status"
	}
	//"status"
	//1."success",注册成功
	//2."used_username",用户名被占用


###2.用户登陆###

>URL: host/signin.cgi

使用如下数据结构：

	{
		"user":"user",
  		"pass":"pass"
	}


返回数据：

	{
		"status":"status"
		"session":"session key"
	}
	//"status"
	//1."success",登陆成功
	//2."incorrect_password",密码错误
	//"session"字符串
	//用于标示已登录用户，除signup和signin接口，其他接口的Json数据中必须包含session

> 客户端/web需保存session key，
> 后面每此通讯里面的Json都必须有session来标示登录用户。


###3.用户登出###

>URL: host/signout.cgi

登出时，发送

	{
  		"session":"session key"
	}

返回数据：

	{
		"status":"status"
	}
	//"status"
	//1."success",登出成功


###4.请求目录###

>URL: host/fetchnodes.cgi 

取得根节点下所有的文件夹节点

发送

	{
	  	"session":"session key"
	}

返回数据:

	{
		"node":[
		    {
		      "id":id,
		      "name":"name",
			  "stamp":SERVER_TIME_STAMP,
		    },{
		      "id":id
		      "name":"name",
			  "stamp":SERVER_TIME_STAMP,
		    },
		     ...
	  ]
	}
	//"stamp"：服务器时间戳，指示服务器最后一次的修改时间


###5.请求某一目录下所有文件名及摘要等信息###

>URL：host/fetchbriefs.cgi 

取得"id"为node_id的目录下所有文件名及摘要等信息

发送

	{
	  	"session":"session key",
		"id":node_id	
	}

返回数据:
	
	{
	 "article":[
	    {
	      "id":id,
	      "name":"name",
	      "stamp":SERVER_TIME_STAMP,
	      "location":nodeId,
	      "brief":"short brief here"
	    },{
	      "id":id,
	      "name":"name",
	      "stamp":SERVER_TIME_STAMP,
	      "location":nodeId,
	      "brief":"short brief here"
	    },
		 ...
	  ]
	}
	//"stamp"：服务器时间戳，指示服务器最后一次的修改时间
	//"location":指示位于哪个目录下
	//"brief"：二十字的摘要


###6.请求指定id的文章全文###

>URL：host/fetcharticles.cgi 

取得指定id的文章全文，id可以同时传送多个

发送：

	{
	  	"session":"session key",
		"id":[id1,id2,id3,...]
	}

返回数据:

	{
	 "article":[
	    {
	      "id":id,
	      "name":"name",
	      "stamp":SERVER_TIME_STAMP,
	      "location":nodeId,
	      "content":"content"
	    },{
	      "id":id,
	      "name":"name",
	      "stamp":SERVER_TIME_STAMP,
	      "location":nodeId,
	      "content":"content"
	    },
		 ...
	  ]
	}
	//"stamp"：服务器时间戳，指示服务器最后一次的修改时间
	//"location":指示位于哪个目录下
	//"content":文章正文

###7.新建目录###

>URL：host/createnode.cgi 

新建目录

发送：

	{
	  	"session":"session key",
		"name":"node name"
	}

成功时返回数据：

*（不成功时，返回Node Handling Failure异常状态）*
	
	{
		"id":node_id,
		"stamp":SERVER_TIME_STAMP
	}

###8.删除目录###

>URL：host/deletenode.cgi 

删除目录

发送：

	{
	  	"session":"session key",
		"id":node_id
	}

成功时返回数据：

*（不成功时，返回Node Handling Failure异常状态）*
	
	{
		"status":"status"
	}
	//"status"
	//1."success",删除成功


###9.修改目录名称###

>URL：host/changenode.cgi 

将id为node_id的目录名改为"node name"

发送：

	{
	  	"session":"session key",
		"id":node_id，
		"name":"node name"
	}

成功时返回数据：

*（不成功时，返回Node Handling Failure异常状态）*
	
	{
		"stamp":SERVER_TIME_STAMP
	}


###10.新建笔记###

>URL：host/createarticle.cgi 

新建文章。

发送：

	{
	  "session":"session key",
	  "name":"article name",
	  "content":"article content",
	  "location":nodeId
	}

成功时返回数据：

*（不成功时，返回Article Handling Failure异常状态）*

	{
		"id":article_id,
		"stamp":SERVER_TIME_STAMP
	}

###11.删除笔记###

>URL：host/deletearticle.cgi 

删除指定id文章

发送：

	{
	  "session":"session key",
	  "id":article_id,
	}

成功时返回数据：

*（不成功时，返回Article Handling Failure异常状态）*

	{
		"status":"status"
	}
	//"status"
	//1."success",修改成功


###12.修改笔记###

>URL：host/changearticle.cgi 

修改指定id文章，包括保存文章内容、修改名称、移动文章等等

发送：

	{
	  "session":"session key",
	  "id":article_id,
	  "name":"article name",
	  "content":"article content",
	  "location":nodeId
	}
	//"name"，"content"，"location"，只发送要修改的，不修改的不要发送字段。

例如，改名，发送：

	{
	  "session":"session key",
	  "id":article_id,
	  "name":"article name"
	}

成功时返回数据：

*（不成功时，返回Article Handling Failure异常状态）*

	{
		"stamp":SERVER_TIME_STAMP
	}




###13.同步协议待定###

>URL:host/sync.cgi

同步

发送：

    {
        "node":[
                {
                    "id":id,
                    "stamp":SERVER_TIME_STAMP
                },
                {
                    "id":id,
                    "stamp":SERVER_TIME_STAMP
                },
                ...
            ],
       "article":[
                {
                    "id":id,
                    "stamp":SERVER_TIME_STAMP
                },
                {
                    "id":id,
                    "stamp":SERVER_TIME_STAMP
                },
                ...
       ]
    }
    
返回：

    {
        "deleted_node":[id1,id2,id3,...],
        "changed_node":[id1,id2,id3,...],
        "deleted_article":[id1,id2,id3,...],
        "changed_article:[id1,id2,id3,...]
    }

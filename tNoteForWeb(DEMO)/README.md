###tNotesForWeb

------------------------

该Demo采用*Bootstrap*作为前端框架，*Backbone*用于构建Javascript的MVC模式，*RequireJs*进行模块化的分割以及*JQuery*进行DOM操作。

其它使用的外部库列表如下：

* *underscore*：Backbone的依赖库，同时也使用了其所提供的模板方法。

* *backbone.localStorage*：Backbone的Localstorage存储支持。

* *backbone-indexeddb*：Backbone的IndexedDb存储支持。

* *showdown*：Markdown转化为HTML。

该Demo除了不支持同步外，其它大部分功能均已能够使用（导航栏不可用）。

###目录结构说明

-----------------------

CSS, JS, IMG分别放置相应的文件，主要是JS文件夹目录的划分。其中*Model*存放定义数据格式的Model类，*Collection*中存放Model的数据集合，*Lib*存放以上提到的所有外部库文件。*View*中存放Backbone中的视图类，分别控制页面的各个部分。*Database*中存放建立IndexedDb时的配置文件。Js根目录下的*Router*用于控制各个View之间的通信交互，*Util*提供一些公共方法。

基本上如果你已经了解了Backbone的使用方法，那就应该能很容易地知道目录为什么会进行划分。

###备注

-----------

Web端之后会采用分模块的方式进行编写，每个人都必须同时负责视图和Js的编写。基本的目录结构可能会进行部分更改，但大改动是不会有的。我会在这两天内根据后台那边最新定义的数据格式将文件目录结构再分一下，建立各个空的Js文件由每个人负责编写，并且必须提供该模块详细的API文档。

>  编写Markdown格式的说明文档时，可使用该Demo进行编写，通过使用以找出设计上不足的地方来。

> 最后祝大家编码愉快 ^_^
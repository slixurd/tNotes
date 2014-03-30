该目录基本与demo一致，只是将Router分为多个，每个View都有自己所属的Router，用于与其它的View交互。

为避免循环依赖，View可调用Collection和Model，Router可调用View。除非不得已，请不要在View模块中包含其它的View文件。

js/util文件夹存放的是其它功能模块，如果你们自己想自行添加一些可用模块的话，请先暂时扔到这里去==

> PS: 在模块中使用变量时，必须先声明再使用，以免模块间产生全局变量并相互造成影响，尽管在本项目中发生概率极小。
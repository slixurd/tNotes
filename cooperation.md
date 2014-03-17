##git合作流程

1.首先你要有一个github账号,账号给我加入collaborators,这个自己注册.然后你需要一个git cli客户端,以下所有命令针对命令行
只用客户端的自行查找对应命令

2.
签出当前git仓库
```
git clone https://github.com/slixurd/tNotes.git 

```
本地保存自己的账号和用户名,这样commit的用户名才会记录在log里
```
git config --global user.name "your github name here"
git config --global user.email "your github email here"
```
如果希望可以直接提交push,还需要在自己的机器上生成SSH_KEY,然后将公钥写入github账号中

设置在 [github setting](https://github.com/settings/ssh) 中.教程在 [Generating SSH Keys](https://help.github.com/articles/generating-ssh-keys)上,根据自己电脑的操作系统选择.


3.然后每个小组切换到自己的branch下工作

首先需要创建一个和远程分支同名的本地分支,例如web

```
git branch -r //查看所有远程分支
git checkout -b web origin/web
```

除了master分别有3个分支.web/client/server.建立了本地分支以后,可以随意切换分支,例如切换到web分支下
```
git checkout web
```
但是开发要求在自己的分支下进行,web的就在web分支下开发.客户端和后台请不要提交可执行文件和中间文件到git上

然后可以开始进行文件的添加和修改,这个根据个人习惯.文件尽量不要有中文名.

当觉得一个功能写完的时候,可以进行提交.还是以web分支为样例
```
git add . //'.'和add有空格.这个表示递归添加当前所有目录(当然要在工作目录下)
git commit -m "提交消息,可以中文,可以英文"
git push origin web //将本地web分支推送到github上的origin仓库上
//如果提示already up-date.说明你要么没提交commit,要么你弄错分支了.直接在当前分支执行git reset/stash恢复之前的版本(自行备份)
```
关于分支更详细的内容可以查看[git-scm](http://git-scm.com/book/zh/Git-%E5%88%86%E6%94%AF-%E8%BF%9C%E7%A8%8B%E5%88%86%E6%94%AF)

4.同步他人内容.

因为别人也同时在提交代码.在本地需要经常`git pull`来同步代码.不带参数的pull表示默认同步所有远程分支.基本这条就足够了.不需要手动指定分支.


同步就会带来冲突的问题,没有冲突默认显示fast-forward,如果刚好编辑了同一个文件,本地又比远程更新的慢,那很大几率发生conflict.可以参考 [git-scm](http://git-scm.com/book/zh/Git-%E5%88%86%E6%94%AF-%E5%88%86%E6%94%AF%E7%9A%84%E6%96%B0%E5%BB%BA%E4%B8%8E%E5%90%88%E5%B9%B6)

基本流程如下
```
git status //查看哪个文件被多人修改
git diff //查看被修改的地方.然后手动修改后再add,commit,push
git mergetool //也可以直接采用工具合并

```

最后当我们的demo已经完成的时候,由我来将3个分支统一合并到master上.

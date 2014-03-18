# A How-to: Things about Nginx & FastCGI #

文档主要记录如何在ubuntu中安装使用Nginx+FastCGI。

## 1.安装 ##

### 1.1 安装Nginx ###

可使用apt-get安装Nginx：

    % apt-get install nginx

发现apt-get的Nginx版本较低，为1.1.19。 故从[官网](http://nginx.org/cn/)下载安装。

* Ngnix 	[Download](http://nginx.org/en/download.html)

还需要的库文件,包括以下： 

* PCRE		[Download](http://sourceforge.net/projects/pcre/files/pcre/)
* zlib		[Download](http://www.zlib.net/)
* openssl	[Download](https://www.openssl.org/source/)

先编译安装依赖的库文件，再编译Nginx，按默认路径安装。

    % ./configure
    % make
    % make install

### 1.2 安装spawn-fcgi ###

下载spawn-fcgi。

* spawn-fcgi [Download](https://github.com/lighttpd/spawn-fcgi)

同样。

    % ./configure
    % make
    % make install

### 1.3 安装FastCGI #

下载FastCGI库。

* FastCGI [Download](http://www.fastcgi.com/drupal/node/5)

同样。

    % ./configure
    % make
    % make install
		

## 2.测试 ##

### 2.1 测试Nginx ###

运行Nginx。

    % /usr/local/nginx/sbin/nginx

打开浏览器，访问 `http://127.0.0.1` ，正常应返回页面。

**Welcome to nginx！**	

### 2.2 测试FastCGI ###


创建文件`testFastCGI.cpp`，写入如下:

代码来自文档[FastCGI Developer's Kit](http://www.fastcgi.com/drupal/node/6?q=node/21#S3.1)

    #include "fcgi_stdio.h"
    #include <stdlib.h>

    void main(void)
    {
        int count = 0;
        while(FCGI_Accept() >= 0)
        printf("Content-type: text/html\r\n"
                        "\r\n"

                        "<title>FastCGI Hello!</title>"
                        "<h1>FastCGI Hello!</h1>"
                        "Request number %d running on host <i>%s</i>\n",
                        ++count, getenv("SERVER_NAME"));
    }

编译代码：

    % g++ testFastCGI.cpp -o testFastCGI -lfcgi

测试程序是否可正常运行。

### 2.2 配置测试spawn-fastcgi ###

启动spawn-fastcgi。

    % /usr/local/bin/spawn-fcgi -a 127.0.0.1 -p 9002 -C 25 -f testFastCGI

在Nginx配置文件中添加cgi配置，如下：

    location ~ \.cgi$ {
        fastcgi_pass 127.0.0.1:9002;
        fastcgi_index index.cgi;
        fastcgi_param SCRIPT_FILENAME fcgi$fastcgi_script_name;
        include fastcgi_params;
    }

重启nginx，打开`http://127.0.0.1/test.cgi`，测试是否正确运行。

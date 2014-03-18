/*
     后台操作类 Operation
     包含增，删，查操作
*/
#include "json/json.h"
#include "Article.h"
#include "Directory.h"
#include<vector>
#include<algorithm>
#ifndef OPERATION_H
#define OPERATION_H
bool createRoot(Directory dir);        //创建目录，传入目录类
bool createArticle(string iRoot,Article art);     //创建文章，传入目录索引和文章类
bool deleteRoot(string index);         //删除目录，传入目录索引
bool deleteArticle(string iRoot,string iArticle); //删除文章，传入目录和文章索引
vector<Directory> searchAllRoot();//查找所有目录，返回目录列表
vector<Article> searchRootArticle(string iRoot);  //查找某个目录下所有文章，传入目录索引，返回文章列表
vector<Article> searchAllArticle();  //返回所有文章
Article searchArticle(string iRoot,string iArticle);  //查找某个目录下特定文章，传入目录和文章索引，返回文章类
Json::Value returnRoot();  //返回json整个文件，若文件不存在，返回null
bool writeInJson(Json::Value root);         //写入json文件
#endif
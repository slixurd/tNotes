/*
     后台操作类 Operation
     包含增，删，查操作
*/
#include "json/json.h"
#include "Article.h"
#include "Directory.h"
#include<vector>
#include <Qstring>
#include<algorithm>
#include<iostream>
#include<mynetworker.h>
#ifndef OPERATION_H
#define OPERATION_H
//const string rootPath="D:/data/";
void setupRootPath(string username);
bool createRoot(Directory dir);        //创建目录，传入目录类
bool changeRoot(string iRoot ,string name);        //目录重命名，传入目录id和新目录名
bool createArticle(string iRoot,Article art);     //创建文章，传入目录索引和文章类，
bool changeArticleName(string iRoot,string iArticle,string name);//修改文章标题
bool changeArticleContent(string iRoot,string iArticle,string content); //修改文章内容
bool deleteRoot(string index);         //删除目录，传入目录索引
bool deleteArticle(string iRoot,string iArticle); //删除文章，传入目录和文章索引
vector<Directory> searchAllRoot();//查找所有目录，返回目录列表
vector<Article> searchRootArticle(string iRoot);  //查找某个目录下所有文章，传入目录索引，返回文章列表
vector<Article> searchAllArticle();  //返回所有文章
Article searchArticle(string iRoot,string iArticle);  //查找某个目录下特定文章，传入目录和文章索引，返回文章类,若找不到返回一个空对象。
Json::Value returnRoot(string path);  //返回json整个文件，若文件不存在，返回null
bool writeInJson(Json::Value root,string path);         //写入json文件
void getArticlePath(string articleId);//返回文章路径

struct SearchResult{
    string dirId;
    Article article;
};
vector<SearchResult> searchRequestedArticles(vector<string>); //返回文章搜索结果
QString s2q(const string &s);
string q2s(const QString &s);
unsigned int s2i(string ss);
string i2s(unsigned int ss);
bool mysetFind(string id);
void print(QString s);
QString readFile(QString filePath);
bool changeRootId(string oldId,string newId,string modifiedTime); //修改原目录id与时间戳
bool changeArticleId(string rootid,string oldId,string newId,string modifiedTime); //修改原文章id与时间戳
//void synchronous();   //同步操作
void stdstring2charstar(std::string, char *);
void tmpstring2charstar(std::string, char *);
#endif

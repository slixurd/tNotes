/*
     文章类 Article
     包含所需要数据
*/
#include<string>
using namespace std;
#ifndef ARTICLE_H
#define ARTICLE_H
class Article
{
public:
    string articleId;                //文章id,与服务器同步使用
    string name;                     //文章标题
    string context;                  //文章内容
    string createTime;               //文章创建时间
    string modifiedTime;             //文章修改时间
    Article(string articleId,string name,string context,string createTime,string modifiedTime)
    {
        this->articleId=articleId;
        this->name=name;
        this->context=context;
        this->createTime=createTime;
        this->modifiedTime=modifiedTime;
    }
    ~Article(){}
};
#endif
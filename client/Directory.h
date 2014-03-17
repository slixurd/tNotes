/*
     目录类 Directory
     包含所需要数据
*/
#include<string>
using namespace std;
#ifndef DIRECTORY_H
#define DIRECTORY_H
class Directory
{
public:
    string nodeId;                  //目录id,与服务器同步使用
    string name;                    //目录名称
    string createTime;              //目录创建时间
    string modifiedTime;             //目录修改时间
    Directory(string nodeId,string name,string createTime,string modifiedTime)
    {
    this->nodeId=nodeId;
    this->name=name;
    this->createTime=createTime;
    this->modifiedTime=modifiedTime;
    }
    ~Directory(){}
};
#endif
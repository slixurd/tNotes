#include "Operation.h"
#include<fstream>
/************************************************************************/
/* 打开json文件，返回json根                                                                     */
/************************************************************************/
Json::Value returnRoot()
{
    Json::Reader reader;
    Json::Value root;
    ifstream ifs;
    ifs.open("tnote.json");
    reader.parse(ifs,root);
    if(ifs.is_open())
    {
         ifs.close();       
    }
    return root;
}

/************************************************************************/
/* 将json树写入json文件，若文件不存在，则创建一个新文件，工作目录下命名为"tnote.json"                                                                     */
/************************************************************************/
bool writeInJson(Json::Value root)
{
    Json::FastWriter writer;
    ofstream ofs;
    ofs.open("tnote.json");
    if(ofs.is_open())
    {
        string json_file = writer.write(root);
        ofs<<json_file;
        ofs.close();
        return 1;
    }
    return 0;
}

/************************************************************************/
/* 创建新目录，传入目录类，以目录id作为索引，离线编辑时以客户端时间戳作为id，
   若在线编辑，向服务器申请id，时间戳
   操作成功返回1，否则返回0*/
/************************************************************************/
bool createRoot(Directory dir)
{
    Json::Value root=returnRoot();
    Json::Value d;
    d["name"] = dir.name;
    d["createTime"] = dir.createTime;
    d["modifiedTime"]=dir.modifiedTime;
    d["isSyn"]=dir.isSyn;
   
    
    root[dir.nodeId]=d;
    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* 新建文章，传入目录ID和文章类
新建文章只需将前台该文章信息封装成一个类作为参数即可
操作成功返回1，否则返回0
*/
/************************************************************************/
bool createArticle(string iRoot,Article art)
{
    Json::Value root=returnRoot();
    Json::Value a;


    a["context"] = art.context;
    a["name"] = art.name;
    a["createTime"] = art.createTime;
    a["modifiedTime"]=art.modifiedTime;
    a["isSyn"]=art.isSyn;

    root[iRoot]["array"][art.articleId]=a;

    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* 删除目录，传入目录ID，删除该目录及目录下所有文章，操作成功返回1，否则返回0                                                                     */
/************************************************************************/
bool deleteRoot(string index)
{
    Json::Value root=returnRoot();
    
    root.removeMember(index);
    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* 删除指定目录下特点文章，传入目录ID，文章ID   
   操作成功返回1，否则返回0*/
/************************************************************************/
bool deleteArticle(string iRoot,string iArticle)
{
    Json::Value root=returnRoot();

    root[iRoot]["array"].removeMember(iArticle);


    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* 查找所有目录信息，返回目录列表，若不存在目录，则返回一个空列表                                                                     */
/************************************************************************/
vector<Directory> searchAllRoot()
{
    Json::Value root=returnRoot();
    vector<string> listRoot=root.getMemberNames();
    vector<Directory> allRoot;
    Directory obj;
    string nodeId;
    for(int i=0;i<(int)listRoot.size();i++)
    {
        nodeId=listRoot[i];
        obj.nodeId=nodeId;
        obj.createTime=root[nodeId]["createTime"].asString();
        obj.name=root[nodeId]["name"].asString();
        obj.modifiedTime=root[nodeId]["modifiedTime"].asString();
        obj.isSyn=root[nodeId]["isSyn"].asBool();
        allRoot.push_back(obj);
    }

    return allRoot;
}

/************************************************************************/
/* 查找特定目录下所有文章，传入目录ID，返回文章列表，若该目录下无文章，返回一个空列表                                                                     */
/************************************************************************/
vector<Article> searchRootArticle(string iRoot)
{
    Json::Value root=returnRoot();
    Json::Value allArticle=root[iRoot]["array"];
    vector<string> listRootArticle=allArticle.getMemberNames();
    vector<Article> allRootArticle;
    Article obj;
    string articleId;
    for(int i=0;i<(int)listRootArticle.size();i++)
    {
        articleId=listRootArticle[i];
        obj.articleId=articleId;
        obj.createTime=allArticle[articleId]["createTime"].asString();
        obj.name=allArticle[articleId]["name"].asString();
        obj.modifiedTime=allArticle[articleId]["modifiedTime"].asString();
        obj.isSyn=allArticle[articleId]["isSyn"].asBool();
        obj.context=allArticle[articleId]["context"].asString();
        allRootArticle.push_back(obj);
    }

    return allRootArticle;
}

/************************************************************************/
/* 查找所有文章，前台搜索调用，返回所有文章列表，若无文章，返回空队列                                                                     */
/************************************************************************/
vector<Article> searchAllArticle()
{
    Json::Value root=returnRoot();
    vector<string>listRoot=root.getMemberNames();
    vector<Article>allArticle;
    vector<Article>rootArticle;
    vector<Article>::iterator it;
    for(int i=0;i<(int)listRoot.size();i++)
    {
        it=allArticle.end();
        rootArticle=searchRootArticle(listRoot[i]);
        allArticle.insert(it,rootArticle.begin(),rootArticle.end());

    }
 
    return allArticle;
}

/************************************************************************/
/* 查找特定目录下特定文章，传入目录ID和文章ID，返回文章类，若无该文章，返回空对象                                                                     */
/************************************************************************/
Article searchArticle(string iRoot,string iArticle)
{
    Json::Value root=returnRoot();
    Json::Value art=root[iRoot]["array"][iArticle];
    Article article;
    if(!art.isNull())
    {
       
        article.articleId=iArticle;
        article.context=art["context"].asString();
        article.name=art["name"].asString();
        article.createTime=art["createTime"].asString();
        article.modifiedTime=art["modifiedTime"].asString();
        article.isSyn=art["isSyn"].asBool();
      
    }
    return article;
}

/************************************************************************/
/* 修改目录,包括目录名，ID，时间戳。 
   传入原目录ID和新目录类
   若查找到原目录，则返回1，否则返回0
*************************************************************************/
bool changeRoot(string iRoot ,Directory dir)
{
    Json::Value root=returnRoot();
    Json::Value obj=root[iRoot];
    if(!obj.isNull())
    {
        
        obj["name"]=dir.name;
        obj["createTime"]=dir.createTime;
        obj["isSyn"]=dir.isSyn;
        obj["modifiedTime"]=dir.modifiedTime;       
        if(dir.nodeId!=iRoot)
        {
            root.removeMember(iRoot);
           
        }
        root[dir.nodeId]=obj;
        writeInJson(root);
        return 1;
    }
    else return 0;
   
}

/************************************************************************/
/* 修改文章,包括文章名，ID，时间戳，内容。 
   传入原文章所属目录ID和原文章ID和新文章类
   若查找到原文章，则返回1，否则返回0
*************************************************************************/
bool changeArticle(string iRoot,string iArticle,Article art)
{
    Json::Value root=returnRoot();
    Json::Value obj=root[iRoot]["array"][iArticle];
    if(!obj.isNull())
    {
       
        obj["name"]=art.name;
        obj["context"]=art.context;
        obj["createTime"]=art.createTime;
        obj["isSyn"]=art.isSyn;
        obj["modifiedTime"]=art.modifiedTime;
        if(iArticle!=art.articleId)
        {
            root[iRoot]["array"].removeMember(iArticle);
        }
        root[iRoot]["array"][art.articleId]=obj;
        writeInJson(root);
        return 1;
    }
    else return 0;
   
}

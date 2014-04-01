#include "synchronization.h"
#include "mynetworker.h"
#include "Operation.h"
#include <QtNetwork>
#include <QEventLoop>
#include <QDebug>
#include<locale.h>

synchronization::synchronization(QObject *parent) :
    QObject(parent)
{
    this->mynetwork=new MyNetWorker();
    connect(this->mynetwork->manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinished(QNetworkReply*)));
}

void synchronization::sendrecord()
{
    extern string recordPath;

    Json::Value recordRoot=returnRoot(recordPath);
    int mark;
    int size=recordRoot.size();
    map<string,string>mymap;
    map<string,string>::iterator iter;

    for(int i=0;i<size;i++)
    {
    mark=recordRoot[i]["mark"].asInt();
        switch(mark)
        {
        case 1:
        {

//            connect(this->mynetwork->manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
            string url="http://tnotes.wicp.net:8080/createnode.cgi";

            Json::Value obj;
            obj["session"]=MyNetWorker::session_key.toStdString();
            obj["name"]=recordRoot[i]["name"];
            std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();

            Json::Reader reader;
            Json::Value value;
            reader.parse(data,value);
            std::cout<<value.toStyledString();
            changeRootId(recordRoot[i]["id"].asString(),i2s(value["id"].asUInt()),i2s(value["stamp"].asUInt()));
            mymap[recordRoot[i]["id"].asString()]=i2s(value["id"].asUInt());
            break;
        }
        case 2:
        {
            string url="http://tnotes.wicp.net:8080/deletenode.cgi";
            Json::Value obj;
           obj["session"]=MyNetWorker::session_key.toStdString();
            string id=recordRoot[i]["id"].asString();
            iter=mymap.find(id);
            if(iter!=mymap.end())
            {
            id=iter->second;
            }
            obj["id"]=s2i(id);
           // std::cout<<obj["id"].asUInt()；
              std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();
            std::cout<<data;
            break;
        }
        case 3:
        {
            string url="http://tnotes.wicp.net:8080/changenode.cgi";
            Json::Value obj;
            obj["session"]=MyNetWorker::session_key.toStdString();
            string id=recordRoot[i]["id"].asString();
            iter=mymap.find(id);
            if(iter!=mymap.end())
            {
            id=iter->second;
            }
            obj["id"]=s2i(id);
            obj["name"]=recordRoot[i]["name"];
              std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
            reader.parse(data,value);
            changeRootId(id,id,i2s(value["stamp"].asUInt()));
              std::cout<<value.toStyledString();
           // std::cout<<obj.toStyledString()<<std::endl;
            break;
        }
        case 4:
        {
            string url="http://tnotes.wicp.net:8080/createarticle.cgi";
            Json::Value obj;
            obj["session"]=MyNetWorker::session_key.toStdString();
            string iroot=recordRoot[i]["location"].asString();
            iter=mymap.find(iroot);
            if(iter!=mymap.end())
            {
            iroot=iter->second;
            }
            string iarticle=recordRoot[i]["id"].asString();
            Article art=searchArticle(iroot,iarticle);
            obj["content"]=art.context;
            obj["location"]=s2i(iroot);
            obj["name"]=art.name;
              std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
            reader.parse(data,value);
          std::cout<<value.toStyledString();
            changeArticleId(iroot,iarticle,i2s(value["id"].asUInt()),i2s(value["stamp"].asUInt()));
            mymap[recordRoot[i]["id"].asString()]=i2s(value["id"].asUInt());
            break;
        }

        case 5:
        {
           string  url="http://tnotes.wicp.net:8080/deletearticle.cgi";
            Json::Value obj;
           obj["session"]=MyNetWorker::session_key.toStdString();

           string id=recordRoot[i]["id"].asString();
           iter=mymap.find(id);
           if(iter!=mymap.end())
           {
           id=iter->second;
           }
           obj["id"]=s2i(id);
  std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();
  std::cout<<data;
          //  std::cout<<obj.toStyledString()<<std::endl;
            break;
        }
        case 6:
        {
            string url="http://tnotes.wicp.net:8080/changearticle.cgi";
            Json::Value obj;
            obj["session"]=MyNetWorker::session_key.toStdString();

            string iarticle=recordRoot[i]["id"].asString();
            string iroot=recordRoot[i]["location"].asString();
            iter=mymap.find(iroot);
            if(iter!=mymap.end())
            {
            iroot=iter->second;
            }
            obj["id"]=s2i(iarticle);
            Article art=searchArticle(iroot,iarticle);

             obj["name"]=art.name;


             obj["content"]=art.context;

            std::cout<<obj.toStyledString()<<endl;
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
             reader.parse(data,value);
               std::cout<<value.toStyledString();
           // std::cout<<obj.toStyledString()<<std::endl;
            changeArticleId(iroot,iarticle,iarticle,i2s(value["stamp"].asUInt()));
            break;
        }
        }

    }
    recordRoot.clear();
    writeInJson(recordRoot,recordPath);
    mymap.clear();


}
void synchronization::receiveData()
{
    extern string rootPath;
    extern string articlePath;
    Json::Value obj;
    obj["session"]=MyNetWorker::session_key.toStdString();
    Json::Value dir;
    Json::Value art;
    vector<Directory>alldir=searchAllRoot();
    for(int i=0;i<alldir.size();i++)
    {
        Json::Value d;
        d["id"]=s2i(alldir[i].nodeId);
        d["stamp"]=s2i(alldir[i].modifiedTime);
        dir.append(d);
    }
    obj["node"]=dir;
    vector<Article>allart=searchAllArticle();
    for(int i=0;i<allart.size();i++)
    {
        Json::Value a;
        a["id"]=s2i(allart[i].articleId);
        a["stamp"]=s2i(allart[i].modifiedTime);
        art.append(a);
    }
    obj["article"]=art;
     string url="http://tnotes.wicp.net:8080/dummysync.cgi";
     mynetwork->send(url,obj.toStyledString());
     eventLoop.exec();
     Json::Reader reader;
     Json::Value value;
     reader.parse(data,value);
     Json::Value root=returnRoot(rootPath);
     vector<string>rootid=root.getMemberNames();
     //删除文章
     Json::Value deleted_article=value["deleted_article"];

     for(int i=0;i<deleted_article.size();i++)
     {
         for(int j=0;j<rootid.size();i++)
         {
             string deletedid=i2s(deleted_article[i].asUInt());

             if(!root[rootid[j]]["array"][deletedid].isNull())
             {
             root[rootid[j]]["array"].removeMember(deletedid);
             getArticlePath(deletedid);
             remove(articlePath.c_str());
             break;
             }

         }
     }
     //删除目录
     Json::Value deleted_node=value["deleted_node"];
     for(int i=0;i<deleted_node.size();i++)
     {
     root.removeMember(i2s(deleted_node[i].asUInt()));

     }
      //新增目录
     Json::Value changed_node=value["changed_node"];
     for(int i=0;i<changed_node.size();i++)
     {
         root[i2s(changed_node[i]["id"].asUInt())]["name"]=changed_node[i]["name"];
         root[i2s(changed_node[i]["id"].asUInt())]["modifiedTime"]=i2s(changed_node[i]["stamp"].asUInt());
     }

     //新增文章
    Json::Value changed_article=value["changed_article"];
    for(int i=0;i<changed_article.size();i++)
    {
        string nodeid=i2s(changed_article[i]["location"].asUInt());
        string articleid=i2s(changed_article[i]["id"].asUInt());

        Json::Value v;
        v["name"]=changed_article[i]["name"];
        v["modifiedTime"]=i2s(changed_article[i]["stamp"].asUInt());
        root[nodeid]["array"][articleid]=v;
        Json::Value content;
        content["context"]=changed_article[i]["content"];
        getArticlePath(i2s(changed_article[i]["id"].asUInt()));
        writeInJson(content,articlePath);
    }
    writeInJson(root,rootPath);
     emit updateListView();
}


void synchronization::replyfinished(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<status_code;

     QTextCodec * codec=QTextCodec::codecForName("UTF-8");
   //  QTextCodec * gbk=QTextCodec::codecForName("GBK");
   //  QTextCodec::setCodecForLocale(gbk);

    QString json= codec->toUnicode(reply->readAll());
  //  QString serstr=gbk->toUnicode(json.toLocal8Bit().data());
  // QTextCodec * gbk=QTextCodec::codecForName("gbk");
   // QTextCodec::codecForLocale(gbk);
   // QTextCodec::setCodecForLocale(gbk);

 //   QTextCodec::setCodecForCStrings(gbk);

    qDebug()<<json;
    data=json.toStdString();
   // data=json.toStdString();
    std::cout<<"data:"<<data;
    eventLoop.quit();
}

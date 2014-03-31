#include "synchronization.h"
#include "mynetworker.h"
#include "Operation.h"
#include <QtNetwork>
#include <QEventLoop>
#include <QDebug>


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
    //通知前台刷新一遍
    emit updateListView();
}



void synchronization::replyfinished(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<status_code;
    QTextCodec * codec=QTextCodec::codecForName("UTF-8");
    QString json=codec->toUnicode(reply->readAll());
    qDebug()<<json;
    data=json.toStdString();
    std::cout<<"data:"<<data;
    eventLoop.quit();
}

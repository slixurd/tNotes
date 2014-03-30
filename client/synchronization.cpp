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
            string url="tnotes.wicp.net:8080/createnode.cgi";
            Json::Value obj;
            obj["session"]=MyNetWorker::session_key.toStdString();
            obj["name"]=recordRoot[i]["name"];
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();
            Json::Reader reader;
            Json::Value value;
            reader.parse(data,value);
            changeRootId(recordRoot[i]["id"].asString(),i2s(value["id"].asUInt()),i2s(value["stamp"].asUInt()));
            mymap[recordRoot[i]["id"].asString()]=i2s(value["id"].asUInt());
            break;
        }
        case 2:
        {
            string url="tnotes.wicp.net:8080/deletenode.cgi";
            Json::Value obj;
            //obj["session"]=MyNetWorker::SessionKey;
            string id=recordRoot[i]["id"].asString();
            obj["id"]=s2i(findMymap(id));
           // std::cout<<obj["id"].asUInt()；
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();
            std::cout<<obj.toStyledString()<<std::endl;
            break;
        }
        case 3:
        {
            string url="tnotes.wicp.net:8080/changenode.cgi";
            Json::Value obj;
            //obj["session"]=MyNetWorker::SessionKey;
            string id=findMymap(recordRoot[i]["id"].asString());
            obj["id"]=s2i(id);
            obj["name"]=recordRoot[i]["name"];
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
            //reader.parse(data,value);
            changeRootId(id,id,i2s(value["stamp"].asUInt()));
           // std::cout<<obj.toStyledString()<<std::endl;
            break;
        }
        case 4:
        {
            string url="tnotes.wicp.net:8080/createarticle.cgi";
            Json::Value obj;
            //obj["session"]=MyNetWorker::SessionKey;
            obj["content"]=recordRoot[i]["content"];
            obj["location"]=s2i(recordRoot[i]["location"].asString());
            obj["name"]=recordRoot[i]["name"];
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
            //reader.parse(data,value);
          //  std::cout<<obj.toStyledString()<<std::endl;
            changeArticleId(recordRoot[i]["location"].asString(),recordRoot[i]["id"].asString(),i2s(value["id"].asUInt()),i2s(value["stamp"].asUInt()));
            mymap[recordRoot[i]["id"].asString()]=i2s(value["id"].asUInt());
            break;
        }

        case 5:
        {
           string  url="tnotes.wicp.net:8080/deletearticle.cgi";
            Json::Value obj;
            //obj["session"]=MyNetWorker::SessionKey;

            string id=recordRoot[i]["id"].asString();
            obj["id"]=s2i(findMymap(id));

            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();
          //  std::cout<<obj.toStyledString()<<std::endl;
            break;
        }
        case 6:
        {
            string url="tnotes.wicp.net:8080/changearticle.cgi";
            Json::Value obj;
            //obj["session"]=MyNetWorker::SessionKey;

            string id=findMymap(recordRoot[i]["id"].asString());
            obj["id"]=s2i(id);

            if(recordRoot[i].isMember("name"))
            {
                obj["name"]=recordRoot[i]["name"];
            }
            if(recordRoot[i].isMember("content"))
            {
                obj["content"]=recordRoot[i]["content"];
            }
            mynetwork->send(url,obj.toStyledString());
            eventLoop.exec();


            Json::Reader reader;
            Json::Value value;
           reader.parse(data,value);
           // std::cout<<obj.toStyledString()<<std::endl;
            changeArticleId(recordRoot[i]["location"].asString(),id,id,i2s(value["stamp"].asUInt()));
            break;
        }
        }

    }
    recordRoot.clear();
    writeInJson(recordRoot,recordPath);
    mymap.clear();
    //通知前台刷新一遍
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

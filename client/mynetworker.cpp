#include "mynetworker.h"
#include <QtNetwork>
#include <QTextCodec>
MyNetWorker::MyNetWorker(QObject *parent) :
    QObject(parent)
{
    manager=new QNetworkAccessManager();
//    connect(manager,SIGNAL(finished(QNetworkReply* )),this,SLOT(replyFinished(QNetworkReply* )));
}

//void MyNetWorker::replyFinished(QNetworkReply *reply)
//{
//    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
//    this->replyinformation=codec->toUnicode(reply->readAll());
//    emit replydone();
//    reply->deleteLater();
//}
//QString MyNetWorker::getreplyinformation()
//{
//    return this->replyinformation;
//}

QNetworkReply * MyNetWorker::get(const QString &url)
{
    return manager->get(QNetworkRequest(QUrl(url)));
}

QNetworkReply * MyNetWorker::post(const QNetworkRequest &request, const QByteArray &data)
{
    return manager->post(request,data);
}

//判断是否联网
bool MyNetWorker::isconnect()
{
    QHostInfo info=QHostInfo::fromName("tnotes.wicp.net");
    if(info.error()!=QHostInfo::NoError)
    {
        qDebug()<<"Lookup failed:"<<info.errorString();
        return false;
    }
    else
    {
        qDebug()<<"connected";
        return true;
    }
}

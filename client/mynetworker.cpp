#include "mynetworker.h"
#include <QtNetwork>
#include <QTextCodec>
#include <QTimer>

QString MyNetWorker::session_key="";
MyNetWorker::MyNetWorker(QObject *parent) :
    QObject(parent)
{
    manager=new QNetworkAccessManager();
    networkTimer = new QTimer();
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

void MyNetWorker::send(std::string url, std::string senddata)
{
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QString tmpdata=codec->toUnicode(senddata.c_str());
    QByteArray data;
    data.append(tmpdata);
    QNetworkRequest network_request;
    //设置头信息
    network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    network_request.setHeader(QNetworkRequest::ContentLengthHeader, data.length());
    //设置url
    network_request.setUrl(QUrl(url.c_str()));
    post(network_request,data);
}

void MyNetWorker::checkNetStateLoop()
{
    if(isconnect()){
        emit networkConnected();
        networkTimer->stop();
    } else {
        return;
    }
}

void MyNetWorker::setupNetworkTimer()
{
    //networkTimer = new QTimer;
    networkTimer->setInterval(10000);
    networkTimer->setSingleShot(false);
    networkTimer->start();
    connect(networkTimer, SIGNAL(timeout()), this, SLOT(checkNetStateLoop()));
}

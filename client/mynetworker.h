#ifndef MYNETWORKER_H
#define MYNETWORKER_H

#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;
class QNetworkRequest;

class MyNetWorker : public QObject
{
    Q_OBJECT
public:
    static QString session_key;
    explicit MyNetWorker(QObject *parent = 0);
    QString getreplyinformation();
    QNetworkReply * get(const QString &url);
    QNetworkReply * post(const QNetworkRequest & request, const QByteArray & data);
    QNetworkAccessManager *manager;
    //判断是否联网
    bool isconnect();
    void send(std::string url,std::string senddata);


signals:
public slots:
private:

private slots:
//    void replyFinished(QNetworkReply*);

};

#endif // MYNETWORKER_H

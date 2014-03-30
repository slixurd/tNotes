#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <QObject>
#include <QtGui>

enum RemoteRequest {
    createnode,
    deletenode,
    changenode,
    createarticle,
    deletearticle,
    changearticle
};

class MyNetWorker;
class QNetworkReply;

class synchronization : public QObject
{
    Q_OBJECT
public:
    explicit synchronization(QObject *parent = 0);
    void sendrecord();

signals:

public slots:
    void replyfinished(QNetworkReply *reply);
private:
    MyNetWorker *mynetwork;
    QMap<QNetworkReply*,RemoteRequest> replyMap;
    std::string data;
    QEventLoop eventLoop;
};

#endif // SYNCHRONIZATION_H

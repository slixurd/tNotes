#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <QObject>
#include <QtGui>

enum Remoterequest {
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
    void receiveData();



signals:
    void updateListView();
public slots:
    void replyfinished(QNetworkReply *reply);

private:
    MyNetWorker *mynetwork;
    QMap<QNetworkReply*,Remoterequest> replyMap;
    std::string data;
    QEventLoop eventLoop;

};

#endif // SYNCHRONIZATION_H

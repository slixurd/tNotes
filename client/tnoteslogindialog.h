#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtGui>
class QPushButton;
class QLabel;
class QComboBox;
class QDialogButtonBox;
class QLineEdit;
class QString;
class QTabWidget;
class MyNetWorker;
class QNetworkReply;
class QNetworkAccessManager;

enum RemoteRequest {
    login,
    regist
};

class tNotesLoginDialog : public QDialog
{
    Q_OBJECT

public:	
    tNotesLoginDialog(QWidget *parent = 0);
	void setUsername(QString &username);
	void setPassword(QString &password);
	void setUsernamesList(const QStringList &usernames);

private:
	QTabWidget *tabWidget;

	QWidget *loginWidget;
	QLabel *labelUsername;
	QLabel *labelPassword;

	QComboBox *comboUsername;
	QLineEdit *editPassword;

	QDialogButtonBox *loginButtons;
	QDialogButtonBox *registerButtons;

	QWidget *regWidget;
	QLabel *labelRegEmail;
	QLabel *labelRegUsername;
	QLabel *labelRegPassword;

	QLineEdit *editRegEmail;
	QLineEdit *editRegUsername;
	QLineEdit *editRegPassword;
    MyNetWorker *mynetwork;
    QMap<QNetworkReply *,RemoteRequest> replyMap;

	void setUpGUI();
	void setUpLoginGUI();
	void setUpRegGUI();
    void localAuth(QString, QString);
    void storeLocalUserInfo(QString, QString);
	
signals:
	void acceptLogin(QString &username, QString &password, int &indexNumber);
public slots:
	void slotAcceptReg();
	void slotAcceptLogin();
private slots:
    void replyfinished(QNetworkReply *reply);
};

#endif // LOGINDIALOG_H

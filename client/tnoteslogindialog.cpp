/*
 * =====================================================================================
 *
 *       Filename:  logindialog.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年03月19日 11时17分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QDebug>
#include <QTabWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextCodec>
#include <QtNetwork>
#include <QTextCodec>
#include "mynetworker.h"
#include <QMessageBox>

#include "tnoteslogindialog.h"

tNotesLoginDialog::tNotesLoginDialog(QWidget* parent)
	: QDialog(parent)
{
	setUpGUI();
	setWindowTitle(tr("User Login"));
	setModal(true);
    this->mynetwork=new MyNetWorker();
    connect(this->mynetwork->manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinished(QNetworkReply*)));
}

void tNotesLoginDialog::setUpGUI()
{
	QGridLayout *dialogLayout = new QGridLayout();
	tabWidget = new QTabWidget(this);
	setUpLoginGUI();
	setUpRegGUI();
	tabWidget->addTab(loginWidget, tr("Login"));
	tabWidget->addTab(regWidget, tr("Register"));
	dialogLayout->addWidget(tabWidget);
	setLayout(dialogLayout);
	
}

void tNotesLoginDialog::setUpLoginGUI()
{
	//set up the layout
	loginWidget = new QWidget();

	QGridLayout *formGridLayout = new QGridLayout();

	comboUsername = new QComboBox();
	comboUsername->setEditable(true);

	editPassword = new QLineEdit();
	editPassword->setEchoMode(QLineEdit::Password);

	labelUsername = new QLabel();
	labelPassword = new QLabel();
	labelUsername->setText(tr("Username"));
	labelUsername->setBuddy(comboUsername);
	labelPassword->setText(tr("Password"));
	labelPassword->setBuddy(editPassword);

	loginButtons = new QDialogButtonBox();
	loginButtons->addButton(QDialogButtonBox::Ok);
	loginButtons->addButton(QDialogButtonBox::Cancel);
	loginButtons->button(QDialogButtonBox::Ok)->setText(tr("Login"));
	loginButtons->button(QDialogButtonBox::Cancel)->setText(tr("Abort"));

	connect(loginButtons->button(QDialogButtonBox::Cancel),
			SIGNAL(clicked()), this, SLOT(close()));
	connect(loginButtons->button(QDialogButtonBox::Ok),
            SIGNAL(clicked()), this, SLOT(slotAcceptLogin()));

	formGridLayout->addWidget(labelUsername, 0, 0);
	formGridLayout->addWidget(comboUsername, 0, 1);
	formGridLayout->addWidget(labelPassword, 1, 0);
	formGridLayout->addWidget(editPassword, 1, 1);
	formGridLayout->addWidget(loginButtons, 2, 0, 1, 2);

	loginWidget->setLayout(formGridLayout);
}

void tNotesLoginDialog::setUpRegGUI()
{
	//set up the layout
	regWidget = new QWidget();

	QGridLayout *formGridLayout = new QGridLayout(this);

	editRegEmail = new QLineEdit();
	editRegUsername = new QLineEdit();
	editRegPassword = new QLineEdit();
	editRegPassword->setEchoMode(QLineEdit::Password);

	labelRegEmail = new QLabel();
	labelRegUsername = new QLabel();
	labelRegPassword = new QLabel();
	labelRegEmail->setText(tr("Email"));
	labelRegUsername->setBuddy(editRegUsername);
	labelRegUsername->setText(tr("Username"));
	labelRegUsername->setBuddy(editRegUsername);
	labelRegPassword->setText(tr("Password"));
	labelRegPassword->setBuddy(editRegPassword);

	registerButtons = new QDialogButtonBox();
	registerButtons->addButton(QDialogButtonBox::Ok);
	registerButtons->addButton(QDialogButtonBox::Cancel);
	registerButtons->button(QDialogButtonBox::Ok)->setText(tr("Register"));
	registerButtons->button(QDialogButtonBox::Cancel)->setText(tr("Abort"));

	connect(registerButtons->button(QDialogButtonBox::Cancel),
			SIGNAL(clicked()), this, SLOT(close()));
	connect(registerButtons->button(QDialogButtonBox::Ok),
            SIGNAL(clicked()), this, SLOT(slotAcceptReg()));

	formGridLayout->addWidget(labelRegEmail, 0, 0);
	formGridLayout->addWidget(editRegEmail, 0, 1);
	formGridLayout->addWidget(labelRegUsername, 1, 0);
	formGridLayout->addWidget(editRegUsername, 1, 1);
	formGridLayout->addWidget(labelRegPassword, 2, 0);
	formGridLayout->addWidget(editRegPassword, 2, 1);
	formGridLayout->addWidget(registerButtons, 3, 0, 1, 2);

	regWidget->setLayout(formGridLayout);
}

void tNotesLoginDialog::setUsername(QString &username)
{
	bool found = false;
	for( int i = 0; i < comboUsername->count() && !found; i ++)
		if(comboUsername->itemText(i) == username){
			comboUsername->setCurrentIndex(i);
			found = true;
		}

	if(!found){
		int index = comboUsername->count();
		qDebug()<<"Select username"<<index;
		comboUsername->addItem(username);

		comboUsername->setCurrentIndex(index);
	}

	editPassword->setFocus();
}

void tNotesLoginDialog::setPassword(QString &password)
{
	editPassword->setText(password);
}

void tNotesLoginDialog::slotAcceptLogin()
{
    QString username = comboUsername->currentText();
	QString password = editPassword->text();
	int index = comboUsername->currentIndex();

    QByteArray data;
    data.append("{");
    data.append("\"user\":\"");
    data.append(username);
    data.append("\",");
    data.append("\"pass\":\"");
    data.append(password);
    data.append("\"}");
    qDebug()<<data;
    QNetworkRequest network_request;
    //设置头信息
    network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    network_request.setHeader(QNetworkRequest::ContentLengthHeader, data.length());
    //设置url
    network_request.setUrl(QUrl("http://tnotes.wicp.net:8080/signin.cgi"));
    QNetworkReply *reply=mynetwork->post(network_request,data);
    replyMap.insert(reply,login);
//    mynetwork->get("http://www.baidu.com");
//    emit acceptLogin(username, password,
//            index);
//    close();
}

void tNotesLoginDialog::slotAcceptReg()
{
    QString username = editRegUsername->text();
    QString password = editRegPassword->text();
    QByteArray data;
    data.append("{");
    data.append("\"user\":\"");
    data.append(username);
    data.append("\",");
    data.append("\"pass\":\"");
    data.append(password);
    data.append("\"}");
    qDebug()<<data;
    QNetworkRequest network_request;
    //设置头信息
    network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    network_request.setHeader(QNetworkRequest::ContentLengthHeader, data.length());
    //设置url
    network_request.setUrl(QUrl("http://tnotes.wicp.net:8080/signup.cgi"));
    QNetworkReply *reply=mynetwork->post(network_request,data);
    replyMap.insert(reply,regist);
}

void tNotesLoginDialog::setUsernamesList(const QStringList &usernames)
{
	comboUsername->addItems(usernames);
}


//请求完成后执行的操作
void tNotesLoginDialog::replyfinished(QNetworkReply* reply)
{

    RemoteRequest request=replyMap.value(reply);
    switch(request)
    {
    case login:
    {
        QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug()<<status_code;
        QTextCodec * codec=QTextCodec::codecForName("UTF-8");
        QString json=codec->toUnicode(reply->readAll());
        qDebug()<<json;
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
        if (error.error == QJsonParseError::NoError) {
            if (jsonDocument.isObject()) {
                QVariantMap result = jsonDocument.toVariant().toMap();
                QString code=result["status"].toString();
                qDebug() << "state:" << code;
                if(code=="success")
                {
                    //登陆成功
                    QString session=result["session"].toString();
                    qDebug()<<session;
                    QFile file("sessionkey");
                    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
                        qDebug()<<file.errorString();
                    QTextStream out(&file);
                    out<<session;
                    file.close();
                    QMessageBox::information(this,"登陆成功","欢迎使用tNote！",QMessageBox::Ok);
                    QString username = comboUsername->currentText();
                    QString password = editPassword->text();
                    int index = comboUsername->currentIndex();
                    emit acceptLogin(username, password,index);
                    this->close();
                }
                else if(code=="incorrect_password")
                {
                    QMessageBox::warning(this,"登陆失败","密码错误，请重新登陆",QMessageBox::Yes);
                }
                else
                {
                    QMessageBox::warning(this,"登陆失败","出现未知错误，请联系管理员！",QMessageBox::Yes);
                }
            }
        } else {
            QMessageBox::warning(this,"error",error.errorString().toUtf8().constData(),QMessageBox::Yes);
            exit(1);
        }

        break;
    }
    case regist:
    {
        QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug()<<status_code;
        QTextCodec * codec=QTextCodec::codecForName("UTF-8");
        QString json=codec->toUnicode(reply->readAll());
        qDebug()<<json;
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
        if (error.error == QJsonParseError::NoError) {
            if (jsonDocument.isObject()) {
                QVariantMap result = jsonDocument.toVariant().toMap();
                QString code=result["status"].toString();
                qDebug() << "state:" << code;
                if(code=="success")
                {
                    //注册成功
                    QMessageBox::information(this,"注册成功","欢迎使用tNote！",QMessageBox::Ok);
                }
                else if(code=="used_username")
                {
                    QMessageBox::warning(this,"注册失败","用户名已存在，请更换用户名",QMessageBox::Yes);
                }
                else
                {
                    QMessageBox::warning(this,"注册失败","出现未知错误，请联系管理员！",QMessageBox::Yes);
                }
            }
        } else {
            QMessageBox::warning(this,"error",error.errorString().toUtf8().constData(),QMessageBox::Yes);
            exit(1);
        }
        break;
    }

    }
}

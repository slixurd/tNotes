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

#include "tnoteslogindialog.h"

tNotesLoginDialog::tNotesLoginDialog(QWidget* parent)
	: QDialog(parent)
{
	setUpGUI();
	setWindowTitle(tr("User Login"));
	setModal(true);
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
			SIGNAL(clicked()), this, SLOT(slotAccetpLogin()));

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
			SIGNAL(clicked()), this, SLOT(slotAccetpReg()));

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

	emit acceptLogin(username, password,
			index);
	close();
}

void tNotesLoginDialog::slotAcceptReg()
{
	close();
}

void tNotesLoginDialog::setUsernamesList(const QStringList &usernames)
{
	comboUsername->addItems(usernames);
}

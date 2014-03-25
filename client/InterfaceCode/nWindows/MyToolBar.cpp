#include "MyToolBar.h"
#include "nwindows.h"

MyToolBar::MyToolBar(QWidget *parent): QWidget(parent)
{
	
	setStyleSheet("background-color:#c5e398;max-height: 36px;");
	QIcon manIco("asset/man.png");
	QIcon newIco("asset/new.png");
	QIcon rubIco("asset/rub.png");
	QIcon sysIco("asset/sys.png");
	QIcon searchIco("asset/search.png");
	mainLayout = new QHBoxLayout();
	loginButton = new QPushButton();
	loginButton->setStyleSheet(readFile("asset/qss/loginButton.qss"));

	newFileButton= new QPushButton(this);
	newFileButton->setStyleSheet(readFile("asset/qss/newFileButton.qss"));

	deleteFileButton= new QPushButton();
	deleteFileButton->setStyleSheet(readFile("asset/qss/deleteFileButton.qss"));

	sysButton= new QPushButton();
	sysButton->setStyleSheet(readFile("asset/qss/sysButton.qss"));

	searchLineEdit = new QLineEdit();
	searchLineEdit->setStyleSheet(readFile("asset/qss/searchLineEdit.qss"));

	searchButton= new QPushButton();
	searchButton->setStyleSheet(readFile("asset/qss/searchButton.qss"));

	mainLayout->addWidget(loginButton);
	mainLayout->addWidget(newFileButton);
	mainLayout->addWidget(deleteFileButton);
	mainLayout->addWidget(sysButton);
	mainLayout->addWidget(searchLineEdit);
	mainLayout->addWidget(searchButton);

	mainLayout->insertStretch(4, 500);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);
}


MyToolBar::~MyToolBar(void)
{
	
}



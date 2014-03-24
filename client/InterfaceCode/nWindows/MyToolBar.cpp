#include "MyToolBar.h"


MyToolBar::MyToolBar(void)
{
	setStyleSheet("background-color:#c5e398;max-height: 36px;");
	QIcon manIco("asset/man.png");
	QIcon newIco("asset/new.png");
	QIcon rubIco("asset/rub.png");
	QIcon sysIco("asset/sys.png");
	QIcon searchIco("asset/search.png");
	mainLayout = new QHBoxLayout();
	manButton = new QPushButton();
	manButton->setStyleSheet("min-width: 30px;min-height: 30px;color:black;border-image:url(asset/man.png);");

	newButton= new QPushButton();
	newButton->setStyleSheet("min-width: 30px;min-height: 30px;color:black;border-image:url(asset/new.png);");

	rubbishButton= new QPushButton();
	rubbishButton->setStyleSheet("min-width: 30px;min-height: 30px;color:black;border-image:url(asset/rub.png);");

	sysButton= new QPushButton();
	sysButton->setStyleSheet("min-width: 30px;min-height: 30px;color:black;border-image:url(asset/sys.png);");

	searchLineEditsearch = new QLineEdit();
	searchLineEditsearch->setStyleSheet("min-width:300px;min-height: 30px;color:black;border-image:url(asset/searchEdit.png);");

	searchButton= new QPushButton();
	searchButton->setStyleSheet("min-width: 30px;min-height: 30px;color:black;border-image:url(asset/search.png);");


	mainLayout->addWidget(manButton);
	mainLayout->addWidget(newButton);
	mainLayout->addWidget(rubbishButton);
	mainLayout->addWidget(sysButton);
	mainLayout->addWidget(searchLineEditsearch);
	mainLayout->addWidget(searchButton);

	mainLayout->insertStretch(4, 500);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);
}


MyToolBar::~MyToolBar(void)
{
}

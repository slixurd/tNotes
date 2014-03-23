#include "MyEditToolBar.h"


MyEditToolBar::MyEditToolBar(void)
{
	setStyleSheet("background-color:#9dce7a;max-height:50px;");
	mainLayout = new QHBoxLayout();
	bButton = new QPushButton();
	bButton->setStyleSheet("min-width: 40px;min-height: 40px;max-width: 40px;max-height: 40px;color:black;border-image:url(asset/b.png);");

	iButton = new QPushButton();
	iButton->setStyleSheet("min-width: 40px;min-height: 40px;max-width: 40px;max-height: 40px;color:black;border-image:url(asset/i.png);");


	mainLayout->addWidget(bButton,1);
	mainLayout->addWidget(iButton,1);
	mainLayout->insertStretch(2, 50);
	setLayout(mainLayout);
}


MyEditToolBar::~MyEditToolBar(void)
{
}

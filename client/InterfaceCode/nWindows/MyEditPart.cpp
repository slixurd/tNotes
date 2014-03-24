#include "MyEditPart.h"
#include "MyEditToolBar.h"

MyEditPart::MyEditPart(void)
{
	mainLayout = new QVBoxLayout();
	myEditToolBar=new MyEditToolBar();
	textEdit = new QTextEdit();
	textEdit->setStyleSheet("background-color:#FFFFFF");
	mainLayout->setSpacing(0);
	mainLayout->addWidget(myEditToolBar,1);
	QWidget *qw=new QWidget();
	qw->setStyleSheet("background-color:#817f79;max-height:3px;");
	mainLayout->addWidget(qw,1);
	mainLayout->addWidget(textEdit,1);
	setLayout(mainLayout);
}


MyEditPart::~MyEditPart(void)
{

}

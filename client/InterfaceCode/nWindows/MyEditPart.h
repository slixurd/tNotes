#ifndef MYEDIT_H
#define MYEDIT_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include <QTextEdit>
#include "MyEditToolBar.h"
class MyEditPart:public QWidget
{
public:
	MyEditPart(void);
	~MyEditPart(void);

	QVBoxLayout* mainLayout;
	MyEditToolBar* myEditToolBar;
	QTextEdit* textEdit;
};

#endif
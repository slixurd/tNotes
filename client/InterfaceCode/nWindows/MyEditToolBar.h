#ifndef MYEDITTOOL_H
#define MYEDITTOOL_H
#include<QtWidgets/QMainWindow>
#include<QHBoxLayout>
#include<QTextEdit>
#include <QPushButton>

class MyEditToolBar:public QWidget
{
public:
	MyEditToolBar(void);
	~MyEditToolBar(void);

	QHBoxLayout*mainLayout;
	QPushButton* bButton;
	QPushButton* iButton;
};
#endif


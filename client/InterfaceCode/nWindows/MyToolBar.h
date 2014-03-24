#ifndef MYTOOL_H
#define MYTOOL_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
class MyToolBar:public QWidget
{
public:
	MyToolBar(void);
	~MyToolBar(void);
private:
	QHBoxLayout* mainLayout;
	QPushButton* manButton;
	QPushButton* newButton;
	QPushButton* rubbishButton;
	QPushButton* sysButton;
	QLineEdit *searchLineEditsearch;
	QPushButton* searchButton;


};
#endif

#ifndef MYTOOL_H
#define MYTOOL_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
class MyToolBar:public QWidget
{
	
public:
	MyToolBar(QWidget*parent=0);
	~MyToolBar(void);

	QHBoxLayout* mainLayout;
	QPushButton* loginButton;
	QPushButton* newFileButton;
	QPushButton* deleteFileButton;
	QPushButton* sysButton;
	QLineEdit *searchLineEdit;
	QPushButton* searchButton;
};

#endif

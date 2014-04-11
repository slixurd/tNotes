#ifndef MYLISTVIEW_H2
#define MYLISTVIEW_H2

#include <QtGui> 
#include <QListView>
#include <string>

class MyListView2 :public QListView
{  
public:  
	QIcon qic;
	MyListView2();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应

	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
};

#endif
#ifndef TNOTESCATEGORYLIST_H
#define TNOTESCATEGORYLIST_H

#include "MyQItemDelegate.h"
#include <QtGui> 
#include <QListView>
#include <string>
#include <vector>

class tNotesCategoryList :public QListView
{  
public:  
    bool updateListView(QString id);
    QString addCategory(QString name);
    tNotesCategoryList();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
    QIcon qic;
    MyQItemDelegate *myqit;
    vector<Article> dirVector;
};

#endif

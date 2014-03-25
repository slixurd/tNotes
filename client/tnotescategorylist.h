#ifndef TNOTESCATEGORYLIST_H
#define TNOTESCATEGORYLIST_H

#include <QtGui> 
#include <QListView>
#include <string>

class tNotesCategoryList :public QListView
{  
public:  
    tNotesCategoryList();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
};

#endif

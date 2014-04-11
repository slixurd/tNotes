#include <QtGui> 
#include <QTreeView>
#include "nwindows.h"
class TreeView :public QTreeView  
{  
public:  
	TreeView();
	void iterateOverItems();
	QList<QStandardItem*> returnTheItems();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
};
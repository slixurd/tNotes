#ifndef TNOTESBOOKCATEGORYLIST_H
#define TNOTESBOOKCATEGORYLIST_H

#include <QtGui> 
#include <QListView>
#include <string>
#include <QString>

class tNotesBookCategoryList :public QListView
{  
    Q_OBJECT
public:  
    tNotesBookCategoryList();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
    //QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;

public slots:
    void updateNotebooks(QString path);
};

#endif

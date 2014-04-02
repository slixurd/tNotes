#ifndef TNOTESBOOKCATEGORYLIST_H
#define TNOTESBOOKCATEGORYLIST_H
#include <QVector>
#include <QDialog>
#include <QtGui> 
#include <QListView>
#include <string>
#include <QString>
#include "Operation.h"

class tNotesBookCategoryList :public QListView
{  
    Q_OBJECT
public:

    Directory nowDire;
	vector<Directory>dirVectory;
    tNotesBookCategoryList();

    //添加文件  导入的时候使用
	void appendNotebook(Directory dir);

    //内存和文件上新建删除
    void newNotebook(Directory dir);
    void deleteNotebook(QModelIndex&index);



	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
	QStandardItemModel *model;
    QBrush qbr;
    void setupAction();





signals:
    void initNotesCategory(string notebookId);

private slots:
    void initNotebooks(QString path);
    void notebookSelected(const QModelIndex &index);

    // QAbstractItemView interface
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);


};

#endif

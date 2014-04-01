#ifndef TNOTESCATEGORYLIST_H
#define TNOTESCATEGORYLIST_H

#include "MyQItemDelegate.h"
#include <QtGui> 
#include <QListView>
#include <string>
#include <vector>
#include "Operation.h"
#include <QModelIndex>
class tNotesCategoryList :public QListView
{  
    Q_OBJECT
public:  
    bool IsSearchResult;
    bool updateListView(string id);
    void appendCategory(Article art);
    tNotesCategoryList();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
    vector<Article>dirVector;
    vector<string>faId;

    void newCategory(Article art,string iRoot);
    void deleteCategory(QModelIndex &index,string iRoot);
    QString tmpSearchWord;

private:
	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
    QIcon qic;
    MyQItemDelegate *myqit;
    string currentNotebookId;
    void setupActions();


signals:
    void initNotesEditor(string dirId, string articleId, QString searchWord = NULL);
    void initArticle(string dirId, string articleId);

private slots:
    void initNotesCategory(string dirId);
    void noteSelected(const QModelIndex &index);
    void searchToUpdateListView(vector<SearchResult>, QString);
};

#endif

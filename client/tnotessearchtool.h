#ifndef TNOTESSEARCHTOOL_H
#define TNOTESSEARCHTOOL_H

#include <QWidget>
//#include "search.h"
class QGroupBox;
class QLineEdit;
class QPushButton;
class QLabel;
class tNotesButton;
class tNotesSearch;

#include "Operation.h"

class tNotesSearchTool : public QWidget
{
	Q_OBJECT

public:
		tNotesSearchTool(QWidget *parent = 0);
        ~tNotesSearchTool();
        std::vector<std::string> find();
        static tNotesSearch *searchinstance;
        static void build();//建立索引
        static void drop();//删除索引
private:
		QGroupBox *searchToolGroupBox;
		QLineEdit *searchToolLineEdit;
        tNotesButton *searchbtn;
        QLabel *searchStateLabel;
//        tNotesSearch *searchinstance;
private slots:
    void searchbtn_click();

signals:
    void sendRequestedArticles(vector<SearchResult>, QString searchWord); //返回搜索结果
};

#endif

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
        std::vector<std::string> find();
private:
		QGroupBox *searchToolGroupBox;
		QLineEdit *searchToolLineEdit;
        tNotesButton *searchbtn;
        QLabel *searchStateLabel;
        tNotesSearch *searchinstance;
private slots:
    void searchbtn_click();

signals:
    void sendRequestedArticles(vector<SearchResult>, QString searchWord); //返回搜索结果
};

#endif

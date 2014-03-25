#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include "tnotessearchtool.h"
#include <QFile>
#include <vector>
#include "Operation.h"
#include "tnotesbutton.h"

tNotesSearchTool::tNotesSearchTool(QWidget *parent) 
	: QWidget(parent)
{
	searchToolLineEdit = new QLineEdit;
    searchbtn=new tNotesButton("/myres/search.png");

    searchToolLineEdit->setStyleSheet("min-width:280px;min-height: 30px;color:black;border-image:url(:/myres/searchedit.png);");
    searchToolLineEdit->setPlaceholderText("search");
	QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(searchToolLineEdit);
    layout->addWidget(searchbtn);
    layout->addWidget(searchStateLabel);
    layout->setContentsMargins(0, 0, 0, 0);

//    QFile file("~/tNotes/my.qss");
//    // 只读方式打开该文件
//    file.open(QFile::ReadOnly);
//    // 读取文件全部内容，使用tr()函数将其转换为QString类型
//    QString styleSheet = tr(file.readAll());
//    // 为QApplication设置样式表
//    searchbtn->setStyleSheet(styleSheet);
    setLayout(layout);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(searchbtn_click()));
}

bool tNotesSearchTool::find(const std::string str)
{
    int pos=str.find(searchToolLineEdit->text().toStdString());
    if(pos!=-1)
    {
//        searchStateLabel->setText("find it");
        return true;
    }
    else
    {
//        searchStateLabel->setText("not find");
        return false;
    }
}

//按下查询按钮时响应
void tNotesSearchTool::searchbtn_click()
{
    //获取包含查询词的文章列表的伪代码

    std::vector<Article> list(searchAllArticle());
    const char *p=list[0].context.c_str();
    searchStateLabel->setText( p);
//    for(std::vector<Article>::iterator iter=list.begin();iter!=list.end();)
//    {
//        if(!find((*iter).context))
//        {
//            searchStateLabel->setText("find it");
//            list.erase(iter);
//        }
//        else
//        {
//            iter++;
//            searchStateLabel->setText("not find");
//        }
//    }
    //显示在界面的文章列表上

    //暂缺
}

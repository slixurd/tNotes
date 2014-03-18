#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include "tnotessearchtool.h"
#include <QFile>
#include <vector>

tNotesSearchTool::tNotesSearchTool(QWidget *parent) 
	: QWidget(parent)
{
	searchToolLineEdit = new QLineEdit;
    searchbtn=new QPushButton("查找",this);
    searchStateLabel=new QLabel(this);
    searchToolLineEdit->setPlaceholderText("search");
	QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(searchToolLineEdit);
    layout->addWidget(searchbtn);
    layout->addWidget(searchStateLabel);


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

//    std::vector<T> list(searchAllnote());
//    for(std::vector<T>::iterator iter=list.begin();iter!=ivec.end();)
//    {
//        if(!find(*iter.context))
//        {
//            list.erase(iter);
//        }
//        else
//            iter++;
//    }
    //显示在界面的文章列表上



    //暂缺

}

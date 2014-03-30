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
#include "search.h"
#include "Article.h"
#include "string.h"
#include <QDebug>
#include <QTextCodec>

tNotesSearchTool::tNotesSearchTool(QWidget *parent) 
	: QWidget(parent)
{
	searchToolLineEdit = new QLineEdit;
    searchbtn=new tNotesButton("/myres/search.png");

    searchToolLineEdit->setStyleSheet(readFile(":/qss/searchLineEdit.qss"));
    searchToolLineEdit->setPlaceholderText("search");

	QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(searchToolLineEdit);
    layout->addWidget(searchbtn);

    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(searchbtn_click()));
    searchinstance=new tNotesSearch("D:/friso.ini");

    searchinstance->connect("test.db");
    searchinstance->init();
}

std::vector<std::string> tNotesSearchTool::find()
{
    QString searchText = searchToolLineEdit->text();

    char *x = new char[q2s(searchText).length() + 1];
    strcpy(x, q2s(searchText).c_str());


    return searchinstance->select(x);
//    if(pos!=-1)
//    {
////        searchStateLabel->setText("find it");
//        return true;
//    }
//    else
//    {
////        searchStateLabel->setText("not find");
//        return false;
//    }
}

//按下查询按钮时响应
void tNotesSearchTool::searchbtn_click()
{
    //获取包含查询词的文章列表的伪代码
    qDebug()<<"button clicked";
    std::vector<Article> list(searchAllArticle());
    for(std::vector<Article>::iterator iter=list.begin();iter!=list.end();iter++)
    {
        char *tmpArticleId = new char[(*iter).articleId.length() + 1];
        char *tmpName = new char[(*iter).name.length() + 1];
        char *tmpContext = new char[(*iter).context.length() + 1];
        std::cout<<(*iter).context.c_str();
        stdstring2charstar((*iter).articleId.c_str(), tmpArticleId);
        stdstring2charstar((*iter).name.c_str(), tmpName);
        stdstring2charstar((*iter).context.c_str(), tmpContext);
        std::cout<<"content:";
        std::cout<<tmpArticleId<<' '<<tmpName<<' '<<tmpContext<<endl;

        QTextCodec *codec=QTextCodec::codecForName("UTF-8");
       // QString tmp = codec->toUnicode(s2q((*iter).name));

        //char *tmpStr = new char[q2s(tmp).length()+1];

        //stdstring2charstar(q2s(tmp).c_str(), tmpStr);

        //    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
        //    this->replyinformation=codec->toUnicode(reply->readAll());

        QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
        //QString tmp = utf8->toUnicode(s2q((*iter).name.c_str()).toLatin1());
        //char *tmpStr = new char[q2s(tmp).length()+1];

        //stdstring2charstar(q2s(tmp).c_str(), tmpStr);
        //qDebug()<<"tmpstr: "<<tmpStr<<endl;
        searchinstance->insert(tmpArticleId, /*tmpStr*/tmpName,tmpContext);

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
    }
    std::vector<std::string> temp=find();
    //显示在界面的文章列表上

    //暂缺
}

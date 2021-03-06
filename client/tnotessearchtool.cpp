#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include "tnotessearchtool.h"
#include <QFile>
#include <vector>
#include "tnotesbutton.h"
#include "search.h"
#include "Article.h"
#include "string.h"
#include <QDebug>
#include <QTextCodec>

tNotesSearch* tNotesSearchTool::searchinstance=new tNotesSearch("D:/Tencent/tNotes/client/libs/friso.ini");

tNotesSearchTool::tNotesSearchTool(QWidget *parent) 
	: QWidget(parent)
{
	searchToolGroupBox = new QGroupBox(tr("search tool"), this);
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

    searchinstance->connect("test.db");
    searchinstance->init();
}

tNotesSearchTool::~tNotesSearchTool()
{
    drop();
}

std::vector<std::string> tNotesSearchTool::find()
{
    QString searchText = searchToolLineEdit->text();
    //qDebug()<<"searchText:"<<searchText<<endl;
    char *x = new char[searchText.toStdString().length() + 10];
    stdstring2charstar(searchText.toStdString(),x);
    //qDebug()<<"x:"<<x<<endl;
    return searchinstance->select(x);
}

void tNotesSearchTool::build()
{
    qDebug()<<"开始建立索引\n";
    std::vector<Article> list(searchAllArticle());
    for(std::vector<Article>::iterator iter=list.begin();iter!=list.end();iter++)
    {
        qDebug()<<"开始进行咯！";
        //字符转换丧心病狂
        char *tmpArticleId = new char[(*iter).articleId.length()*2];
        char *tmpName = new char[(*iter).name.length()*2];
        char *tmpContext = new char[(*iter).context.length()*2];
        QTextCodec *codec=QTextCodec::codecForName("GBK");
        QString id=codec->toUnicode((*iter).articleId.c_str());
        QString name=codec->toUnicode((*iter).name.c_str());
        QString context=codec->toUnicode((*iter).context.c_str());
        stdstring2charstar(id.toStdString(), tmpArticleId);
        stdstring2charstar(name.toStdString(), tmpName);
        stdstring2charstar(context.toStdString(), tmpContext);
        searchinstance->insert(tmpArticleId,tmpName,tmpContext);
        free(tmpArticleId);
        free(tmpName);
        free(tmpContext);
        //字符转换丧心病狂
    }
    qDebug()<<"索引建立完成！\n";
}

void tNotesSearchTool::drop()
{
    searchinstance->drop();
}



//按下查询按钮时响应
void tNotesSearchTool::searchbtn_click()
{
    //获取包含查询词的文章列表的伪代码
    qDebug()<<"button clicked";
//    build();
//    std::vector<Article> list(searchAllArticle());
//    for(std::vector<Article>::iterator iter=list.begin();iter!=list.end();iter++)
//    {
//        //字符转换丧心病狂
//        char *tmpArticleId = new char[(*iter).articleId.length()*2];
//        char *tmpName = new char[(*iter).name.length()*2];
//        char *tmpContext = new char[(*iter).context.length()*2];
//        QTextCodec *codec=QTextCodec::codecForName("GBK");
//        QString id=codec->toUnicode((*iter).articleId.c_str());
//        QString name=codec->toUnicode((*iter).name.c_str());
//        QString context=codec->toUnicode((*iter).context.c_str());
//        stdstring2charstar(id.toStdString(), tmpArticleId);
//        stdstring2charstar(name.toStdString(), tmpName);
//        stdstring2charstar(context.toStdString(), tmpContext);
//        searchinstance->insert(tmpArticleId,tmpName,tmpContext);
//        free(tmpArticleId);
//        free(tmpName);
//        free(tmpContext);
//        //字符转换丧心病狂
//    }
    std::vector<std::string> temp=find();
    //vector<SearchResult> temp = find();
    //显示在界面的文章列表上
    vector<SearchResult> result = searchRequestedArticles(temp);
    emit sendRequestedArticles(result, searchToolLineEdit->text()); //返回搜索结果（dirId, article）
    //暂缺
}

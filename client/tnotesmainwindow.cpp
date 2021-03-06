#ifndef TNOTEMAIN_H
#define TNOTEMAIN_H

#include <QDir>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QSplitter>
#include <QPushButton>
#include <QSize>
#include <QIcon>
#include <QDate>
#include <QPoint>
#include <QMessageBox>
#include <QTime>
#include <QtDebug>
#include <iostream>

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotesbookcategory.h"
#include "tnotescategory.h"
#include "tnotessearchtool.h"
#include "tnotesbutton.h"
#include "tnoteslogindialog.h"

#include "tnotestitlebar.h"
#include "tnotestoolbar.h"
#include "tnotescontentwidget.h"
#include "tnotesstatusbar.h"
#include "Operation.h"
#include "synchronization.h"
#include "mythread.h"


extern bool isConnected = false;
extern QString DATAPATH = "D:/data/";

tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    IsLogin=false;

    ROOT_PATH = "D:\\data\\";
    /* set window size */

    setMainWindowsSize();
    setWindowFlags(Qt::FramelessWindowHint);
    /* initialization */
    initWidgets();
    setMouseTracking(true);

    setMainWindowLayout();
    setupActions();

    centralWidget->setMouseTracking(true);
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

tNotesMainWindow::~tNotesMainWindow()
{
}




void tNotesMainWindow::setMainWindowsSize()
{
    //因为那天跟投影仪链接的时候获得大小乘以0.8可能会有问题   改回0.8应该也行
    QDesktopWidget *desktop=new QDesktopWidget();
    QWidget *screenWidget = desktop->screen(0);
    int x = screenWidget->width()*0.9;
    int y = screenWidget->height()*0.9;

    this->resize(x, y);
    setWindowState(Qt::WindowMaximized);
}

void tNotesMainWindow::initWidgets()
{
    currentDir = new Directory();
    titleBar = new tNotesTitleBar();
    toolBar = new tNotesToolBar();
    contentWidget = new tNotesContentWidget();
    statusBar = new tNotesStatusBar();
    dialogLogin = new tNotesLoginDialog();
    networkState = new MyNetWorker();

    extern bool isConnected;

    /*
     * 检查网络是否连通，此处有bug
     */
    isConnected = networkState->isconnect();
}

void tNotesMainWindow::setMainWindowLayout()
{	
	centralWidget = new QWidget;

	this->setCentralWidget(centralWidget);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(toolBar, 2);
    mainLayout->addWidget(contentWidget, 10);
    mainLayout->addWidget(statusBar, 2);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

	centralWidget->setLayout(mainLayout);
}


void tNotesMainWindow::setupActions()
{
    connect(toolBar, SIGNAL(openLoginDialog()), this, SLOT(openLoginDialog()));
    connect(toolBar->newDirectoryButton, SIGNAL(clicked()), this, SLOT(newDirectory()));
    connect(toolBar->newArticleButton, SIGNAL(clicked()), this, SLOT(newArticle()));
    connect(toolBar->deleteArticleButton, SIGNAL(clicked()), this, SLOT(deleteArticle()));
    connect(toolBar->deleteDirectoryButton, SIGNAL(clicked()), this, SLOT(deleteDirectory()));
    connect(toolBar->sysButton, SIGNAL(clicked()), this, SLOT(synchronize()));
    connect(toolBar->searchTool,SIGNAL(sendRequestedArticles(vector<SearchResult>, QString)),contentWidget->mListView2,
            SLOT(searchToUpdateListView(vector<SearchResult>, QString)));

    connect(dialogLogin, SIGNAL(acceptLogin(QString&,QString&,int&)), this, SLOT(userAuthenticated(QString&,QString&,int&)));

    connect(titleBar, SIGNAL(minimizeWindow()), this, SLOT(minimizeWindow()));
    connect(titleBar, SIGNAL(maxmizeRestoreWindow(bool)), this, SLOT(maxmizeRestoreWindow(bool)));
    connect(titleBar, SIGNAL(closeWindow()), this, SLOT(close()));
    connect(titleBar, SIGNAL(moveStart(QPoint)), this, SLOT(moveStart(QPoint)));
    connect(titleBar, SIGNAL(moveEnd(QPoint)), this, SLOT(moveEnd(QPoint)));

    connect(this, SIGNAL(updateNotebooks(QString)), contentWidget, SLOT(initContents(QString)));
    connect(&syn, SIGNAL(updateListView()), this, SLOT(synUpdateListView()));

    connect(contentWidget->mEditPart,SIGNAL(updateNoteFinished(string, string)),this,
            SLOT(updateListView2ArticleModify(string, string)));
    connect(this,SIGNAL(deleteListView2Artical()),contentWidget->mEditPart,
            SLOT(clearArticle()));

}

void tNotesMainWindow::updateListView2ArticleModify(string dirId, string artId){
    contentWidget->mListView2->updateIndexView(dirId,artId);
}

void tNotesMainWindow::synUpdateListView(){
    emit initNotesByUser(qstrUser);
}



void tNotesMainWindow::userAuthenticated(QString &username, QString &pass, int &index)
{
    IsLogin=true;
    //toolBar->loginButton->setStyleSheet(readFile(":/qss/exitButton.qss"));

    qstrUser = username;
    QDir qdir(ROOT_PATH+username);
    if(!qdir.exists())qdir.mkdir(ROOT_PATH+username);
    initNotesByUser(username);
}

void tNotesMainWindow::openLoginDialog()
{
    if(IsLogin){
        //toolBar->loginButton->setStyleSheet(readFile(":/qss/loginButton.qss"));
        IsLogin=false;
        //退出操作








    }else
    {
        dialogLogin->exec();
    }
}


bool tNotesMainWindow::saveArticle()
{
    currentArticle->context = "helloworld!";
    currentArticle->name = "bar";
    currentArticle->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentArticle->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentArticle->isSyn = true;
    createArticle("foo", *currentArticle);
	return true;
}


void tNotesMainWindow::initNotesByUser(QString &name)
{
    qstrUser = name;
    //print(name);
    extern string rootPath;
    setupRootPath(q2s(ROOT_PATH + name));
    myThread *newthread=new myThread();
    newthread->start();
    //print(s2q(rootPath));
    emit updateNotebooks(ROOT_PATH + name);
}


/*
 * actions to change window size.
 *
 */


void tNotesMainWindow::minimizeWindow()
{
    showMinimized();
}
void tNotesMainWindow::maxmizeRestoreWindow(bool maxRestore)
{
    if(!maxRestore){
        showMaximized();
    } else {
        showNormal();
    }
}

void tNotesMainWindow::moveStart(QPoint startPoint)
{
    moveStartPoint = startPoint;
}

void tNotesMainWindow::moveEnd(QPoint endPoint)
{
    move(endPoint - moveStartPoint);
}

void tNotesMainWindow::newDirectory(){
    QModelIndex index = contentWidget->mListView->currentIndex();
    if(!IsLogin){
        return;
    }
    QDate nowDate = QDate::currentDate();

    qint64 time = QDateTime::currentMSecsSinceEpoch();
    QString qstrTimeStamp = QString::number(time);
    //qstrTimeStamp = qstrTimeStamp.mid(0,10);

    QString qstrYear = QString::number(nowDate.year());
    QString qstrMonth = QString::number(nowDate.month());
    QString qstrDay = QString::number(nowDate.day());


    if(nowDate.month()<10)qstrMonth="0"+qstrMonth;
    if(nowDate.day()<10)qstrDay="0"+qstrDay;

    QString qstrDate = qstrYear+
            qstrMonth+qstrDay;
    qDebug()<<qstrDate<<"asd"<<endl;
    string strDate  =q2s(qstrDate);
    /////////ID  修改目录id
    Directory dirTemp(q2s(qstrTimeStamp),string("newNotes"),strDate,strDate,false);
    contentWidget->mListView->newNotebook(dirTemp);
}

void tNotesMainWindow::newArticle(){
    QModelIndex index = contentWidget->mListView2->currentIndex();
    if(index.column()==-1){
        if(contentWidget->mListView->nowDire.nodeId=="")return;
    }
    QDate nowDate = QDate::currentDate();

    QString qstrYear = QString::number(nowDate.year());
    QString qstrMonth = QString::number(nowDate.month());
    QString qstrDay = QString::number(nowDate.day());

    qint64 time = QDateTime::currentMSecsSinceEpoch();
    QString qstrTimeStamp = QString::number(time);
    //qstrTimeStamp = qstrTimeStamp.mid(0,10);


    if(nowDate.month()<10)qstrMonth="0"+qstrMonth;
    if(nowDate.day()<10)qstrDay="0"+qstrDay;

    QString qstrDate = qstrYear+
            qstrMonth+qstrDay;
    qDebug()<<qstrDate<<"asd"<<endl;
    string strDate  =q2s(qstrDate);

    /////////ID  修改文章id
    Article artTemp(q2s(qstrTimeStamp), "newArticle", "",strDate,strDate,false);
    contentWidget->mListView2->newCategory(artTemp,
                  contentWidget->mListView->nowDire.nodeId);
}

void tNotesMainWindow::deleteArticle(){
    QModelIndex index = contentWidget->mListView2->currentIndex();
    if(index.column()==-1){
        return;
    }
    contentWidget->mListView2->deleteCategory(index,
                  contentWidget->mListView->nowDire.nodeId);
    emit deleteListView2Artical();
}

void tNotesMainWindow::deleteDirectory(){
    QModelIndex index = contentWidget->mListView->currentIndex();
    if(index.column()==-1){
        return;
    }
    contentWidget->mListView->deleteNotebook(index);
    contentWidget->mListView2->clearView();
    emit deleteListView2Artical();
}
//同步按钮
void tNotesMainWindow::synchronize(){
    //contentWidget->mListView->dirVectory;   第一个列表的vector
    //contentWidget->mListView2->dirVectory;  第二个列表的vector
    //contentWidget->mListView->nowDire; 第一个当前的目录
    //如果没有登陆则登陆  否则同步
    if(!IsLogin){
        openLoginDialog();
    }else{
        syn.sendrecord();
        syn.receiveData();
    }
}








////////拉伸窗口代码////////
void tNotesMainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_ptPressGlobal = event->globalPos();
        m_bLeftBtnPress = true;

        m_eDirection = PointValid(event->windowPos());
        SetCursorStyle(m_eDirection);
    }
}
//鼠标移动事件
void tNotesMainWindow::mouseMoveEvent(QMouseEvent *event)
{

    if(!m_bLeftBtnPress)
    {
        m_eDirection = PointValid(event->windowPos());
        SetCursorStyle(m_eDirection);
    }
    else
    {
        m_eDirection = PointValid(event->windowPos());
        SetCursorStyle(m_eDirection);
        int nXGlobal = event->globalX();
        int nYGlobal = event->globalY();
        SetDrayMove(nXGlobal,nYGlobal,m_eDirection);
        m_ptPressGlobal =QPoint(nXGlobal,nYGlobal);
    }
}
////鼠标释放事件
void tNotesMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bLeftBtnPress = false;
        m_eDirection = 9;
    }
}
////双击变大事件在titilebar
////鼠标样式
void tNotesMainWindow::SetCursorStyle(int direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case 1:
    case 5:
        setCursor(Qt::SizeVerCursor);
        break;
    case 3:
    case 7:
        setCursor(Qt::SizeHorCursor);
        break;
    case 2:
    case 6:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case 4:
    case 0:
        setCursor(Qt::SizeFDiagCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

int tNotesMainWindow::PointValid(QPointF p)
{
    int temp=0;
    int PxW=50;
    QRect qr = this->geometry();

    if(p.x()>0&&p.x()<PxW){
        temp+=1;
    }
    if(p.x()>qr.width()-PxW&&p.x()<qr.width()){
        temp+=2;
    }
    if(p.y()>0&&p.y()<PxW){
        temp+=8;
    }
    if(p.y()>qr.height()-PxW&&p.y()<qr.height()){
        temp+=4;
    }


    switch(temp){
        case 9:return 0;
        break;
        case 8:return 1;
        break;
        case 10:return 2;
        break;
        case 2:return 3;
        break;
        case 6:return 4;
        break;
        case 4:return 5;
        break;
        case 5:return 6;
        break;
        case 1:return 7;
        break;
        default:return 8;
    }
}

void tNotesMainWindow::SetDrayMove(int nXGlobal,int nYGlobal,int d)
{
    //计算偏差
    int ndX = nXGlobal - m_ptPressGlobal.x();
    int ndY = nYGlobal - m_ptPressGlobal.y();
    //获得主窗口位置信息
    QRect rectWindow = geometry();
    switch(d){
        case 1:
            rectWindow.setTop(rectWindow.top()+ndY);
            break;
        case 3:
            rectWindow.setRight(rectWindow.right()+ndX);
            break;
        case 5:
            rectWindow.setBottom(rectWindow.bottom()+ndY);
            break;
        case 7:
            rectWindow.setLeft(rectWindow.left()+ndX);
            break;
    case 0:
        rectWindow.setBottom(rectWindow.top()+ndY);
        rectWindow.setLeft(rectWindow.left()+ndX);
        break;
    case 2:
        rectWindow.setBottom(rectWindow.top()+ndY);
        rectWindow.setLeft(rectWindow.right()+ndX);
        break;
    case 4:
        rectWindow.setBottom(rectWindow.bottom()+ndY);
        rectWindow.setLeft(rectWindow.right()+ndX);
        break;
    case 6:
            rectWindow.setBottom(rectWindow.bottom()+ndY);
            rectWindow.setLeft(rectWindow.left()+ndX);
            break;
    }
    //重新设置窗口位置为新位置信息
    setGeometry(rectWindow);
}

#endif

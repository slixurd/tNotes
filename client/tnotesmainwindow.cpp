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

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotessearchtool.h"
#include "tnotesbutton.h"
#include "tnoteslogindialog.h"

#include "tnotestitlebar.h"
#include "tnotestoolbar.h"
#include "tnotescontentwidget.h"
#include "tnotesstatusbar.h"
#include "Operation.h"



tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ROOT_PATH = "D:\\data\\";
	/* set window size */

	setMainWindowsSize();
    setWindowFlags(Qt::FramelessWindowHint);
	/* initialization */
    initWidgets();
    setMouseTracking(true);

    setMainWindowLayout();
	setupActions();
}

tNotesMainWindow::~tNotesMainWindow()
{


}




void tNotesMainWindow::setMainWindowsSize()
{
    //因为那天跟投影仪链接的时候获得大小乘以0.8可能会有问题   改回0.8应该也行
    setMinimumWidth(1200);
    setMinimumHeight(680);
    this->move(100,30);
}

void tNotesMainWindow::initWidgets()
{
    currentDir = new Directory();
    titleBar = new tNotesTitleBar();
    toolBar = new tNotesToolBar();
    contentWidget = new tNotesContentWidget();
    statusBar = new tNotesStatusBar();
    dialogLogin = new tNotesLoginDialog();
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
	connect(toolBar->newnoteButton, SIGNAL(clicked()), this, SLOT(newDirectory()));
	
   connect(dialogLogin, SIGNAL(acceptLogin(QString&,QString&,int&)), this, SLOT(userAuthenticated(QString&,QString&,int&)));

    connect(titleBar, SIGNAL(minimizeWindow()), this, SLOT(minimizeWindow()));
    connect(titleBar, SIGNAL(maxmizeRestoreWindow(bool)), this, SLOT(maxmizeRestoreWindow(bool)));
    connect(titleBar, SIGNAL(closeWindow()), this, SLOT(close()));
    connect(titleBar, SIGNAL(moveStart(QPoint)), this, SLOT(moveStart(QPoint)));
    connect(titleBar, SIGNAL(moveEnd(QPoint)), this, SLOT(moveEnd(QPoint)));

    connect(this, SIGNAL(updateNotebooks(QString)), contentWidget, SLOT(initContents(QString)));

}




void tNotesMainWindow::userAuthenticated(QString &username, QString &pass, int &index)
{
    initNotesByUser(username);
}

void tNotesMainWindow::openLoginDialog()
{

	dialogLogin->exec();
}

bool tNotesMainWindow::createDirectory()
{
    currentDir->name = "foo";
    currentDir->modifiedTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentDir->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentDir->isSyn = true;
    createRoot(*currentDir);
    return true;
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
    //print(name);
    extern string rootPath;
    setupRootPath(q2s(ROOT_PATH + name));
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
    Directory dirTemp("99",string("newNotes"),"2014/2/1","2014/2/1",false);
    contentWidget->mListView->newNotebook(dirTemp);
}

////////拉伸窗口代码：////////
//void tNotesMainWindow::mousePressEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        m_ptPressGlobal = event->globalPos();
//        m_bLeftBtnPress = true;
//    }
//}
////鼠标移动事件
//void tNotesMainWindow::normalMoveEvent(QMouseEvent *me)
//{
//    if(!m_bLeftBtnPress)
//    {
//        m_eDirection = PointValid(event->windowPos());
//        SetCursorStyle(m_eDirection);
//    }
//    else
//    {
//        int nXGlobal = event->globalX();
//        int nYGlobal = event->globalY();
//        SetDrayMove(nXGlobal,nYGlobal,m_eDirection);
//        m_ptPressGlobal =QPoint(nXGlobal,nYGlobal);
//    }
//}
////鼠标释放事件
//void tNotesMainWindow::mouseReleaseEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        m_bLeftBtnPress = false;
//        m_eDirection = 8;
//    }
//}
////双击变大事件在titilebar
////鼠标样式
//void tNotesMainWindow::SetCursorStyle(int direction)
//{
//    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
//    switch(direction)
//    {
//    case 1:
//    case 5:
//        setCursor(Qt::SizeVerCursor);
//        break;
//    case 3:
//    case 7:
//        setCursor(Qt::SizeHorCursor);
//        break;
//    case 2:
//    case 6:
//        setCursor(Qt::SizeBDiagCursor);
//        break;
//    case 4:
//    case 0:
//        setCursor(Qt::SizeFDiagCursor);
//        break;
//    default:
//        setCursor(Qt::ArrowCursor);
//        break;
//    }
//}

//int tNotesMainWindow::PointValid(QPointF p)
//{
//    int temp=0;
//    int PxW;
//    QRect qr = geometry();
//    if(p.x()>0&&p.x()<PxW){
//        temp+=1;
//    }
//    if(p.x()>qr.width()-PxW&&p.x()<qr.width()){
//        temp+=2;
//    }
//    if(p.y()>0&&p.y()<PxW){
//        temp+=8;
//    }
//    if(p.x()>qr.height()-PxW&&p.x()<qr.height()){
//        temp+=4;
//    }
//    switch(temp){
//        case 9:return 0;
//        break;
//        case 8:return 1;
//        break;
//        case 10:return 2;
//        break;
//        case 2:return 3;
//        break;
//        case 6:return 4;
//        break;
//        case 4:return 5;
//        break;
//        case 5:return 6;
//        break;
//        case 1:return 7;
//        break;
//        default:return 8;
//    }
//}

//void tNotesMainWindow::SetDrayMove(int x,int y,int d)
//{

//}

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

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotessearchtool.h"
#include "tnotesbutton.h"
#include "tnoteslogindialog.h"

#include "tnotestitlebar.h"
#include "tnotestoolbar.h"
#include "tnotescontentwidget.h"
#include "tnotesstatusbar.h"



tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* set window size */

	setMainWindowsSize();
    setWindowFlags(Qt::FramelessWindowHint);
	/* initialization */
    initWidgets();
    setMouseTracking(true);
    /*
	notesBookCategory = new tNotesBookCategory;
	notesBookCategory->setMinimumSize(150, 300);
	notesTextEditor = new tNotesTextEditor;
	notesTextEditor->setMinimumSize(300, 300);
	notesCategory = new tNotesCategory;
	notesCategory->setMinimumSize(150, 300);

	searchTool = new tNotesSearchTool;
	searchTool->setStyleSheet("width:25%;height:25px;");

	buttonLogin = new tNotesButton(tr("/myres/login.png"), 56, 28);
	buttonNewNotebook = new tNotesButton(tr("/myres/newnotebook.png"));
	buttonSettings = new tNotesButton(tr("/myres/settings.png"));
	buttonSync = new tNotesButton(tr("/myres/sync.png"));
    currentDir = new Directory();
    */
    /*
	 * set layout
	 */
	setMainWindowLayout();
    pointValid(1, 2);
	setupActions();
}

tNotesMainWindow::~tNotesMainWindow()
{


}




void tNotesMainWindow::setMainWindowsSize()
{
    QDesktopWidget dw;
    int x = dw.width()*0.8;
    int y = dw.height()*0.8;
    //this->resize(950, 600);
    this->resize(x, y);
}

void tNotesMainWindow::initWidgets()
{
/*
    notesBookCategory = new tNotesBookCategory;
    notesBookCategory->setMinimumSize(150, 300);
    notesTextEditor = new tNotesTextEditor;
    notesTextEditor->setMinimumSize(300, 300);
    notesCategory = new tNotesCategory;
    notesCategory->setMinimumSize(150, 300);

    searchTool = new tNotesSearchTool;
    searchTool->setStyleSheet("width:25%;height:25px;");

    buttonLogin = new tNotesButton(tr("/myres/login.png"), 56, 28);
    buttonNewNotebook = new tNotesButton(tr("/myres/newnotebook.png"));
    buttonSettings = new tNotesButton(tr("/myres/settings.png"));
    buttonSync = new tNotesButton(tr("/myres/sync.png"));
*/
    currentDir = new Directory();

    titleBar = new tNotesTitleBar();
    toolBar = new tNotesToolBar();
    contentWidget = new tNotesContentWidget();
    statusBar = new tNotesStatusBar();

}

void tNotesMainWindow::setMainWindowLayout()
{	
	centralWidget = new QWidget;
	this->setCentralWidget(centralWidget);
    /*
	QWidget *topWidget = new QWidget;
	QHBoxLayout *toolLayout = new QHBoxLayout;
	toolLayout->addWidget(buttonLogin);
	toolLayout->addWidget(buttonNewNotebook);
	toolLayout->addWidget(buttonSettings);
	toolLayout->addWidget(buttonSync);
	toolLayout->addSpacing(400);
	//toolLayout->addWidget(searchTool, 0, Qt::AlignRight);
	toolLayout->addWidget(searchTool);
	toolLayout->setContentsMargins(0, 0, 0, 0);
	topWidget->setLayout(toolLayout);
	topWidget->setStyleSheet("background-color:#44ddff;height:100px;");

	QHBoxLayout *noteLayout = new QHBoxLayout;
	splitter = new QSplitter;
	splitter->setChildrenCollapsible(false);
	notesBookCategory->setStyleSheet("height:520px;");
	splitter->addWidget(notesBookCategory);
	splitter->setStretchFactor(splitter->indexOf(notesBookCategory), 1);
	notesCategory->setStyleSheet("height:520px;");
	
	splitter->addWidget(notesCategory);
	splitter->setStretchFactor(splitter->indexOf(notesCategory), 2);
	notesTextEditor->setStyleSheet("height:520px;");
	splitter->addWidget(notesTextEditor);
	splitter->setStretchFactor(splitter->indexOf(notesTextEditor), 3);
	noteLayout->addWidget(splitter);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);
	mainLayout->addWidget(topWidget);
	mainLayout->addLayout(noteLayout);
    */

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(toolBar, 2);
    mainLayout->addWidget(contentWidget, 10);
    mainLayout->addWidget(statusBar, 2);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
	centralWidget->setLayout(mainLayout);
}


void tNotesMainWindow::setupActions()
{
    connect(toolBar, SIGNAL(openLoginDialog()), this, SLOT(openLoginDialog()));
//    connect(buttonNewNotebook, SIGNAL(clicked()), this, SLOT(createDirectory()));
//    connect(buttonSettings, SIGNAL(clicked()), this, SLOT(saveArticle()));
}

void tNotesMainWindow::openLoginDialog()
{
	dialogLogin = new tNotesLoginDialog();
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
}

void tNotesMainWindow::pointValid(int x, int y)
{

    QRect qrTemp = geometry();
    int x1, x2, y1, y2;
    qrTemp.getCoords(&x1, &x2, &y1, &y2);
}



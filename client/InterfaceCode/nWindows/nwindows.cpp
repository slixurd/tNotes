#include "nwindows.h"



//************************************
//全局函数  用于QString string互转  文件读取（QSS）
//************************************
QString s2q( const std::string &s) 
{ 
	return QString(QString::fromLocal8Bit(s.c_str())); 
}
std::string q2s( const QString &s) 
{ 
	return std::string((const char *)s.toLocal8Bit()); 
}
QString readFile(std::string filePath)
{
	std::ifstream file(filePath);
	std::string strTemp((std::istreambuf_iterator<char>(file)),  
		std::istreambuf_iterator<char>());  
	return s2q(strTemp);
}

//************************************
//构造函数与析构
//************************************
nWindows::nWindows(QWidget *parent)
	: QFrame(parent)
{
	//设置窗口大小  属性
	setMainWindowsSize();
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	//创建标题栏
	m_TitleBar = new MyTitleBar(this);
	//创建工具栏
	m_ToolBar = new MyToolBar(this);
	//创建内容区域
	m_ContentWidget = new MyContentWidget();
	//创建状态栏
	m_StatusBar = new MyStatusBar();
	//创建布局
	m_pMainLayout = new QVBoxLayout(this);
	//将部件加入到布局中
	m_pMainLayout->addWidget(m_TitleBar);
	m_pMainLayout->addWidget(m_ToolBar,2);
	m_pMainLayout->addWidget(m_ContentWidget,10);
	m_pMainLayout->addWidget(m_StatusBar,2);
	//设置间距与边缘空白
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->setContentsMargins(0,0,0,0);

	//m_TitleBar  响应函数
	connect(m_TitleBar->maxmizeButton, SIGNAL(clicked()), this, SLOT(showMaxRestore()));
	connect(m_TitleBar->minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(m_TitleBar->closeButton, SIGNAL(clicked()), this, SLOT(close()));
	//m_ToolBar  响应函数
	connect(m_ToolBar->loginButton, SIGNAL(clicked()), this, SLOT(login()));
	connect(m_ToolBar->newFileButton, SIGNAL(clicked()), this, SLOT(newFile()));
	connect(m_ToolBar->deleteFileButton, SIGNAL(clicked()), this, SLOT(deleteFile()));
	connect(m_ToolBar->sysButton, SIGNAL(clicked()), this, SLOT(synchronized()));
	connect(m_ToolBar->searchButton, SIGNAL(clicked()), this, SLOT(searchNote()));

	//mListView  响应函数
	connect(m_ContentWidget->mListView, SIGNAL(clicked(QModelIndex)),
		this, SLOT(clicked(QModelIndex)));

	//mListView2  响应函数
	connect(m_ContentWidget->mListView2, SIGNAL(clicked(QModelIndex)),
		this, SLOT(clicke(QModelIndex)));

	MyListView *mylistviewTemp1 = m_ContentWidget->mListView;
	MyListView2 *mylistviewTemp2 = m_ContentWidget->mListView2;
	//初始化数据
	dirVector1 = searchAllRoot();
	for (int i=0;i<dirVector1.size();i++)
	{
		QStandardItem *itemTemp=new QStandardItem(s2q(dirVector1[i].name));
		itemTemp->setSizeHint(QSize(150,40));
		itemTemp->setIcon(mylistviewTemp1->qic);
		itemTemp->setBackground(mylistviewTemp1->qbr);
		mylistviewTemp1->model->appendRow(itemTemp);
	}


	MyQItemDelegate *myqit=new MyQItemDelegate();
	mylistviewTemp2->setItemDelegate(myqit);

	vector<Article> dir2Vector = searchRootArticle(dirVector1[0].nodeId);
	for (int i=0;i<dir2Vector.size();i++)
	{
		QStandardItem *itemTemp=new QStandardItem(s2q(dir2Vector[i].name));
		itemTemp->setSizeHint(QSize(150,70));
		mylistviewTemp2->model->appendRow(itemTemp);
	}
}

nWindows::~nWindows()
{
	
}


//************************************
// 调整窗口大小的函数
//************************************
void nWindows::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.8;
	this->resize(x, y);
}
void nWindows::showSmall()
{
	showMinimized();
}
void nWindows::showMaxRestore()
{
	if (m_TitleBar->maxNormal) {
		showNormal();
		m_TitleBar->maxNormal = !(m_TitleBar->maxNormal);
		m_TitleBar->maxmizeButton->setIcon(m_TitleBar->maxPix);
	} else {
		showMaximized();
		m_TitleBar->maxNormal = !(this->m_TitleBar->maxNormal);
		m_TitleBar->maxmizeButton->setIcon(m_TitleBar->restorePix);
	}
}


//************************************
//  各个部件按钮等的响应函数
//************************************

/////////////工具栏////////////////
//登陆
void nWindows::login()
{
	QDialog qd;
	qd.show();
}
//创建新的文件
void nWindows::newFile()
{
	MyListView*mlist1 = m_ContentWidget->mListView;
	
	QStandardItem *itemTemp=new QStandardItem(s2q("新笔记本"));  ;
	itemTemp->setIcon(mlist1->qic);
	itemTemp->setBackground(mlist1->qbr);

	mlist1->model->appendRow(itemTemp);
}
//删除文件
void nWindows::deleteFile()
{
	MyListView*mlist1 = m_ContentWidget->mListView;
	
}
//同步文件
void nWindows::synchronized()
{
	QDialog qd;
	qd.show();
}
//搜索文件
void nWindows::searchNote()
{
	
}


/////////////编辑栏////////////////
//黑体按钮
void nWindows::editBoldButton()
{
	QDialog qd;
	qd.show();
}
//下划线按钮
void nWindows::editUnderLineButton()
{
	QDialog qd;
	qd.show();
}



/////////////笔记本组ListView1视图响应函数////////////////

//点击了QModelIndex项
void nWindows::clicked(const QModelIndex &index){
	QDialog qd;
	qd.show();
}

/////////////笔记本ListView2视图响应函数////////////////
void nWindows::clicke(const QModelIndex &index){
	QDialog qd;
	qd.show();
}
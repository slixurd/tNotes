#include "nwindows.h"
#include <string>
#include <QString>
#include <QRect>
QString s2q( const std::string &s) 
{ 
	return QString(QString::fromLocal8Bit(s.c_str())); 
}
std::string q2s( const QString &s) 
{ 
	return std::string((const char *)s.toLocal8Bit()); 
}

nWindows::nWindows(QWidget *parent)
	: QFrame(parent)
{
	setMainWindowsSize();
	//setWindowFlags(Qt::CustomizeWindowHint); 
	//setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint);
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	//创建标题栏
	m_TitleBar = new MyTitleBar(this);
	//创建工具栏
	m_ToolBar = new MyToolBar();
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
	PointValid(1,2);
}

nWindows::~nWindows()
{
	
}

void nWindows::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.8;
	this->resize(x, y);

	//setGeometry(dw.availableGeometry());
}

//	QPoint m_ptPressGlobal;
//	bool m_bLeftBtnPress;
//	m_eDirection
//	//鼠标按下事件
//	void MainWindow::mousePressEvent(QMouseEvent * event)
//{
//	
//	if (event ->button() == Qt::LeftButton)
//	{
//		m_ptPressGlobal = event ->globalPos();
//		m_bLeftBtnPress = true ;
//	}
//}
////鼠标移动事件
//void MainWindow::mouseMoveEvent(QMouseEvent * event)
//{
//	
//	if (!m_bLeftBtnPress)
//	{
//		m_eDirection = PointValid( event ->x(),event ->y());
//		SetCursorStyle(m_eDirection);
//	}
//	else
//	{
//		int nXGlobal = event ->globalX();
//		int nYGlobal = event ->globalY();
//		SetDrayMove(nXGlobal,nYGlobal,m_eDirection);
//		m_ptPressGlobal =QPoint(nXGlobal,nYGlobal);
//	}
//}
////鼠标释放事件
//void MainWindow::mouseReleaseEvent(QMouseEvent * event)
//{
//	if (event ->button() == Qt::LeftButton)
//	{
//		m_bLeftBtnPress = false ;
//		m_eDirection = eNone;
//	}
//}
////鼠标双击事件
//void MainWindow::mouseDoubleClickEvent(QMouseEvent * event)
//{
//	if (event ->button() == Qt::LeftButton && event ->y()<= m_pTitleBar->height())
//	{
//		if (!m_bMaxWin)
//		{
//			m_rectRestoreWindow = geometry();
//			setGeometry(qApp->desktop()->availableGeometry());
//		}
//		else
//		{
//			setGeometry(m_rectRestoreWindow);
//		}
//		m_bMaxWin = !m_bMaxWin;
//	}
//}
//
////设置鼠标样式
//void MainWindow::SetCursorStyle(enum_Direction direction)
//{
//	//设置上下左右以及右上、右下、左上、坐下的鼠标形状
//	switch (direction)
//	{
//	case eTop:
//	case eBottom:
//		setCursor(Qt::SizeVerCursor);
//		break ;
//	case eRight:
//	case eLeft:
//		setCursor(Qt::SizeHorCursor);
//		break ;
//	case eTopRight:
//	case eBottomLeft:
//		setCursor(Qt::SizeBDiagCursor);
//		break ;
//	case eRightBottom:
//	case eLeftTop:
//		setCursor(Qt::SizeFDiagCursor);
//		break ;
//	default :
//		setCursor(Qt::ArrowCursor);
//		break ;
//	}
//}
//
////设置鼠标拖动的窗口位置信息
//void MainWindow::SetDrayMove(int nXGlobal, int nYGlobal,enum_Direction direction)
//{
//	//计算偏差
//	int ndX = nXGlobal - m_ptPressGlobal.x();
//	int ndY = nYGlobal - m_ptPressGlobal.y();
//	//获得主窗口位置信息
//	QRect rectWindow = geometry();
//	//判D别方向
//	if (direction & eTop)
//	{
//		rectWindow.setTop(rectWindow.top()+ndY);
//	}
//	if (direction & eRight)
//	{
//		rectWindow.setRight(rectWindow.right()+ndX);
//	}
//	if (direction & eBottom)
//	{
//		rectWindow.setBottom(rectWindow.bottom()+ndY);
//	}
//	if (direction & eLeft)
//	{
//		rectWindow.setLeft(rectWindow.left()+ndX);
//	}
//	if (rectWindow.width()< minimumWidth() || rectWindow.height()<minimumHeight())
//	{
//		return ;
//	}
//	//重新设置窗口位置为新位置信息
//	setGeometry(rectWindow);
//}
void nWindows::PointValid(int x,int y){
	QRect qrTemp = geometry();
	int x1,x2,y1,y2;
	qrTemp.getCoords(&x1,&x2,&y1,&y2);

}
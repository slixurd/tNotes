#ifndef NWINDOWS_H
#define NWINDOWS_H
#include <QDesktopWidget>
#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include <QToolButton>

#include "ui_nwindows.h"

#include "MyTitleBar.h"
#include "MyToolBar.h"
#include "ContentWidget.h"
#include "MyStatusBar.h"

#include <string>
extern QString s2q( const std::string &s);
extern std::string q2s(const QString &s);



class nWindows : public QFrame
{
	Q_OBJECT
public:
	nWindows(QWidget *parent = 0);
	~nWindows();
	void setMainWindowsSize();





	void PointValid(int x,int y);

private:
	QVBoxLayout *m_pMainLayout;
	MyTitleBar *m_TitleBar;
	MyToolBar *m_ToolBar;
	MyContentWidget *m_ContentWidget;
	MyStatusBar *m_StatusBar;
};

#endif // NWINDOWS_H

#ifndef NWINDOWS_H
#define NWINDOWS_H

#include <string>
#include <QString>
#include <QRect>
#include <fstream>
#include <QDesktopWidget>
#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QToolButton>
#include <QItemDelegate>

#include "MyQItemDelegate.h"
#include "Operation.h"
#include "MyTitleBar.h"
#include "MyToolBar.h"
#include "ContentWidget.h"
#include "MyStatusBar.h"

extern QString s2q( const std::string &s);
extern std::string q2s(const QString &s);
extern QString readFile(std::string filePath);


class nWindows : public QFrame
{
	Q_OBJECT
public:
	nWindows(QWidget *parent = 0);
	~nWindows();
	void setMainWindowsSize();

private:
	QVBoxLayout *m_pMainLayout;
	MyTitleBar *m_TitleBar;
	MyToolBar *m_ToolBar;
	MyContentWidget *m_ContentWidget;
	MyStatusBar *m_StatusBar;


	//Êý¾Ý
	vector<Directory> dirVector1;
	public slots:
		void newFile();
		void login();
		void deleteFile();
		void synchronized();
		void searchNote();

		void editBoldButton();
		void editUnderLineButton();

		void showSmall();
		void showMaxRestore();
		void clicked(const QModelIndex &index);
		void clicke(const QModelIndex &index);
};

#endif // NWINDOWS_H

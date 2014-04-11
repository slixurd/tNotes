#ifndef MYTITLE_H
#define MYTITLE_H
#include <QToolButton>
#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QStyle>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QDialog>
class MyTitleBar:public QWidget
{
public:
	MyTitleBar(QWidget *parent);
	~MyTitleBar(void);
	QHBoxLayout* m_pMainLayout;

	MyTitleBar *selfWidget;
	QWidget *mParent;
	QPoint startPos;
	QPoint clickPos;
	QPixmap restorePix, maxPix;
	bool maxNormal;
	QToolButton *minimizeButton;
	QToolButton *maxmizeButton;
	QToolButton *closeButton;

	
protected:
	void mousePressEvent(QMouseEvent *me);
	void mouseMoveEvent(QMouseEvent *me);
};
#endif

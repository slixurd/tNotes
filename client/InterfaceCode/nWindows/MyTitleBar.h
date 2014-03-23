#ifndef MYTITLE_H
#define MYTITLE_H
#include <QToolButton>
#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
class MyTitleBar:public QWidget
{
public:
	MyTitleBar(QWidget *parent);
	~MyTitleBar(void);
	QHBoxLayout* m_pMainLayout;
private:
	MyTitleBar *selfWidget;
	QWidget *mParent;
	QPoint startPos;
	QPoint clickPos;
	QPixmap restorePix, maxPix;
	bool maxNormal;
	QToolButton *minimizeButton;
	QToolButton *maxmizeButton;
	QToolButton *closeButton;

	public slots:
		void showSmall();
	public slots:
		void showMaxRestore();
protected:
	void mousePressEvent(QMouseEvent *me);
	void mouseMoveEvent(QMouseEvent *me);
};
#endif

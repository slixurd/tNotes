#ifndef TNOTESTITLEBAR_H
#define TNOTESTITLEBAR_H
#include <QToolButton>
#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
class tNotesTitleBar:public QWidget
{
public:
    tNotesTitleBar(QWidget *parent = 0);
    ~tNotesTitleBar(void);
	QHBoxLayout* m_pMainLayout;
private:
    tNotesTitleBar *selfWidget;
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

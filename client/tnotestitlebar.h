#ifndef TNOTESTITLEBAR_H
#define TNOTESTITLEBAR_H
#include <QToolButton>
#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include "tnotesmainwindow.h"
class QPoint;
class tNotesTitleBar:public QWidget
{
    Q_OBJECT
public:
    tNotesTitleBar(QWidget *parent = 0);
    ~tNotesTitleBar(void);
	QHBoxLayout* m_pMainLayout;
    bool maxNormal;
private:
    void setupActions();
    tNotesTitleBar *selfWidget;
	QWidget *mParent;
	QPoint startPos;
	QPoint clickPos;
	QPixmap restorePix, maxPix;

	QToolButton *minimizeButton;
	QToolButton *maxmizeButton;
	QToolButton *closeButton;

private slots:
        void showMinimized();
		void showMaxRestore();
        void closeMainWindow();

signals:
    void minimizeWindow();
    void maxmizeRestoreWindow(bool);
    void closeWindow();
    void moveStart(QPoint);
    void moveEnd(QPoint);
protected:
	void mousePressEvent(QMouseEvent *me);
	void mouseMoveEvent(QMouseEvent *me);
};
#endif

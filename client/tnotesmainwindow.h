#ifndef TNOTESMAINWINDOW_H
#define TNOTESMAINWINDOW_H
#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include "Operation.h"
#include"synchronization.h"
class QSplitter;
class QPushButton;
class QGroupBox;
class QIcon;
class QPoint;

class tNotesButton;
class tNotesTextEditor;
class tNotesBookCategory;
class tNotesCategory;
class tNotesSearchTool;
class tNotesLoginDialog;
class tNotesTitleBar;
class tNotesToolBar;
class tNotesContentWidget;
class tNotesStatusBar;

class tNotesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    tNotesMainWindow(QWidget *parent = 0);
    ~tNotesMainWindow();

private:
		void setMainWindowsSize();
		void setMainWindowLayout();
		void setupActions();
        void initWidgets();
        void initNotesByUser(QString &name);
        void showMaxRestore();
		QWidget *centralWidget;
        QString ROOT_PATH;
        tNotesTitleBar *titleBar;
        tNotesToolBar *toolBar;
        tNotesContentWidget *contentWidget;
        tNotesStatusBar *statusBar;

/*
		tNotesButton *buttonLogin;
		tNotesButton *buttonNewNotebook;
		tNotesButton *buttonSettings;
		tNotesButton *buttonSync;
		
		tNotesSearchTool *searchTool;

		QSplitter *splitter;
		tNotesBookCategory *notesBookCategory;
        tNotesTextEditor *notesTextEditor;
		tNotesCategory *notesCategory;
*/
        Directory *currentDir;
        Article *currentArticle;

        tNotesLoginDialog *dialogLogin;
        QPoint moveStartPoint;
        synchronization syn;

        QString qstrUser;

public:
        bool IsLogin=false;

protected:
        ///////////拉伸窗口函数
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        int PointValid(QPointF p);
        void SetDrayMove(int x,int y,int d);
        //0 1 2 3 4 5 6 7  左上角  上  右上角  右  右下角  下  左下角  左
        void SetCursorStyle(int direction);

        QPoint m_ptPressGlobal;
        bool m_bLeftBtnPress;
        int m_eDirection;
private slots:
        void minimizeWindow();
        void maxmizeRestoreWindow(bool maxRestore);
        void userAuthenticated(QString &username , QString &pass, int &Sindex);
		void openLoginDialog();

        bool saveArticle();
        void moveStart(QPoint);
        void moveEnd(QPoint);
        //void clickedBook(const QModelIndex &index);
        //void clickedNote(const QModelIndex &index);
        void newDirectory();
        void newArticle();
        void deleteArticle();
        void deleteDirectory();
        void synchronize();

        void synUpdateListView();
signals:
        void initNotebooks(Directory *dirList);
        void initNotes(Article *articleList);
        void initNotesContents(Article article);
        void updateNotebooks(QString path);
        //void updateEditor(string articleId);
};
#endif

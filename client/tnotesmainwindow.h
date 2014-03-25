#ifndef TNOTESMAINWINDOW_H
#define TNOTESMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include "Operation.h"

class QSplitter;
class QPushButton;
class QGroupBox;
class QIcon;

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
        void pointValid(int x, int y);

		QWidget *centralWidget;

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

private slots:
		void openLoginDialog();
        bool createDirectory();
        bool saveArticle();


};

#endif // TNOTESMAINWINDOW_H

#ifndef TNOTESMAINWINDOW_H
#define TNOTESMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>

class QSplitter;
class tNotesTextEditor;
class QGroupBox;
class tNotesBookCategory;
class tNotesCategory;
class tNotesSearchTool;

class tNotesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    tNotesMainWindow(QWidget *parent = 0);
    ~tNotesMainWindow();



private:
		void setMainWindowsSize();

		QSplitter *splitter;
		QGroupBox *centralWidget;
    tNotesTextEditor *notesTextEditor;
		QWidget *editToolBar;
		tNotesBookCategory *notesBookCategory;
		tNotesCategory *notesCategory;
		tNotesSearchTool *searchTool;
};

#endif // TNOTESMAINWINDOW_H

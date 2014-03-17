#ifndef TNOTESMAINWINDOW_H
#define TNOTESMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>


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

		QGroupBox *centralWidget;
    tNotesTextEditor *notesTextEditor;
		QWidget *editToolBar;
		tNotesBookCategory *notesBookCategory;
		tNotesCategory *notesCategory;
		tNotesSearchTool *searchTool;
};

#endif // TNOTESMAINWINDOW_H

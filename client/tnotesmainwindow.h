#ifndef TNOTESMAINWINDOW_H
#define TNOTESMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>

class QSplitter;
class QPushButton;
class QGroupBox;
class QIcon;

class tNotesButton;
class tNotesTextEditor;
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
		void setMainWindowLayout();

		QWidget *centralWidget;

		tNotesButton *buttonLogin;
		tNotesButton *buttonNewNotebook;
		tNotesButton *buttonSettings;
		tNotesButton *buttonSync;
		
		tNotesSearchTool *searchTool;


		QSplitter *splitter;
		tNotesBookCategory *notesBookCategory;
    tNotesTextEditor *notesTextEditor;
		tNotesCategory *notesCategory;
};

#endif // TNOTESMAINWINDOW_H

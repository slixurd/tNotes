#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QMap>
#include <QPointer>
#include <QString>

class QTextEdit;
class QGroupBox;
class QLabel;
class QToolButton;
class QToolBar;
class QAction;

class tNotesTextEditor : public QWidget
{
	Q_OBJECT

public:
		tNotesTextEditor(QWidget *parent = 0);

private:
		QLabel *noteTitle;
		QToolBar *noteToolBar;
		QLabel *noteCreatedTime;
		QLabel *noteLastModifiedTime;
		QGroupBox *noteEditorGroupBox;
		QTextEdit *noteEditor;
		QAction *actionUndo;

private:

		QString getTitle();
		QString getCreatedTime();
		QString getLastModifiedTime();

		void setupEditActions();


};

#endif

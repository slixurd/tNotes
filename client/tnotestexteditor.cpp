#include <QTextEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QToolBar>
#include <QTextDocument>
#include <QIcon>
#include <QDateTime>
#include <QFont>
#include <QAction>
#include "tnotestexteditor.h"


tNotesTextEditor::tNotesTextEditor(QWidget *parent)
	: QWidget(parent)
{

	setupEditActions();

	//noteEditorGroupBox = new QGroupBox(tr("noteEditor"), this);
	noteEditor = new QTextEdit;
	
	noteTitle = new QLabel(getTitle());

	QFont timeFont("Arial", 8, QFont::Bold);
	noteCreatedTime = new QLabel("Created: " + getCreatedTime());
	noteCreatedTime->setFont(timeFont);
	noteLastModifiedTime = new QLabel("updated: " + getLastModifiedTime());
	noteLastModifiedTime->setFont(timeFont);

	noteToolBar = new QToolBar;

	connect(noteEditor->document(), SIGNAL(undoAvailable(bool)),
			actionUndo, SLOT(setEnabled(bool)));

	actionUndo->setEnabled(noteEditor->document()->isUndoAvailable());

	connect(actionUndo, SIGNAL(triggered()), noteEditor, SLOT(undo()));


	QGridLayout *titleLayout = new QGridLayout;
	titleLayout->addWidget(noteTitle, 0, 0, 0, 2);
	titleLayout->addWidget(noteToolBar, 0, 2);
	titleLayout->addWidget(noteCreatedTime, 1, 0);
	titleLayout->addWidget(noteLastModifiedTime, 1, 1);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(titleLayout, 1);
	layout->addWidget(noteEditor, 9);

	setLayout(layout);
}

void tNotesTextEditor::setupEditActions()
{
	QToolBar *tb = new QToolBar();
	
	tb->setWindowTitle(tr("Edit Action"));

	QAction *a;
	/*  
	a = actionUndo = new QAction(QIcon::fromTheme("edit-undo"),
				tr("&Undo"), this);
	*/

	actionUndo = new QAction("&Undo", this);

	actionUndo->setShortcut(QKeySequence::Undo);
	tb->addAction(actionUndo);
}

QString tNotesTextEditor::getTitle()
{
	QString ret = "Hello World!";
	return ret;
}

QString tNotesTextEditor::getCreatedTime()
{
	return QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
}

QString tNotesTextEditor::getLastModifiedTime()
{
	return QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
}

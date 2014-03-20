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
#include <QFrame>
#include "tnotestexteditor.h"
#include "tnotesbutton.h"


tNotesTextEditor::tNotesTextEditor(QWidget *parent)
	: QWidget(parent)
{

	setupEditActions();

	//noteEditorGroupBox = new QGroupBox(tr("noteEditor"), this);
	noteEditor = new QTextEdit;
	
	QFont titleFont("Arial", 18, QFont::Bold);
	noteTitle = new QLabel(getTitle());
	noteTitle->setFont(titleFont);

	QFont timeFont("Arial", 8, QFont::Bold);
	noteCreatedTime = new QLabel("Created: " + getCreatedTime());
	noteCreatedTime->setFont(timeFont);
	noteLastModifiedTime = new QLabel("updated: " + getLastModifiedTime());
	noteLastModifiedTime->setFont(timeFont);

	horizonLine = new QFrame();
	horizonLine->setFrameShape(QFrame::HLine);
	horizonLine->setFrameShadow(QFrame::Sunken);

	buttonEdit = new tNotesButton("/myres/edit.png");

	/*  
	QHBoxLayout *tmpLayout = new QHBoxLayout;
	tmpLayout->addWidget(buttonEdit);
	*/

	QWidget *titleWidget = new QWidget;
	QGridLayout *titleLayout = new QGridLayout;
	titleLayout->addWidget(noteTitle, 0, 0, 0, 2);
	titleLayout->addWidget(noteCreatedTime, 0, 1, 0, 2, Qt::AlignJustify);
	//titleLayout->addLayout(tmpLayout, 0, 2, 0, 2);
	titleLayout->addWidget(buttonEdit, 0, 3, 0, 2, Qt::AlignRight);
	titleLayout->addWidget(horizonLine, 1, 0, 2, 0);
	titleLayout->addWidget(noteLastModifiedTime, 2, 4, Qt::AlignRight);
	titleLayout->setContentsMargins(0, 0, 0, 2);
	titleWidget->setLayout(titleLayout);
	titleWidget->setMinimumSize(470, 80);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(titleWidget);
	layout->addWidget(noteEditor);
	

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
	return QDate::currentDate().toString("yyyy.MM.dd");
}

QString tNotesTextEditor::getLastModifiedTime()
{
	return QDate::currentDate().toString("yyyy.MM.dd");
}

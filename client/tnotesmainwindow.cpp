#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QSplitter>
#include <QPushButton>
#include <QSize>
#include <QIcon>

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotesbookcategory.h"
#include "tnotescategory.h"
#include "tnotessearchtool.h"
#include "tnotesbutton.h"


tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* set window size */

	setMainWindowsSize();

	/* initialization */
	/*  
	centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	*/
	
	notesBookCategory = new tNotesBookCategory;
	notesBookCategory->setMinimumSize(150, 300);
	notesTextEditor = new tNotesTextEditor;
	notesTextEditor->setMinimumSize(300, 300);
	searchTool = new tNotesSearchTool;
	searchTool->setStyleSheet("width:120px;height:25px;");
	notesCategory = new tNotesCategory;
	notesCategory->setMinimumSize(150, 300);



	buttonLogin = new tNotesButton(tr("/myres/login.png"), 50, 25);
	buttonNewNotebook = new tNotesButton(tr("/myres/newnotebook.png"));
	buttonSettings = new tNotesButton(tr("/myres/settings.png"));
	buttonSync = new tNotesButton(tr("/myres/sync.png"));

	/*
	 * set layout
	 */
	setMainWindowLayout();
	/*  
	QHBoxLayout *toolLayout = new QHBoxLayout;
	toolLayout->addStretch(3);
	toolLayout->addWidget(searchTool, 1);

	QHBoxLayout *noteLayout = new QHBoxLayout;
	splitter = new QSplitter;
	splitter->setChildrenCollapsible(false);
	splitter->addWidget(notesBookCategory);
	splitter->setStretchFactor(splitter->indexOf(notesBookCategory), 1);
	splitter->addWidget(notesCategory);
	splitter->setStretchFactor(splitter->indexOf(notesCategory), 1);
	splitter->addWidget(notesTextEditor);
	splitter->setStretchFactor(splitter->indexOf(notesTextEditor), 5);
	noteLayout->addWidget(splitter);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(toolLayout, 1);
	mainLayout->addLayout(noteLayout, 9);
	
	centralWidget->setLayout(mainLayout);
	*/
}

tNotesMainWindow::~tNotesMainWindow()
{


}

void tNotesMainWindow::setMainWindowsSize()
{
	this->resize(950, 600);
}

void tNotesMainWindow::setMainWindowLayout()
{	
	centralWidget = new QWidget;
	this->setCentralWidget(centralWidget);
	
	QWidget *topWidget = new QWidget;
	QHBoxLayout *toolLayout = new QHBoxLayout;
	toolLayout->addWidget(buttonLogin);
	toolLayout->addWidget(buttonNewNotebook);
	toolLayout->addWidget(buttonSettings);
	toolLayout->addWidget(buttonSync);
	toolLayout->addSpacing(500);
	toolLayout->addWidget(searchTool, 0, Qt::AlignRight);
	topWidget->setStyleSheet("background-color:#44ddff;height:50px;");
	topWidget->setLayout(toolLayout);

	QHBoxLayout *noteLayout = new QHBoxLayout;
	splitter = new QSplitter;
	splitter->setChildrenCollapsible(false);
	splitter->addWidget(notesBookCategory);
	splitter->setStretchFactor(splitter->indexOf(notesBookCategory), 1);
	splitter->addWidget(notesCategory);
	splitter->setStretchFactor(splitter->indexOf(notesCategory), 1);
	splitter->addWidget(notesTextEditor);
	splitter->setStretchFactor(splitter->indexOf(notesTextEditor), 5);
	noteLayout->addWidget(splitter);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(topWidget, 1);
	mainLayout->addLayout(noteLayout, 9);
	
	centralWidget->setLayout(mainLayout);
}

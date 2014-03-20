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
	
	notesBookCategory = new tNotesBookCategory;
	notesBookCategory->setMinimumSize(150, 300);
	notesTextEditor = new tNotesTextEditor;
	notesTextEditor->setMinimumSize(300, 300);
	notesCategory = new tNotesCategory;
	notesCategory->setMinimumSize(150, 300);


	searchTool = new tNotesSearchTool;
	searchTool->setStyleSheet("width:25%;height:25px;");



	buttonLogin = new tNotesButton(tr("/myres/login.png"), 56, 28);
	buttonNewNotebook = new tNotesButton(tr("/myres/newnotebook.png"));
	buttonSettings = new tNotesButton(tr("/myres/settings.png"));
	buttonSync = new tNotesButton(tr("/myres/sync.png"));

	/*
	 * set layout
	 */
	setMainWindowLayout();
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
	toolLayout->addSpacing(400);
	//toolLayout->addWidget(searchTool, 0, Qt::AlignRight);
	toolLayout->addWidget(searchTool);
	toolLayout->setContentsMargins(0, 0, 0, 0);
	topWidget->setLayout(toolLayout);
	topWidget->setStyleSheet("background-color:#44ddff;height:100px;");

	QHBoxLayout *noteLayout = new QHBoxLayout;
	splitter = new QSplitter;
	splitter->setChildrenCollapsible(false);
	notesBookCategory->setStyleSheet("height:520px;");
	splitter->addWidget(notesBookCategory);
	splitter->setStretchFactor(splitter->indexOf(notesBookCategory), 1);
	notesCategory->setStyleSheet("height:520px;");
	
	splitter->addWidget(notesCategory);
	splitter->setStretchFactor(splitter->indexOf(notesCategory), 2);
	notesTextEditor->setStyleSheet("height:520px;");
	splitter->addWidget(notesTextEditor);
	splitter->setStretchFactor(splitter->indexOf(notesTextEditor), 3);
	noteLayout->addWidget(splitter);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);
	mainLayout->addWidget(topWidget);
	mainLayout->addLayout(noteLayout);
	
	centralWidget->setLayout(mainLayout);
}

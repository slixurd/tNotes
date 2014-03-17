#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotesbookcategory.h"
#include "tnotescategory.h"
#include "tnotessearchtool.h"


tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* set window size */

	setMainWindowsSize();

	/* initialization */
	centralWidget = new QGroupBox(tr("central widget"));
	setCentralWidget(centralWidget);
	centralWidget->setSizePolicy(QSizePolicy::Expanding,
			QSizePolicy::Expanding);
	
	notesBookCategory = new tNotesBookCategory;
	notesTextEditor = new tNotesTextEditor;
	searchTool = new tNotesSearchTool;
	notesCategory = new tNotesCategory;

	/*
	 * set layout
	 */
	QVBoxLayout *editorLayout = new QVBoxLayout;
	editorLayout->addWidget(searchTool, 1);
	editorLayout->addWidget(notesTextEditor, 10);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addWidget(notesBookCategory, 1);
	mainLayout->addWidget(notesCategory, 1);
	mainLayout->addLayout(editorLayout, 2);
	
	centralWidget->setLayout(mainLayout);
}

tNotesMainWindow::~tNotesMainWindow()
{

}

void tNotesMainWindow::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.7;
	this->resize(x, y);
}

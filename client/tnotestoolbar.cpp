#include "tnotestoolbar.h"
#include "tnotesbutton.h"
#include "tnotessearchtool.h"
#include "tnoteslogindialog.h"


tNotesToolBar::tNotesToolBar(void)
{
    QWidget *toolWidget = new QWidget();
    setStyleSheet(readFile(":/qss/mytoolbar.qss"));


    loginButton = new QPushButton();
    loginButton->setStyleSheet(readFile(":/qss/loginButton.qss"));
    newnoteButton = new QPushButton();
    newnoteButton->setStyleSheet(readFile(":/qss/newFileButton.qss"));
    trashButton = new QPushButton();
    trashButton->setStyleSheet(readFile(":/qss/deleteFileButton.qss"));
    sysButton = new QPushButton();
    sysButton->setStyleSheet(readFile(":/qss/sysButton.qss"));
    searchTool = new tNotesSearchTool();


    setupActions();
    QHBoxLayout *toolLayout = new QHBoxLayout();
    mainLayout = new QHBoxLayout();

    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(newnoteButton);
    mainLayout->addWidget(trashButton);
	mainLayout->addWidget(sysButton);
    mainLayout->addWidget(searchTool);

    mainLayout->insertStretch(4, 500);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);


    toolWidget->setLayout(mainLayout);
    toolLayout->addWidget(toolWidget);
    toolLayout->setContentsMargins(0,0,0,0);
    setLayout(toolLayout);
}


tNotesToolBar::~tNotesToolBar(void)
{
}

void tNotesToolBar::setupActions()
{
    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
}

void tNotesToolBar::loginButtonClicked()
{
    emit openLoginDialog();
}

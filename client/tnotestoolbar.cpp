#include "tnotestoolbar.h"
#include "tnotesbutton.h"
#include "tnotessearchtool.h"
#include "tnoteslogindialog.h"


tNotesToolBar::tNotesToolBar(void)
{
    QWidget *toolWidget = new QWidget();
    setStyleSheet("background-color:#c5e398;max-height: 40px;");


    loginButton = new tNotesButton("/myres/login.png", 30, 30);
    newnoteButton = new tNotesButton("/myres/newnote.png", 30, 30);
    trashButton = new tNotesButton("/myres/trash.png", 30, 30);
    sysButton = new tNotesButton("/myres/sys.png", 30, 30);
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

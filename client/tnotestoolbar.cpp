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
    newDirectoryButton = new QPushButton();
    newDirectoryButton->setStyleSheet(readFile(":/qss/newFileButton.qss"));
    deleteDirectoryButton = new QPushButton();
    deleteDirectoryButton->setStyleSheet(readFile(":/qss/deleteFileButton.qss"));
    sysButton = new QPushButton();
    sysButton->setStyleSheet(readFile(":/qss/sysButton.qss"));
    searchTool = new tNotesSearchTool();

    newArticleButton = new QPushButton();;
    newArticleButton->setStyleSheet(readFile(":/qss/newArticleButton.qss"));
    deleteArticleButton = new QPushButton();;
    deleteArticleButton->setStyleSheet(readFile(":/qss/deleteArticleButton.qss"));


    setupActions();
    QHBoxLayout *toolLayout = new QHBoxLayout();
    mainLayout = new QHBoxLayout();

    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(newDirectoryButton);
    mainLayout->addWidget(deleteDirectoryButton);
    mainLayout->addWidget(sysButton);

    //mainLayout->alignment();
    mainLayout->addWidget(newArticleButton,0,Qt::AlignAbsolute);
    mainLayout->addWidget(deleteArticleButton);
    mainLayout->addWidget(searchTool);

    mainLayout->insertStretch(6, 500);
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


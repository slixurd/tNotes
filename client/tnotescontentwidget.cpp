#include "tnotescontentwidget.h"
#include <QSplitter>


tNotesContentWidget::tNotesContentWidget(void)
{
    setupLayout();
    setupActions();
}


tNotesContentWidget::~tNotesContentWidget(void)
{

}

void tNotesContentWidget::setupLayout()
{
    setStyleSheet(readFile(":/qss/tnotescontentwidget.qss"));
    QWidget *mainWidget = new QWidget();
    m_pMainLayout = new QHBoxLayout();
    splitter = new QSplitter();
    mListView = new tNotesBookCategoryList();
    mListView->setMinimumSize(200, 400);
    mListView2 = new tNotesCategoryList();
    mListView2->setMinimumSize(200, 400);
    mEditPart = new tNotesTextEditor();
    mEditPart->setMinimumSize(400, 400);

    splitter->setChildrenCollapsible(false);
    splitter->addWidget(mListView);
    splitter->addWidget(mListView2);
    splitter->addWidget(mEditPart);
    splitter->setStretchFactor(splitter->indexOf(mListView), 0.6);
    splitter->setStretchFactor(splitter->indexOf(mListView2), 0.6);
    splitter->setStretchFactor(splitter->indexOf(mEditPart), 0.6);
    m_pMainLayout->addWidget(splitter);
    mainWidget->setLayout(m_pMainLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(mainWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);
}

void tNotesContentWidget::setupActions()
{
    connect(this, SIGNAL(initNotebooksCategory(QString)), mListView, SLOT(initNotebooks(QString)));
    connect(mListView, SIGNAL(initNotesCategory(string)), mListView2, SLOT(initNotesCategory(string)));
    connect(mListView2, SIGNAL(initNotesEditor(string, string)), mEditPart, SLOT(initArticle(string, string)));
}



void tNotesContentWidget::initContents(QString path)
{
    emit initNotebooksCategory(path);
}

#include "tnotescontentwidget.h"
#include <QSplitter>


tNotesContentWidget::tNotesContentWidget(void)
{
	setStyleSheet("background-color:#c5e398;");
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

	setLayout(m_pMainLayout);

}


tNotesContentWidget::~tNotesContentWidget(void)
{

}

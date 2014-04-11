#include "ContentWidget.h"


MyContentWidget::MyContentWidget(void)
{
	setStyleSheet("background-color:#c5e398;");
	m_pMainLayout = new QHBoxLayout();
	mListView = new MyListView();

	m_pMainLayout->addWidget(mListView,0.6);

	mListView2 = new MyListView2();
	m_pMainLayout->addWidget(mListView2,0.8);

	mEditPart = new MyEditPart();
	m_pMainLayout->addWidget(mEditPart,2);
	setLayout(m_pMainLayout);
	/*QWidget *qwidget=new QWidget();
	qwidget->setStyleSheet("background-image: url(asset/notes0.png);max-height: 48px;max-width: 48px;");
	m_pMainLayout->addWidget(qwidget);
	setLayout(m_pMainLayout);*/
}


MyContentWidget::~MyContentWidget(void)
{

}

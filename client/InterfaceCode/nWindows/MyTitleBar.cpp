#include "MyTitleBar.h"
#include "nwindows.h"
MyTitleBar::MyTitleBar(QWidget *parent)
{
	mParent=parent;
	selfWidget=this;
	setStyleSheet(readFile("asset/qss/mytitlebar.qss"));
	m_pMainLayout = new QHBoxLayout();


	minimizeButton = new QToolButton(this);
	maxmizeButton = new QToolButton(this);
	closeButton = new QToolButton(this);

	QPixmap pix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
	closeButton->setIcon(pix);

	maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
	maxmizeButton->setIcon(maxPix);

	QPixmap minpix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
	minimizeButton->setIcon(minpix);

	restorePix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);

	minimizeButton->setMinimumHeight(24);
	closeButton->setMinimumHeight(24);
	maxmizeButton->setMinimumHeight(24);

	QLabel *label = new QLabel(this);
	label->setStyleSheet("color:#ffffff;font-size:24px;");
	label->setText("tNotes");

	//titleico.png
	
	QPushButton*icoButton= new QPushButton();
	icoButton->setStyleSheet("top:2px;min-width: 25px;min-height: 25px;color:black;border-image:url(asset/image/titleico.png);");
	m_pMainLayout->addWidget(icoButton);
	m_pMainLayout->addWidget(label);
	m_pMainLayout->addWidget(label);
	m_pMainLayout->addWidget(minimizeButton);
	m_pMainLayout->addWidget(maxmizeButton);
	m_pMainLayout->addWidget(closeButton);

	m_pMainLayout->insertStretch(2, 500);
	m_pMainLayout->setSpacing(0);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setLayout(m_pMainLayout);

	maxNormal = false;
}


MyTitleBar::~MyTitleBar(void)
{

}

void MyTitleBar::mousePressEvent(QMouseEvent *me)
{
	startPos = me->globalPos();
	clickPos = mapToParent(me->pos());
}
void MyTitleBar::mouseMoveEvent(QMouseEvent *me)
{
	if (maxNormal)
		return;
	parentWidget()->move(me->globalPos() - clickPos);
}
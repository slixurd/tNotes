#include "tnotestitlebar.h"
#include "operation.h"
#include<QStyle>
#include<QLabel>
#include<QMouseEvent>
#include <QPushButton>
#include <QDialog>


tNotesTitleBar::tNotesTitleBar(QWidget *parent)
{
    mParent=parent;
    selfWidget=this;
    QWidget *titleWidget = new QWidget();

    setStyleSheet(readFile(":/qss/mytitlebar.qss"));
    m_pMainLayout = new QHBoxLayout();


    minimizeButton = new QToolButton(this);
    maxmizeButton = new QToolButton(this);
    closeButton = new QToolButton(this);

    QPixmap pix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(pix);

    restorePix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);

    maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    maxmizeButton->setIcon(restorePix);

    QPixmap minpix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minimizeButton->setIcon(minpix);



    minimizeButton->setMinimumHeight(24);
    closeButton->setMinimumHeight(24);
    maxmizeButton->setMinimumHeight(24);

    QLabel *label = new QLabel(this);
    label->setStyleSheet("color:#ffffff;font-size:24px;font-family:sans-serif;");
    label->setText("tNotes");

    QPushButton*icoButton= new QPushButton();
    icoButton->setStyleSheet("top:2px;min-width: 25px;min-height: 25px;color:black;border-image:url(:/myres/titleico.png);");
    //m_pMainLayout->addWidget(icoButton);
    m_pMainLayout->addWidget(label);
    m_pMainLayout->addWidget(label);
    m_pMainLayout->addWidget(minimizeButton);
    m_pMainLayout->addWidget(maxmizeButton);
    m_pMainLayout->addWidget(closeButton);

    m_pMainLayout->insertStretch(2, 500);
    m_pMainLayout->setSpacing(0);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    titleWidget->setLayout(m_pMainLayout);
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleWidget);
    titleLayout->setContentsMargins(0,0,0,0);
    setLayout(titleLayout);

    maxNormal = true;
    setupActions();
}


tNotesTitleBar::~tNotesTitleBar(void)
{

}

void tNotesTitleBar::setupActions()
{
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeMainWindow()));
    connect(maxmizeButton, SIGNAL(clicked()), this, SLOT(showMaxRestore()));

}
void tNotesTitleBar::showMinimized()
{
    emit minimizeWindow();
}

void tNotesTitleBar::showMaxRestore()
{
    emit maxmizeRestoreWindow(maxNormal);
    if (maxNormal) {
        maxNormal = !maxNormal;
        maxmizeButton->setIcon(maxPix);
    } else {
        maxNormal = !maxNormal;
        maxmizeButton->setIcon(restorePix);
    }
}

void tNotesTitleBar::closeMainWindow()
{
    emit closeWindow();
}

void tNotesTitleBar::mousePressEvent(QMouseEvent *me)
{
    startPos = me->globalPos();
    clickPos = mapToParent(me->pos());
    emit moveStart(clickPos);
}
void tNotesTitleBar::mouseMoveEvent(QMouseEvent *me)
{
    if (maxNormal)
        return;
    emit moveEnd(me->globalPos());
}
void tNotesTitleBar::mouseDoubleClickEvent(QMouseEvent *event)   //鼠标点击响应
{
    showMaxRestore();
}


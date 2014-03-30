#include "MyQItemDelegate.h"


MyQItemDelegate::MyQItemDelegate(void)
{
}


MyQItemDelegate::~MyQItemDelegate(void)
{

}
void MyQItemDelegate::paint(QPainter*painter,const QStyleOptionViewItem&option, const QModelIndex&index)const  
{
    QString strConfigListview=readFile(":/cfg/Listview1.cfg");
    QStringList strConfigList=strConfigListview.split("");
	QStyleOptionViewItem myOption=option; 
    //configur
    QFont qfTitle(s2q("微软雅黑"));
    QFont qfNormal(s2q("微软雅黑"));
    qfTitle.setPixelSize(14);
    qfTitle.setBold(true);

    QColor qcTitle(23,48,5);
    QColor qcDate=Qt::darkGreen;
    QColor qcContent=Qt::black;
    QColor qcLine=Qt::darkGreen;




	QString content = index.model()->data(index, Qt::DisplayRole).toString(); // 取到模型中原来的内容

    QStringList QList = content.split(";");
    QString qstrName="";
    QString qstrDate="";
    QString qstrContent="";

    if(QList.size()>0)
        qstrName=QList[0];
    if(QList.size()>1){
        qstrDate=QList[1].mid(0,4)+"/"+QList[1].mid(4,2)+"/"+QList[1].mid(6,2);;
    }
    if(QList.size()>2)
        qstrContent =QList[2];


	QRect drawRectTextName=QRect(option.rect.topLeft(), QSize(option.rect.size().width()/2,option.rect.size().height()/4));
	QRect drawRectTextDate=QRect(option.rect.topLeft()+QPoint(option.rect.size().width()/2,0), QSize(option.rect.size().width()/2,option.rect.size().height()/4));
	QRect drawRectTextContent=QRect(option.rect.topLeft()+QPoint(0,option.rect.size().height()/4), QSize(option.rect.size().width(),option.rect.size().height()*3/4));

    //画标题
    painter->setFont(qfTitle);
    painter->setPen(qcTitle);
	painter->drawText(drawRectTextName, qstrName);
    //画日期
	painter->setFont(qfNormal);
    painter->setPen(qcDate);
	painter->drawText(drawRectTextDate, qstrDate);
    //画摘要
	painter->setFont(qfNormal);
    painter->setPen(qcContent);
	painter->drawText(drawRectTextContent, qstrContent);

    //画线
    painter->setPen(qcLine);
	painter->drawLine(option.rect.bottomLeft(),option.rect.bottomRight());

	myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter; // 处理文本的对齐方式 (不重要)  
	drawFocus(painter,option,option.rect);  
}  



void MyQItemDelegate::updateEditorGeometry( QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	editor->setGeometry(option.rect);  
}

void MyQItemDelegate::drawFocus( QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect ) const
{
	//如果有控件被选中，我们就让选中的控件变亮
	if (option.state & QStyle::State_Selected){
		painter->setBrush(QBrush(QColor(157,206,122,122)));
		painter->setPen(QColor(157,206,122,122));
		painter->drawRect(rect);
		painter->setBrush(Qt::NoBrush);
		painter->setPen(Qt::darkGreen);
		painter->drawRect(rect);
	}
}

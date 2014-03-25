#include "tnotescategorylist.h"
#include "Operation.h"
//#include "nwindows.h"
tNotesCategoryList::tNotesCategoryList() : QListView()
{
	setGridSize(QSize(150,70));
	this->setStyleSheet("background-color:#FFFFFF;");
	model = new QStandardItemModel(4,2);  
	model->setHeaderData(0, Qt::Horizontal, tr("Service"));  
	model->setHeaderData(1, Qt::Horizontal, tr("Details"));

	setWordWrap(true);
    QStandardItem *item1 = new QStandardItem(s2q("天气\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
	
    item1->setIcon(QIcon(":/myres/notes.png"));
	item1->setColumnCount(21);

    QStandardItem *item2 = new QStandardItem(s2q("学习\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item2->setIcon(QIcon(":/myres/notes.png"));
    QStandardItem *item3 = new QStandardItem(s2q("运动\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item3->setIcon(QIcon(":/myres/notes.png"));
    QStandardItem *item4 = new QStandardItem(s2q("泡妞\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item4->setIcon(QIcon(":/myres/notes.png"));

    QStandardItem *item5 = new QStandardItem(s2q("泡妞\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item5->setIcon(QIcon(":/myres/notes.png"));

    QStandardItem *item6 = new QStandardItem(s2q("泡妞\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item6->setIcon(QIcon(":/myres/notes.png"));

    QStandardItem *item7 = new QStandardItem(s2q("泡妞\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item7->setIcon(QIcon(":/myres/notes.png"));

    QStandardItem *item8 = new QStandardItem(s2q("泡妞\n随着天气的逐渐转暖，北京楼市成交量也逐周回升，统计数据显示。"));
    item8->setIcon(QIcon(":/myres/notes.png"));

	model->setItem(0, 0, item1); 
	model->setItem(1, 0, item2);  
	model->setItem(2, 0, item3);  
	model->setItem(3, 0, item4);
	model->setItem(4, 0, item5); 
	model->setItem(5, 0, item6); 
	model->setItem(6, 0, item7); 
	model->setItem(7, 0, item8); 

	this->setModel(model);  
}  

void tNotesCategoryList::mouseDoubleClickEvent(QMouseEvent *event)
{  
	if (event->button() == Qt::LeftButton) {  
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
	}  
}

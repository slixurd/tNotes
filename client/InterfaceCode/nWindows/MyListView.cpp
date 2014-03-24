#include "MyListView.h"  
#include "nwindows.h"
MyListView::MyListView() : QListView()  
{
	//setResizeMode(QListWidget::Adjust);
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
	this->setStyleSheet("background-color:#F3F2EF;");
	model = new QStandardItemModel(4,2);  
	model->setHeaderData(0, Qt::Horizontal, tr("Service"));  
	model->setHeaderData(1, Qt::Horizontal, tr("Details"));


	QStandardItem *item1 = new QStandardItem(s2q("I couldn't find in the documentation any instructions how to it.So - how can I set the header text of a QTreeView?"));  
	
	item1->setIcon(QIcon("asset/notes3.png"));
	item1->setColumnCount(21);
	QBrush qbr;
	qbr.setColor("#FFFFFF");
	qbr.setStyle(Qt::Dense3Pattern);
	/*QImage qimg("asset/back0.png");
	qbr.setTextureImage(qimg);*/
	item1->setBackground(qbr);

	QStandardItem *item2 = new QStandardItem(s2q("学习"));  
	item2->setIcon(QIcon("asset/notes3.png"));  
	item2->setBackground(qbr);
	QStandardItem *item3 = new QStandardItem(s2q("运动"));  
	item3->setIcon(QIcon("asset/notes3.png"));
	item3->setBackground(qbr);
	QStandardItem *item4 = new QStandardItem(s2q("泡妞"));  
	item4->setIcon(QIcon("asset/notes3.png")); 
	item4->setBackground(qbr);
	QStandardItem *item5 = new QStandardItem(s2q("活动"));  
	item5->setIcon(QIcon("asset/notes3.png")); 
	item5->setBackground(qbr);
	QStandardItem *item6 = new QStandardItem(s2q("C++"));  
	item6->setIcon(QIcon("asset/notes3.png")); 
	item6->setBackground(qbr);
	QStandardItem *item7 = new QStandardItem(s2q("Java"));  
	item7->setIcon(QIcon("asset/notes3.png")); 
	item7->setBackground(qbr);
	QStandardItem *item8 = new QStandardItem(s2q("组织"));  
	item8->setIcon(QIcon("asset/notes3.png"));
	item8->setBackground(qbr);
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

void MyListView::mouseDoubleClickEvent(QMouseEvent *event)  
{  
	if (event->button() == Qt::LeftButton) {  
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
	}  
}
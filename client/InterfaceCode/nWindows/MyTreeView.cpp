#include "MyTreeView.h"  
TreeView::TreeView() : QTreeView()  
{
	this->setStyleSheet("background-color:#C6E8B3;");
	model = new QStandardItemModel(4,2);  
	model->setHeaderData(0, Qt::Horizontal, tr("Service"));  
	model->setHeaderData(1, Qt::Horizontal, tr("Details"));


	QStandardItem *item1 = new QStandardItem(s2q("Éú»î"));  
	item1->setIcon(QIcon("asset/notes1.png"));
	item1->setColumnCount(21);

	QStandardItem *item2 = new QStandardItem(s2q("Ñ§Ï°"));  
	item2->setIcon(QIcon("asset/notes1.png"));  
	QStandardItem *item3 = new QStandardItem(s2q("ÔË¶¯"));  
	item3->setIcon(QIcon("asset/notes1.png"));   
	QStandardItem *item4 = new QStandardItem(s2q("ÅÝæ¤"));  
	item4->setIcon(QIcon("asset/notes1.png")); 

	QStandardItem *item5 = new QStandardItem(s2q("ÅÝæ¤"));  
	item5->setIcon(QIcon("asset/notes1.png")); 

	QStandardItem *item6 = new QStandardItem(s2q("ÅÝæ¤"));  
	item6->setIcon(QIcon("asset/notes1.png")); 

	QStandardItem *item7 = new QStandardItem(s2q("ÅÝæ¤"));  
	item7->setIcon(QIcon("asset/notes1.png")); 
	model->setItem(0, 0, item1); 
	model->setItem(1, 0, item2);  
	model->setItem(2, 0, item3);  
	model->setItem(3, 0, item4);
	model->setItem(4, 0, item4); 
	model->setItem(5, 0, item5); 
	model->setItem(6, 0, item6); 
	model->setItem(7, 0, item7); 
	QStandardItem *item8 = new QStandardItem("fifth");  
	item7->appendRow(item8);  
	QModelIndex parent;  
	for (int i = 0; i < 4; ++i) {  
		parent = model->index(0, 0, parent);  
		model->insertRows(0, 1, parent);  
		model->insertColumns(0, 1, parent);  
		QModelIndex index = model->index(0, 0, parent);  
		model->setData(index, i);  
	}  
	this->setModel(model);  
}  
QList<QStandardItem*> TreeView::returnTheItems()  
{  
	return model->findItems("*", Qt::MatchWildcard | Qt::MatchRecursive);  
}  
void TreeView::iterateOverItems()  
{  
	QList<QStandardItem*> list = returnTheItems();  

	foreach (QStandardItem* item, list) {  
		qDebug() << item->text();  
	}  
}  
void TreeView::mouseDoubleClickEvent(QMouseEvent *event)  
{  
	if (event->button() == Qt::LeftButton) {  
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
	}  
}
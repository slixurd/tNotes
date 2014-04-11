#include "MyListView2.h"  
#include "nwindows.h"
MyListView2::MyListView2() : QListView()  
{
	qic = QIcon("asset/image/notes5.png");
	setGridSize(QSize(150,70));
	this->setStyleSheet("background-color:#FFFFFF;");
	model = new QStandardItemModel();
	setWordWrap(true);
	this->setModel(model);
}  

void MyListView2::mouseDoubleClickEvent(QMouseEvent *event)  
{  
	if (event->button() == Qt::LeftButton) {  
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
	}  
}
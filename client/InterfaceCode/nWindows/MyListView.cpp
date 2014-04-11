#include "MyListView.h"  
#include "nwindows.h"

MyListView::MyListView() : QListView()  
{
	qic =QIcon("asset/image/notes3.png");
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
	this->setStyleSheet("background-color:#F3F2EF;");
	qbr.setColor("#FFFFFF");
	qbr.setStyle(Qt::Dense3Pattern);
	model = new QStandardItemModel();
	this->setModel(model);
}

void MyListView::mouseDoubleClickEvent(QMouseEvent *event)
{  
	if (event->button() == Qt::LeftButton) {
		QModelIndex index0 = currentIndex();
		qDebug() << index0.data().toString();
	}
}
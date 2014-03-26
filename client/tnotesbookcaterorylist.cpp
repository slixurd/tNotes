
#include "tnotesbookcategorylist.h"

//#include "nwindows.h"
tNotesBookCategoryList::tNotesBookCategoryList() : QListView()
{
	//setResizeMode(QListWidget::Adjust);
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
	this->setStyleSheet("background-color:#F3F2EF;");
    model = new QStandardItemModel();
	model->setHeaderData(0, Qt::Horizontal, tr("Service"));  
	model->setHeaderData(1, Qt::Horizontal, tr("Details"));


    QStandardItem *item1 = new QStandardItem(tr("Notebook list"));
	
    item1->setIcon(QIcon(":/myres/notebook.png"));
	item1->setColumnCount(21);
    QBrush qbr;
	qbr.setColor("#FFFFFF");
	qbr.setStyle(Qt::Dense3Pattern);

	item1->setBackground(qbr);
/*
    QStandardItem *item2 = new QStandardItem(s2q("学习"));
    item2->setIcon(QIcon(":/myres/notebook.png"));
	item2->setBackground(qbr);
    QStandardItem *item3 = new QStandardItem(s2q("运动"));
    item3->setIcon(QIcon(":/myres/notebook.png"));
	item3->setBackground(qbr);
    QStandardItem *item4 = new QStandardItem(s2q("泡妞"));
    item4->setIcon(QIcon(":/myres/notebook.png"));
	item4->setBackground(qbr);
    QStandardItem *item5 = new QStandardItem(s2q("活动"));
    item5->setIcon(QIcon(":/myres/notebook.png"));
	item5->setBackground(qbr);
    QStandardItem *item6 = new QStandardItem(s2q("C++"));
    item6->setIcon(QIcon(":/myres/notebook.png"));
	item6->setBackground(qbr);
    QStandardItem *item7 = new QStandardItem(s2q("Java"));
    item7->setIcon(QIcon(":/myres/notebook.png"));
	item7->setBackground(qbr);
    QStandardItem *item8 = new QStandardItem(s2q("组织"));
    item8->setIcon(QIcon(":/myres/notebook.png"));
	item8->setBackground(qbr);
	model->setItem(0, 0, item1); 
	model->setItem(1, 0, item2);  
	model->setItem(2, 0, item3);  
	model->setItem(3, 0, item4);
	model->setItem(4, 0, item5); 
	model->setItem(5, 0, item6); 
	model->setItem(6, 0, item7); 
	model->setItem(7, 0, item8); 
    */
    model->setItem(0, 0, item1);
	this->setModel(model);

}  

void tNotesBookCategoryList::mouseDoubleClickEvent(QMouseEvent *event)
{  
	if (event->button() == Qt::LeftButton) {  
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
    }
}

void tNotesBookCategoryList::updateNotebooks(QString path)
{
    extern string rootPath;
    //setupRootPath(q2s(path));
    print(s2q(rootPath));
    vector<Directory> categoryList;
    categoryList = searchAllRoot();

    vector<Directory>::const_iterator cii;
    for(cii = categoryList.begin(); cii != categoryList.end(); cii ++)
    {
        std::cout<<(*cii).name<<std::endl;
        appendNotebook(*cii);
    }
}

void tNotesBookCategoryList::appendNotebook(Directory dir)
{
    QBrush qbr;
    qbr.setColor("#FFFFFF");
    qbr.setStyle(Qt::Dense3Pattern);
    QStandardItem *item = new QStandardItem(s2q(dir.name));
    item->setIcon(QIcon(":/myres/notebook.png"));
    item->setBackground(qbr);
    model->appendRow(item);
}

#include "tnotesbookcategorylist.h"

tNotesBookCategoryList::tNotesBookCategoryList() : QListView()
{
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
	this->setStyleSheet("background-color:#F3F2EF;");
    model = new QStandardItemModel();
    QBrush qbr;
	qbr.setColor("#FFFFFF");
	qbr.setStyle(Qt::Dense3Pattern);
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
    dirVectory.push_back(dir);
    QBrush qbr;
    qbr.setColor("#FFFFFF");
    qbr.setStyle(Qt::Dense3Pattern);
    QStandardItem *item = new QStandardItem(s2q(dir.name));
    item->setIcon(QIcon(":/myres/notebook.png"));
    item->setBackground(qbr);
    model->appendRow(item);
}



void tNotesBookCategoryList::deleteNoyebook(QModelIndex&index){
    std::vector<Directory>::iterator it = dirVectory.begin()+index.row();
    dirVectory.erase(it);
    model->removeRow(index.row());
    //????
}

#include "tnotesbookcategorylist.h"
#include "Operation.h"
//#include "nwindows.h"
tNotesBookCategoryList::tNotesBookCategoryList() : QListView()
{
    setIconSize(QSize(40,40));
    setGridSize(QSize(150,40));
    this->setStyleSheet("background-color:#F3F2EF;");
    qbr.setColor("#FFFFFF");
    qbr.setStyle(Qt::Dense3Pattern);
    model = new QStandardItemModel();
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
    }
}

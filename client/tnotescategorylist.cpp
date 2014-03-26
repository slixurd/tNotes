#include "tnotescategorylist.h"
#include "Operation.h"
//#include "nwindows.h"
tNotesCategoryList::tNotesCategoryList() : QListView()
{
    qic = QIcon(":/myres/notebook.png");
    setGridSize(QSize(150,70));
    this->setStyleSheet("background-color:#FFFFFF;");
    model = new QStandardItemModel();
    setWordWrap(true);
    this->setModel(model);
    myqit = new MyQItemDelegate();
    setItemDelegate(myqit);

}

void tNotesCategoryList::mouseDoubleClickEvent(QMouseEvent *event)
{  
    if (event->button() == Qt::LeftButton) {
        QModelIndex index0 = currentIndex();
        qDebug() << index0.data().toString();
    }
}

bool tNotesCategoryList::updateListView(string id){
    dirVector.clear();
    model->clear();
    dirVector = searchRootArticle(id);
    for (int i=0;i<dirVector.size();i++)
    {
        QStandardItem *itemTemp=new QStandardItem(s2q(dirVector[i].name));
        itemTemp->setSizeHint(QSize(150,70));
        model->appendRow(itemTemp);
    }
}
QString tNotesCategoryList::addCategory(QString name){
    QStandardItem *itemTemp=new QStandardItem(name);
    itemTemp->setSizeHint(QSize(150,70));
    model->appendRow(itemTemp);
}


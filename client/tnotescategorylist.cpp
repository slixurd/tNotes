#include "tnotescategorylist.h"

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
    setupActions();
}


void tNotesCategoryList::setupActions()
{
    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(noteSelected(QModelIndex)));
}

void tNotesCategoryList::mouseDoubleClickEvent(QMouseEvent *event)
{  
    if (event->button() == Qt::LeftButton) {
        QListView::edit(currentIndex());
    }
}

bool tNotesCategoryList::updateListView(string id){
    dirVector.clear();
	model->clear();
	dirVector = searchRootArticle(id);
    for (int i=0;i<dirVector.size();i++)
    {
        //传入名字、时间、内容
        QStandardItem *itemTemp=new QStandardItem(s2q(dirVector[i].name+";"
                                +dirVector[i].modifiedTime+";"+dirVector[i].context));
        itemTemp->setSizeHint(QSize(150,70));
        model->appendRow(itemTemp);
    }
}
QString tNotesCategoryList::addCategory(QString name){
    QStandardItem *itemTemp=new QStandardItem(name);
    itemTemp->setSizeHint(QSize(150,70));
    model->appendRow(itemTemp);
}

void tNotesCategoryList::initNotesCategory(string dirId)
{
    currentNotebookId = dirId;
    updateListView(dirId);
}

void tNotesCategoryList::noteSelected(const QModelIndex &index)
{
    string articleId = dirVector[index.row()].articleId;
    emit initNotesEditor(currentNotebookId, articleId);
}

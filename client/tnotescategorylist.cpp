#include "tnotescategorylist.h"

#include "Operation.h"
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
        //QListView::edit(currentIndex());
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

//内存中添加
void tNotesCategoryList::appendCategory(Article art){
    dirVector.push_back(art);
    QStandardItem *itemTemp=new QStandardItem(s2q(art.name+";"+art.createTime+";"+art.context));
    itemTemp->setSizeHint(QSize(150,70));
    model->appendRow(itemTemp);

}

//内存中添加 文件中也添加
void tNotesCategoryList::newCategory(Article art,string iRoot){
    if(createArticle(iRoot,art)){
        appendCategory(art);
        emit initNotesEditor(currentNotebookId, art.articleId);
    }
}

void tNotesCategoryList::deleteCategory(QModelIndex &index,string iRoot){
    std::vector<Article>::iterator it = dirVector.begin()+index.row();
    deleteArticle(iRoot,(*it).articleId);
    dirVector.erase(it);
    model->removeRow(index.row());
}



//slots
void tNotesCategoryList::initNotesCategory(string dirId)
{
    currentNotebookId = dirId;
    updateListView(dirId);
    if(dirVector.size()>=1){
    string articleId = dirVector[0].articleId;
    emit initArticle(dirId, articleId);
    }
}

void tNotesCategoryList::noteSelected(const QModelIndex &index)
{
    string articleId = dirVector[index.row()].articleId;
    emit initNotesEditor(currentNotebookId, articleId);
}

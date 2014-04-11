#include "tnotescategorylist.h"
#include<QDialog>
#include "Operation.h"
tNotesCategoryList::tNotesCategoryList() : QListView()
{
    qic = QIcon(":/myres/notebook.png");
    setGridSize(QSize(150,70));
    this->setStyleSheet(readFile(":/qss/listview1background.qss"));
    model = new QStandardItemModel();
    setWordWrap(true);
    this->setModel(model);
    myqit = new MyQItemDelegate();
    setItemDelegate(myqit);
    setupActions();
}
void tNotesCategoryList::updateIndexView(string iRoot,string iArticle){
    Article artTemp = searchArticle(iRoot,iArticle);
    for(int i=0;i<dirVector.size();i++){
        Article artTempi = dirVector[i];
        if(artTempi.articleId==artTemp.articleId){
            dirVector[i]=artTemp;
            QStandardItem *itemTemp=new QStandardItem(s2q(dirVector[i].name+";"
                                    +dirVector[i].createTime+";"+dirVector[i].context));
            itemTemp->setSizeHint(QSize(150,70));
            model->setItem(i,itemTemp);
            break;
        }
    }
    this->setUpdatesEnabled(true);
    this->update();
}

void tNotesCategoryList::searchToUpdateListView(vector<SearchResult> resultVector, QString searchWord){
    IsSearchResult=true;
    dirVector.clear();
    faId.clear();
    model->clear();
    for(int i=0;i<resultVector.size();i++){
        dirVector.push_back(resultVector[i].article);
        faId.push_back(resultVector[i].dirId);
    }
    for (int i=0;i<dirVector.size();i++)
    {
        //传入名字、时间、内容
        //qDebug()<<"insert item "<< s2q(dirVector[i].name)<<endl;
        QStandardItem *itemTemp=new QStandardItem(s2q(dirVector[i].name+";"
                                +dirVector[i].createTime+";"+dirVector[i].context));
        itemTemp->setSizeHint(QSize(150,70));
        model->appendRow(itemTemp);
    }
    if(resultVector.size()>=1)
    emit initNotesEditor(resultVector[0].dirId, resultVector[0].article.articleId, searchWord);
    tmpSearchWord = searchWord;
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
    IsSearchResult = false;
    dirVector.clear();
	model->clear();
    dirVector = searchRootArticle(id);
    for (int i=0;i<dirVector.size();i++)
    {
        //传入名字、时间、内容
        QStandardItem *itemTemp=new QStandardItem(s2q(dirVector[i].name+";"
                                +dirVector[i].createTime+";"+dirVector[i].context));
        itemTemp->setSizeHint(QSize(150,70));
        model->appendRow(itemTemp);
    }
}
void tNotesCategoryList::clearView(){
   if(!dirVector.empty()&&dirVector.size()>=1) dirVector.clear();
   if(!faId.empty()&&faId.size()>=1)faId.clear();
   model->clear();
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
    if(IsSearchResult)return;
    if(createArticle(iRoot,art)){
        appendCategory(art);
        emit initNotesEditor(currentNotebookId, art.articleId);
    }
}

//内存中删除 文件中也删除
void tNotesCategoryList::deleteCategory(QModelIndex &index,string iRoot){
    if(IsSearchResult)return;
    std::vector<Article>::iterator it = dirVector.begin()+index.row();
    deleteArticle(iRoot,(*it).articleId);
    dirVector.erase(it);
    model->removeRow(index.row());
}



//slots
void tNotesCategoryList::initNotesCategory(string dirId)
{
    IsSearchResult=false;
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
    //qDebug() << "dirId " << s2q(faId[index.row()]) << " articleId" << s2q(articleId) <<endl;
    if(IsSearchResult)emit initNotesEditor(faId[index.row()], articleId, tmpSearchWord);
    else  emit initNotesEditor(currentNotebookId, articleId);
}

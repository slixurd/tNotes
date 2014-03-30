#include "tnotesbookcategorylist.h"
#include "Operation.h"

tNotesBookCategoryList::tNotesBookCategoryList() : QListView()
{
    //设置图标网格大小样式
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
    this->setStyleSheet(readFile(":/qss/listview2background.qss"));

    model = new QStandardItemModel();
    QBrush qbr;
	qbr.setColor("#FFFFFF");
	qbr.setStyle(Qt::Dense3Pattern);
	this->setModel(model);

    //设置信号槽
    setupAction();
}  

void tNotesBookCategoryList::setupAction()
{
    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(notebookSelected(QModelIndex)));
}

void tNotesBookCategoryList::mouseDoubleClickEvent(QMouseEvent *event)
{  
	if (event->button() == Qt::LeftButton) {  
        QListView::edit(currentIndex());
    }
}
//修改了目录名字
void tNotesBookCategoryList::dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight,
const QVector<int> & roles = QVector<int> ()){
    QString qstr = currentIndex().data().toString();
    dirVectory[topLeft.column()].name=q2s(qstr);
    changeRoot( nowDire.nodeId , dirVectory[topLeft.column()].name);
}


//初始化笔记本
void tNotesBookCategoryList::initNotebooks(QString path)
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
    //每次初始化目录就初始化当前目录
    if(categoryList.size()>=1){
        nowDire = categoryList[0];
        emit initNotesCategory(nowDire.nodeId);
    }
}

//删除笔记本（会在内存和文件上删除）
void tNotesBookCategoryList::deleteNotebook(QModelIndex&index){
    std::vector<Directory>::iterator it = dirVectory.begin()+index.row();
    deleteRoot((*it).nodeId);
    dirVectory.erase(it);
    model->removeRow(index.row());


    //????
}

//添加笔记本（会在内存和文件上添加）
void tNotesBookCategoryList::newNotebook(Directory dir)
{
    //内存加入
    //文件加入  [文件如果有重复的id则不会添加]
    if(createRoot(dir))appendNotebook(dir);;
}

//添加笔记本（用于初始化）  不会再文件上添加笔记
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


void tNotesBookCategoryList::notebookSelected(const QModelIndex &index)
{
     nowDire=dirVectory[index.row()];
     string id = dirVectory[index.row()].nodeId;
     emit initNotesCategory(id);
}

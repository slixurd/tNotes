#include "tnotesbookcategorylist.h"


tNotesBookCategoryList::tNotesBookCategoryList() : QListView()
{
    //设置图标网格大小样式
	setIconSize(QSize(40,40));
	setGridSize(QSize(150,40));
	this->setStyleSheet("background-color:#F3F2EF;");

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
		QModelIndex index0 = currentIndex();  
		qDebug() << index0.data().toString();  
    }
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
    if(categoryList.size()>=1)
        nowDire = categoryList[0];
}

//删除笔记本（会在内存和文件上删除）
void tNotesBookCategoryList::deleteNoyebook(QModelIndex&index){
    std::vector<Directory>::iterator it = dirVectory.begin()+index.row();
    dirVectory.erase(it);
    model->removeRow(index.row());
    //????
}

//添加笔记本（会在内存和文件上添加）
void tNotesBookCategoryList::newNotebook(Directory dir)
{
    //内存加入
    appendNotebook(dir);
    //文件加入  [文件如果有重复的id则不会添加]
    createRoot(dir);
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
     string id = dirVectory[index.row()].nodeId;
     emit initNotesCategory(id);
}

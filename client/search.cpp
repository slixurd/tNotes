#include "search.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

search::search(char *path)
{
    friso = friso_new();
    config = friso_new_config();
    friso_init_from_ifile(friso, config, path);//从指定的friso.ini文件中初始化friso和config
}
search::~search()
{
//    friso_free_config(config);//有bug，先注释掉
    friso_free(friso);
}
QString search::segment(char *context)
{
    //创建分词任务&&设置分词内容
    friso_task_t task = friso_new_task();
    fstring text = context;
    friso_set_text( task, text );
    QString temp;
    while ( ( friso_next( friso, config, task ) ) != NULL ) {
        temp=temp+task->hits->word+" ";
    }
    qDebug()<<temp;
    //释放任务
    friso_free_task( task );
    return temp;
}
//连接数据库
bool search::connect(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        qDebug()<<"Database Error"<<db.lastError().text();
        return false;
    }
    return true;
}
//初始化
bool search::init()
{
    QSqlQuery query;
    if(!query.exec("CREATE VIRTUAL TABLE pages USING fts3(id PRIMARY KEY, title, body,tokenize=simple)"))
    {
        qDebug()<<"error: "<<query.lastError().text()<<endl;
        return false;
    }
    return true;
}
//插入
bool search::insert(char *id,char* title,char *body)
{
    QSqlQuery query;
    query.prepare("INSERT INTO pages (id, title, body) VALUES (?,?,?)");
    query.addBindValue(id);
    query.addBindValue(segment(title));
    query.addBindValue(segment(body));
    if(!query.exec())
    {
        qDebug()<<"error: "<<query.lastError().text()<<endl;
        return false;
    }
    return true;
}
//删除
bool search::deleteDB(char *id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM pages where id = ?");
    query.addBindValue(id);
    if(!query.exec())
    {
        qDebug()<<"error: "<<query.lastError().text()<<endl;
        return false;
    }
    return true;
}
//更新
bool search::update(char *id,char *title,char*body)
{
    QSqlQuery query;
    query.prepare("update pages set title=?,body=? where id=?");
    query.addBindValue(segment(title));
    query.addBindValue(segment(body));
    query.addBindValue(id);
    if(!query.exec())
    {
        qDebug()<<"error: "<<query.lastError().text()<<endl;
        return false;
    }
    return true;
}

//查询
bool search::select(char *key)
{
    bool flag=false;
    QSqlQuery query;
    query.prepare("SELECT id,title,body FROM pages WHERE pages MATCH ?");
    query.addBindValue(key);
    if(!query.exec())
    {
        qDebug()<<"error: "<<query.lastError().text()<<endl;
        return false;
    }
    while(query.next())
    {
        qDebug()<<query.value(0).toString()<< query.value(1).toString()<< query.value(2).toString();
        flag=true;
    }
    if(flag==false)
        qDebug()<<"find nothing";
    return true;
}

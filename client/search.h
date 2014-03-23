#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
class QString;
extern "C"
{
#include "friso.h"
}

class search
{
private:
    friso_t friso;
    friso_config_t config;
    QString segment(char *context);
public:
    search(char *path);
    ~search();
    //连接数据库
    bool connect(const QString &dbName);
    //初始化
    bool init();
    //插入
    bool insert(char *id,char* title,char *body);
    //删除
    bool deleteDB(char *id);
    //更新
    bool update(char *id,char *title,char*body);
    //查询
    bool select(char *key);
};

#endif // SEARCH_H

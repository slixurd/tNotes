#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<mysql.h>
#include "config.h"
using namespace std;


class NotesDB{
public:
    NotesDB();
    NotesDB(string,string,string,string);
    ~NotesDB();


    //增加用户
    bool addUser(string,string);
private:
    MYSQL noteDB;
    string host;
    string user;
    string pass;
    string currentDB;
    int port;
};

NotesDB::NotesDB(){
    mysql_init(&noteDB);
    //端口设置为0表示采用mysql的默认3306端口
    port = 0;
    this->host = CONFIG_HOST.c_str();
    this->user = CONFIG_USER.c_str();
    this->pass = CONFIG_PASS.c_str();
    this->currentDB = CONFIG_DB.c_str();
    if(!mysql_real_connect(&noteDB,
                    host.c_str(),
                    user.c_str(),
                    pass.c_str(),
                    currentDB.c_str(),
                    port,NULL,0
                    )){
        cerr<<"MYSQL 初始化失败."<<endl;
        mysql_error(&noteDB);

    }

}
NotesDB::NotesDB(string host,string user,string pass,string db){
    mysql_init(&noteDB);
    //端口设置为0表示采用mysql的默认3306端口
    port = 0;
    this->host = host;
    this->user = user;
    this->pass = pass;
    this->currentDB = db;

    if(!mysql_real_connect(&noteDB,
                    host.c_str(),
                    user.c_str(),
                    pass.c_str(),
                    db.c_str(),
                    port,NULL,0
                    )){
        cerr<<"MYSQL 初始化失败."<<endl;
        mysql_error(&noteDB);
    }

}

NotesDB::~NotesDB(){
    mysql_close(&noteDB);
}

bool NotesDB::addUser(string username,string pass){
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,"INSERT INTO user(username,pass,salt)\
                    VALUE(%s,%s,%s)",username,pass,salt);
    mysql_real_query(&noteDB,query_sql,len);
    

}

int main(){
    NotesDB nDB;
    
    return 0;
}

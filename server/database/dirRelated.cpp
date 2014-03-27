/* 
 * Author: slixurd(xiexiaopeng) 
 */

#include "../noteDB.h"

/***
 * 创建目录
 * 如果返回0,说明插入错误
 * 默认返回插入ID.客户端需要此ID作唯一标识号
 */
long NotesDB::create_dir(string title,string user){
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape[TITLE_LEN];
    mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
    string _title = escape;
    mysql_real_escape_string(&database,escape,user.c_str(),user.length()); 
    string _name = escape;
    len = snprintf(query_sql,MAX_LEN,
                "INSERT INTO node(name,username,modifiedTime) VALUE('%s','%s',CURRENT_TIMESTAMP)",
                _title.c_str(),_name.c_str());
    mysql_real_query(&database,query_sql,len);
    return mysql_insert_id(&database);
        
}


/***
 *  修改笔记所在目录
 * 返回影响行数
 */
int NotesDB::change_dir(long id,long pid){
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,
                "UPDATE articleLocation SET modifiedTime = CURRENT_TIMESTAMP, nodeID = %ld WHERE articleID = %ld",
                pid,id);
    mysql_real_query(&database,query_sql,len);
    return mysql_affected_rows(&database);
}

/***
 * 删除目录
 * 返回被删除的目录下的文件个数
 */
int NotesDB::remove_dir(long id){
    unsigned int len;
    char query_sql[MAX_LEN];
    int effects = this->remove_all_notes_from_dir(id);
    len = snprintf(query_sql,MAX_LEN,
                "DELETE FROM node WHERE nodeID = %ld",
                id);
    //cerr<<query_sql<<endl;
    mysql_real_query(&database,query_sql,len);
    return effects;
}

/***
 * 删除目录
 * 提供2个参数的删除
 * 防止修改POST删除别人的数据
 */
int NotesDB::remove_dir(string username,long id){
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape[MAX_LEN];
    int effects = this->remove_all_notes_from_dir(id);

    mysql_real_escape_string(&database,escape,username.c_str(),username.length()); 
    string _username = escape;
    len = snprintf(query_sql,MAX_LEN,
                "DELETE FROM node WHERE nodeID = %ld AND username = '%s' ",
                id,_username.c_str());
    //cerr<<query_sql<<endl;
    mysql_real_query(&database,query_sql,len);
    if(mysql_affected_rows(&database) == 0 || mysql_affected_rows(&database) == -1)
        return -1;
    return effects;
}

/*
 * 移除目录下所有文件以及关联表
 * 外部不需要调用
 */
int NotesDB::remove_all_notes_from_dir(long pid){
    unsigned int len;
    char query_sql[MAX_LEN];
    //先通过关联表删除文件夹下的所有笔记
    len = snprintf(query_sql,MAX_LEN,
                "DELETE FROM article \
                 WHERE articleID in \
                (SELECT articleID FROM articleLocation \
                WHERE nodeID = %ld);",
                pid);
    mysql_real_query(&database,query_sql,len); 
    int effects = mysql_affected_rows(&database);
    //删除文件夹的关联表
    len = snprintf(query_sql,MAX_LEN,
                "DELETE FROM articleLocation WHERE nodeID = %ld ",
                pid);
    mysql_real_query(&database,query_sql,len);
    return effects;
}

/*
 * 更新目录信息
 * 目前主要是目录名
 */
int NotesDB::update_dir(string title, long id){
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape[MAX_LEN];
    mysql_real_escape_string(&database,escape,title.c_str(),title.length()); 
    string _title = escape;    
    len = snprintf(query_sql,MAX_LEN,
                "UPDATE node SET modifiedTime = CURRENT_TIMESTAMP, name = '%s' WHERE articleID = %ld",
                _title.c_str(),id);
    mysql_real_query(&database,query_sql,len);
    return mysql_affected_rows(&database);    
    
}

bool NotesDB::check_node_exist(const long id){
    
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,
                "SELECT * FROM node WHERE nodeID = %ld",
                id);
    int err = mysql_real_query(&database,query_sql,len);
    if(err != 0)
        cerr<<"database error";
    else{
    
        MYSQL_RES* res = mysql_store_result(&database);
        int num = mysql_num_rows(res); 
        mysql_free_result(res);
        if(num == 0)
            return false;
        else 
            return true;
    }
    return false;
    
}

/*
 * 获取所有文件夹
 * 这里参数返回值标识整个info数组的大小
 * 需要传入一个info的指针.这里采用指针的传引用.数据放置在info中
 */
int NotesDB::get_all_dir(string username,DIR_INFO*& info){
    unsigned int len;
    char query_sql[MAX_LEN];
    string _username = escape(username);
    len = snprintf(query_sql,MAX_LEN,
                "SELECT nodeID,name,UNIX_TIMESTAMP(createTime) as ctime FROM node WHERE username = '%s'",
                _username.c_str());
    mysql_real_query(&database,query_sql,len);
    
    MYSQL_RES* result;
    MYSQL_ROW row;
    unsigned int num_fields;
    unsigned int i,count=0;
    unsigned int num_rows;
    result = mysql_store_result(&database);

    num_fields = mysql_num_fields(result);
    num_rows = mysql_num_rows(result);
    info = new DIR_INFO[num_rows];
    while ((row = mysql_fetch_row(result)))
    {
       /*
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result);
            for(i = 0; i < num_fields; i++){
                printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
           }
      */
       info[count].pid = atoi(row[0]);
       info[count].name = row[1];
       info[count].timestamp = atoi(row[2]);
       count++;
    } 
    /*
        MYSQL_FIELD *field;
        num_fields = mysql_num_fields(result);
        for(i = 0; i < num_fields; i++)
        {
            field = mysql_fetch_field_direct(result, i);
            printf("Field %u is %s\n", i, field->name);
        }
    */
    mysql_free_result(result);
    return count;
}

/*
 * 传入一个vector<int>.
 * 笔记列表放在list中
 * 返回值为总个数
 */
int  NotesDB::get_note_list(string username,long pid,vector<int>& list){
    unsigned int len;
    char query_sql[MAX_LEN];
    string _username = escape(username);
    len = snprintf(query_sql,MAX_LEN,
                   "SELECT articleID FROM articleLocation \
                    LEFT JOIN node ON articleLocation.nodeID = node.nodeID \
                    WHERE articleLocation.nodeID = %ld AND username = '%s'",
                pid,_username.c_str());
    mysql_real_query(&database,query_sql,len);
    
    MYSQL_RES* result;
    MYSQL_ROW row;
    unsigned int count=0;
    result = mysql_store_result(&database);
    while ((row = mysql_fetch_row(result)))
    {
       count++;
       list.push_back(atoi(row[0]));
    }
    mysql_free_result(result);
    return count;
    
}

/*
 * 获取目录最后修改时间
 * 返回值为ul型的时间戳
 */
unsigned long NotesDB::get_dir_mtime(string username,long pid){
    unsigned int len;
    char query_sql[MAX_LEN];
    string _username = escape(username);
    len = snprintf(query_sql,MAX_LEN,
                   "SELECT UNIX_TIMESTAMP(modifiedTime) \
                    FROM node WHERE nodeID = %ld AND username = '%s'",
                pid,_username.c_str());
    mysql_real_query(&database,query_sql,len);
    MYSQL_RES* result;
    MYSQL_ROW row;
    result = mysql_store_result(&database);
    row = mysql_fetch_row(result);
    unsigned long tstamp = atoi(row[0]);
    mysql_free_result(result);
    return tstamp;    
    
}

string NotesDB::escape(string s){
    char escape[MAX_LEN];
    mysql_real_escape_string(&database,escape,s.c_str(),s.length()); 
    string _s = escape;
    return _s;
}
/* 
 * Author: slixurd(xiexiaopeng) 
 */

#include "../noteDB.h"


/***
 * 创建笔记
 * 如果返回0,说明插入错误
 */
long NotesDB::create_note(string title,string content,long parentid){
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape[CONTENT_LEN];
    mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
    string _title = escape;
    mysql_real_escape_string(&database,escape,content.c_str(),content.length()); 
    string _content = escape;
    len = snprintf(query_sql,CONTENT_LEN,
                "INSERT INTO article(name,content,modifiedTime) \
                 VALUE('%s','%s',CURRENT_TIMESTAMP)",
                _title.c_str(),_content.c_str());
    //cerr<<query_sql<<endl;
    mysql_real_query(&database,query_sql,len);
    long autoId = mysql_insert_id(&database);
    
    long pid;
    //如果pid不存在,那么直接放入根目录中
    if(check_node_exist(parentid) == false)
        pid = 0;
    else
        pid = parentid;
    
    
    len = snprintf(query_sql,MAX_LEN,
                "INSERT INTO articleLocation(articleID,nodeID) VALUE('%ld','%ld')",
                autoId,pid);
    //cerr<<query_sql<<endl;
    mysql_real_query(&database,query_sql,len);
    return autoId;
}

/***
 * 更新笔记
 * id是必须要传入的.pid如果不需要更改请置为-1
 * title和content不需要修改的传一个空值
 * 返回值表示影响的行数.如果没有修改任何东西会返回0(包括提交未改变的内容)
 * 如果该笔记已不存在.在change_dir里就会直接返回-1,并且不会进行后续操作
 */
int NotesDB::update_note(string title, string content, long id, long pid = -1){
    unsigned int len;
    char query_sql[MAX_LEN];
    int effect = 0;
    if(pid != -1){
        effect = this->change_dir(id,pid);
    }
    stringstream ss;
    char escape[CONTENT_LEN];
    string _content;
    string sql;
    string _id;
    if(title.empty() && content.empty()){
        return effect;
    }else  if(!title.empty() && content.empty()){
        mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, name = '"+string(escape)+"' ";
    }else if(!content.empty() && title.empty()){
         mysql_real_escape_string(&database,escape,content.substr(0,TITLE_LEN).c_str(),content.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, content = '"+string(escape)+"' ";       
    }else if(!content.empty() && !title.empty()){
        mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, name = '"+string(escape)+"' ";
        mysql_real_escape_string(&database,escape,content.substr(0,TITLE_LEN).c_str(),content.length()); 
        sql += ",content = '"+ string(escape)+"' ";
    }
    ss<<id;ss>>_id;
    sql += " WHERE articleID = "+_id;
        

    mysql_real_query(&database,sql.c_str(),sql.length());
    return mysql_affected_rows(&database);
}
/*
 * 更新笔记
 * 只更新目录ID号
 */
int NotesDB::update_note(long id, long pid){
    int effect = this->change_dir(id,pid);
    return effect;
}

/***
 * 更新笔记
 * 只更新title和content
 * 不需要修改的传一个空值
 */
int NotesDB::update_note(string title, string content,long id){
    unsigned int len;
    char query_sql[MAX_LEN];
    stringstream ss;
    char escape[CONTENT_LEN];
    string _content;
    string sql;
    string _id;
    
    if(title.empty() && content.empty()){
        return 0;
    }else  if(!title.empty() && content.empty()){
        mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, name = '"+string(escape)+"' ";
    }else if(!content.empty() && title.empty()){
         mysql_real_escape_string(&database,escape,content.substr(0,TITLE_LEN).c_str(),content.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, content = '"+string(escape)+"' ";       
    }else if(!content.empty() && !title.empty()){
        mysql_real_escape_string(&database,escape,title.substr(0,TITLE_LEN).c_str(),title.length()); 
        sql = "UPDATE article SET modifiedTime = CURRENT_TIMESTAMP, name = '"+string(escape)+"' ";
        mysql_real_escape_string(&database,escape,content.substr(0,TITLE_LEN).c_str(),content.length()); 
        sql += ",content = '"+ string(escape)+"' ";
    }
    ss<<id;ss>>_id;
    sql += " WHERE articleID = "+_id;
    mysql_real_query(&database,sql.c_str(),sql.length());
    return mysql_affected_rows(&database);
}


/*
 * 删除笔记
 */
int NotesDB::remove_note(long id){
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,
                "DELETE FROM article WHERE articleID = %ld",
                id);
    mysql_real_query(&database,query_sql,len);
    return mysql_affected_rows(&database);
}

/*
 * 获取单条笔记
 * 
 */
int NotesDB::get_note(long id,ARTICLE_INFO*& ai){
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,
                   "SELECT article.articleID,nodeID,name,content,UNIX_TIMESTAMP(article.modifiedTime) \
                    FROM article \
                    LEFT JOIN articleLocation \
                    ON article.articleID = articleLocation.articleID \
                    WHERE article.articleID = %ld; ",
                id);
    mysql_real_query(&database,query_sql,len);
    
    MYSQL_RES* result;
    MYSQL_ROW row;
    unsigned int count=0;
    unsigned int num_rows;
    result = mysql_store_result(&database);
    num_rows = mysql_num_rows(result);
    ai = new ARTICLE_INFO[num_rows];
    unsigned int num_fields;
    num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result)))
    {
       ai[count].id = atoi(row[0]);
       ai[count].pid = atoi(row[1]);
       ai[count].name = row[2];
       ai[count].content = row[3];
       ai[count].timestamp = atoi(row[4]);
       count++;
    }
    mysql_free_result(result);
    return count;    
}
/*
 * 获取*单个*目录下笔记的时间
 * 
 */
int NotesDB::get_notes_time(long pid, ARTICLE_SYNC*& as){
    unsigned int len;
    char query_sql[MAX_LEN];
    len = snprintf(query_sql,MAX_LEN,
                   "SELECT article.articleID,UNIX_TIMESTAMP(article.modifiedTime) \
                    FROM article \
                    LEFT JOIN articleLocation \
                    ON article.articleID = articleLocation.articleID \
                    WHERE nodeID = %ld ",
                pid);
    mysql_real_query(&database,query_sql,len);
    
    MYSQL_RES* result;
    MYSQL_ROW row;
    unsigned int count=0;
    unsigned int num_rows;
    result = mysql_store_result(&database);
    num_rows = mysql_num_rows(result);
    as = new ARTICLE_SYNC[num_rows];
    while ((row = mysql_fetch_row(result)))
    {
       as[count].id = atoi(row[0]);
       as[count].timestamp = atoi(row[1]);
       count++;
    }
    mysql_free_result(result);
    return count;
}

/*
 * 获取单条笔记的brief
 * 
 */
int NotesDB::get_brief(long id,ARTICLE_INFO*& ai){
    int t = this->get_note(id,ai);
    int count = t;
    while(t--){
        ai[t].content = ai[t].content.substr(0,BRIEF_LEN);
    }
    return count;
}
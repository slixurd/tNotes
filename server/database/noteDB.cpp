/* 
 * Author: slixurd(xiexiaopeng) 
 */

#include "../noteDB.h"

NotesDB::NotesDB(){
    mysql_init(&database);
    //端口设置为0表示采用mysql的默认3306端口
    port = 0;
    this->host = CONFIG_HOST.c_str();
    this->user = CONFIG_USER.c_str();
    this->pass = CONFIG_PASS.c_str();
    this->currentDB = CONFIG_DB.c_str();
    if(!mysql_real_connect(&database,
                    host.c_str(),
                    user.c_str(),
                    pass.c_str(),
                    currentDB.c_str(),
                    port,NULL,0
                    )){
        cerr<<"MYSQL 初始化失败."<<endl;
        mysql_error(&database);
    
    }

}
NotesDB::NotesDB(string host,string user,string pass,string db){
    mysql_init(&database);
    //端口设置为0表示采用mysql的默认3306端口
    port = 0;
    this->host = host;
    this->user = user;
    this->pass = pass;
    this->currentDB = db;

    if(!mysql_real_connect(&database,
                    host.c_str(),
                    user.c_str(),
                    pass.c_str(),
                    db.c_str(),
                    port,NULL,0
                    )){
        cerr<<"MYSQL 初始化失败."<<endl;
        mysql_error(&database);
    }

}

NotesDB::~NotesDB(){
    mysql_close(&database);
}

/*
 * 查询是否已经存在该用户名
 * false表示该用户名不存在,可以注册
 * true表示已有此名.
 * 通过select的行数来判断
 */

bool NotesDB::check_user_exist(const string name){
    
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape_sql[MAX_LEN];
    mysql_real_escape_string(&database,escape_sql,name.c_str(),name.length()); 
    string _name = escape_sql;
    len = snprintf(query_sql,MAX_LEN,
                "SELECT username FROM user WHERE username = '%s'",
                _name.c_str());
    int err = mysql_real_query(&database,query_sql,len);
    if(err != 0)
        cerr<<"database error";
    else{
    
        MYSQL_RES* res = mysql_store_result(&database);
        int num = mysql_num_rows(res); 
        //cout<<"col: "<<mysql_field_count(&database)<<endl; 
        //cout<<"row: "<<num<<endl;
        mysql_free_result(res);
        if(num == 0)
            return false;
        else 
            return true;
    }
    return false;
    
}



/*
 * 添加用户,传入参数:用户名,密码.均不需要处理
 * 如果数据库错误或者用户名已被使用无法注册,均返回false
 */
bool NotesDB::add_user(string name,string pass){
    unsigned int len;
    char query_sql[MAX_LEN];

    bool exist = this->check_user_exist(name);
    if(exist == true){
        return false;
    } 
    char escape_sql[MAX_LEN];
    mysql_real_escape_string(&database,escape_sql,name.c_str(),name.length()); 
    string _name = escape_sql;
    //生成随机盐
    string salt = generate_salt();
    //拼接密码并做hash
    string _pass = sha1(pass + salt).substr(0,PASS_LEN);
    int id = this->add_uncatagorized_dir(name);
    len = snprintf(query_sql,MAX_LEN,
                "INSERT INTO user(username,pass,salt,uncatagorized) VALUE('%s','%s','%s',%d)",
                _name.c_str(),_pass.c_str(),salt.c_str(),id);
    //cout<<query_sql<<endl;
    int err = mysql_real_query(&database,query_sql,len);
    if(err)
       return false;
    return true;
    

}
/**
 * 生成随机盐.通过时间和随机数混合以后再hash,取前15位做随机盐
 */
string NotesDB::generate_salt(){
    
    const time_t t = time(NULL);
    srand(time(NULL));
    string t_str;
    stringstream ss;
    ss<<t+(rand()%65535);
    ss>>t_str;
    string _salt = this->sha1(t_str).substr(0,15);
    return _salt;

}
/***
 * 获取随机盐前需要先查找用户是否存在
 * 否则返回null
 * 用于登陆时得到随机盐和密码hash
 */
string NotesDB::get_salt(const string name){
    
    unsigned int len;
    char query_sql[MAX_LEN];
    char escape_sql[MAX_LEN];
    mysql_real_escape_string(&database,escape_sql,name.c_str(),name.length()); 
    string _name = escape_sql;
    len = snprintf(query_sql,MAX_LEN,
                "SELECT salt FROM user WHERE username = '%s'",
                _name.c_str());
    int err = mysql_real_query(&database,query_sql,len);
    if(err != 0)
        cerr<<"database error";
    MYSQL_RES* res = mysql_store_result(&database);
    if(mysql_num_rows(res) == 0)
        return NULL;
    MYSQL_ROW row = mysql_fetch_row(res);
    string _salt = row[0];
    //cout<<"col: "<<mysql_field_count(&database)<<endl; 
    //cout<<"row: "<<num<<endl;
    mysql_free_result(res);
    return _salt; 
}

/***
 * 登陆,判断密码是否匹配
 * 如果不存在用户名也返回false
 * !!!时间允许还是应该在此处生成session
 */
bool NotesDB::login(string name,string pass){

    unsigned int len;
    char query_sql[MAX_LEN];
    //如果用户名不存在,直接返回false
    bool exist = this->check_user_exist(name);
    if(exist == false){
        return false;
    } 
    char escape_sql[MAX_LEN];
    mysql_real_escape_string(&database,escape_sql,name.c_str(),name.length()); 
    string _name = escape_sql;
    //获取随机盐
    string salt = this->get_salt(name);
    string _pass = sha1(pass + salt).substr(0,PASS_LEN);
    len = snprintf(query_sql,MAX_LEN,
                "SELECT pass FROM user WHERE username = '%s'",
                _name.c_str());
    int err = mysql_real_query(&database,query_sql,len);
    
    if(err != 0)
        cerr<<"database error";
    MYSQL_RES* res = mysql_store_result(&database);
    MYSQL_ROW row = mysql_fetch_row(res);
    string correct_pass= row[0];
    mysql_free_result(res);
    cout<<"pass"<<row[0]<<endl; 
    if(correct_pass == _pass)
        return true;
    else
        return false;

}


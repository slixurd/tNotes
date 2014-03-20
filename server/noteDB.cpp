#include "config.h"
#include "noteDB.h"


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
    len = snprintf(query_sql,MAX_LEN,
                "INSERT INTO user(username,pass,salt) VALUE('%s','%s','%s')",
                _name.c_str(),_pass.c_str(),salt.c_str());
    cout<<query_sql<<endl;
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

/*
 * 循环移位
 */
unsigned circleShift(const unsigned& word,const int& bits){
    return (word<<bits) | ((word)>>(32-bits));
}
  
unsigned sha1Fun(const unsigned& B,const unsigned& C,const unsigned& D,const unsigned& t){
  
    switch (t/20){
        case 0:     return (B & C) | ((~B) & D);
        case 2:     return (B & C) | (B & D) | (C & D);
        case 1:
        case 3:     return B ^ C ^ D;
    }
  
    return t;
}
/**
 * 计算SHA1
 */
string NotesDB::sha1(const string& strRaw){
 
    string str(strRaw);
 
    str+=(unsigned char)(0x80);
 
    // 每个字节8位,所以要乘8,左移3位
    while (str.size()<<3 % 512 != 448){
        str+=(char)0;
    }
 
    // 写入原始数据长度
    for (int i(56);i>=0;i-=8){
        str+=(unsigned char)((strRaw.size()<<3) >> i);
    }
 
    const unsigned K[4]={0x5a827999,0x6ed9eba1,0x8f1bbcdc,0xca62c1d6};
    unsigned A(0x67452301),B(0xefcdab89),C(0x98badcfe),D(0x10325476),E(0xc3d2e1f0),T(0);
    unsigned W[80]={0};
 
    // 每次处理64字节,共512位
    for (unsigned i(0);i!=str.size();i+=64){
        // 前16个字为原始数据
        for (unsigned t(0);t!=16;++t){
            // 将4个8位数据放入一个32位变量中
            W[t]=((unsigned)str[i+4*t] & 0xff)<<24 |
                 ((unsigned)str[i+4*t+1] & 0xff)<<16 |
                 ((unsigned)str[i+4*t+2] & 0xff)<<8 |
                 ((unsigned)str[i+4*t+3] & 0xff);
        }
 
        // 填充
        for (unsigned t(16);t!=80;++t){
            W[t]=circleShift(W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16],1);
        }
 
        for (unsigned t(0);t!=80;++t){
            T=circleShift(A,5) + sha1Fun(B,C,D,t) + E + W[t] + K[t/20];
            E=D; 
            D=C; 
            C=circleShift(B,30); 
            B=A; 
            A=T;
        }
 
        A+=0x67452301;
        B+=0xefcdab89;
        C+=0x98badcfe;
        D+=0x10325476;
        E+=0xc3d2e1f0;
    }
 
    stringstream ss;
    ss<<setw(8)<<setfill('0')<<hex<<A<<B<<C<<D<<E;
    ss>>str;
 
    return str;
}


int main(){
    NotesDB n;
    string name="slixurd";
    string pass="123456";
    //cout<<n.add_user(name,pass)<<endl;
    //cout<<n.sha1(pass+n.get_salt(name)).substr(0,PASS_LEN)<<endl;
    //cout<<n.login(name,pass)<<endl;
    return 0;
}

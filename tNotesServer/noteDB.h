/* 
 * Author: slixurd(xiexiaopeng) 
 */
#ifndef NOTE_DB
#define NOTE_DB
#include "config.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <mysql/mysql.h>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

class NotesDB{
public:
    //构造函数和析构函数
    NotesDB();
    NotesDB(string,string,string,string);
    ~NotesDB();


    //用户注册和登陆
    bool add_user(string, string);
    bool login(string, string);
    
    
    //笔记相关
    long create_note(string, string, long);
    int  update_note(string, string, long, long);
    int  update_note(string, string,long);
    int  update_note(long, long);
    int  remove_note(long);
    
    int  get_note(long, ARTICLE_INFO*&);
    int  get_notes_time(long,ARTICLE_SYNC*&);
    int  get_brief(long, ARTICLE_INFO*&);
    unsigned long get_note_mtime(string,long);
    
    //目录相关
    long create_dir(string, string);
    int  update_dir(string,long);
    int  remove_dir(long);
    int  remove_dir(string, long);
    int  get_all_dir(string,DIR_INFO*&);
    int  get_note_list(string,long,vector<int>&);
    unsigned long get_dir_mtime(string,long);

private:
    MYSQL database;
    string host;
    string user;
    string pass;
    string currentDB;
    int port;
    
    //不开放的接口
    string sha1(const string&);
    string get_salt(const string);
    string generate_salt();

    bool check_user_exist(const string);
    bool check_node_exist(const long );
    bool check_permission(string,long);
    int  change_dir(long, long);
    int  remove_all_notes_from_dir(long);
    string escape(string);
};


#endif

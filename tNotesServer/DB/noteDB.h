/* 
 * Author: slixurd(xiexiaopeng) 
 */
#ifndef NOTE_DB
#define NOTE_DB

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
    NotesDB();
    NotesDB(string,string,string,string);
    ~NotesDB();


    //增加用户
    bool add_user(string,string);
    bool login(string,string);
    void init_all_data();
    void pull_note();
    void backup_note();
    long create_note(string,string,long);
    void save_note();
    long create_dir(string,string);
    void remove_dir(long);
    bool remove_dir(string,long);
    void sync_dir();
    string sha1(const string&);
    bool check_user_exist(const string);
    bool check_node_exist(const long );
    string get_salt(const string);
private:
    MYSQL database;
    string host;
    string user;
    string pass;
    string currentDB;
    int port;

    string generate_salt();

};


#endif

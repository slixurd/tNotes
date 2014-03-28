/* 
 * File:   main.cpp
 * Author: slixurd
 *
 * Created on 2014年3月21日, 下午6:46
 */

#include <cstdlib>
#include "noteDB.h"
using namespace std;

/*
 * 
 */

int main(){
    NotesDB n;
    string name="slixurd";
    string pass="123456";
    //cout<<n.add_user(name,pass)<<endl;
    //cout<<n.sha1(pass+n.get_salt(name)).substr(0,PASS_LEN)<<endl;
    //cout<<n.login(name,pass)<<endl;
    string dirname = "study";
    //cout<<n.create_note(dirname,name,1);
    string a;
    string b;
    DIR_INFO *info;
    //int t = n.get_all_dir(name,info);
    ARTICLE_INFO * as;
    /*
    vector<int> list;
    cout<<n.get_note_list(name,2l,list);
    for(vector<string>::size_type i = 0; i < list.size(); ++i)
        cout<<list[i]<<endl;*/
    //cout<<n.get_dir_mtime(name,2);
    
    cout<<n.get_note(100,as);
    return 0;
}

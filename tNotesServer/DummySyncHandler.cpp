/* 
 * File:   SyncHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 31, 2014, 12:58 PM
 */

#include "DummySyncHandler.h"
#include "Exception.hpp"

#include <map>
#include <set>

DummySyncHandler::DummySyncHandler() {
}

DummySyncHandler::~DummySyncHandler() {
}

std::string DummySyncHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("node")
            &&val.isMember("article"))
    {
        sessionKey = val["session"].asString();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
        
    _sessionManager.VeritySession(sessionKey);
    
    //------------------------//
    std::map<unsigned int,Json::Value> node;
    std::set<unsigned int> article;
    
    DIR_INFO* DIR;
    int count = _DB->get_all_dir(_sessionManager.GetSessionInfo(sessionKey).User,
            DIR);
    for(int i = 0;i<count;i++)
    {
        Json::Value vtmp;
        vtmp["id"] = (unsigned int)DIR[i].pid;
        vtmp["name"] = DIR[i].name;
        vtmp["stamp"] = (unsigned int)DIR[i].timestamp;
        
        node[(unsigned int)DIR[i].pid]=vtmp;
        
        vector<int> tmp;
        _DB->get_note_list(_sessionManager.GetSessionInfo(sessionKey).User,
            DIR[i].pid,tmp);
        article.insert(tmp.begin(),tmp.end());
    }
    delete[] DIR;
    //------------------------//
    
    Json::Value article2c,article2d,node2c,node2d;
    if(!val["node"].isNull())
    {
        for(Json::ValueIterator it = val["node"].begin(); it != val["node"].end(); it++ )
        {
            unsigned int id = (*it)["id"].asUInt();
            unsigned int stamp = (*it)["stamp"].asUInt();
            
            if(node.find(id)==node.end())
            {
                node2d.append(id);
            }
            else if(node[id]["stamp"].asUInt()==stamp)
            {
                node.erase(node.find(id));
            }
            
        }
    }
    
    for(std::map<unsigned int,Json::Value>::iterator it = node.begin();
            it!= node.end();it++)
    {
        node2c.append(it->second);
    }

    if(!val["article"].isNull())
    {
        for(Json::ValueIterator it = val["article"].begin(); it != val["article"].end(); it++ )
        {
            unsigned int id = (*it)["id"].asUInt();
            unsigned int stamp = (*it)["stamp"].asUInt();
            
            unsigned int stamp4s = _DB->get_note_mtime(_sessionManager.GetSessionInfo(sessionKey).User,
                    id);
            
            if(stamp4s==0)
            {
                article2d.append(id);
            }
            else if(stamp4s==stamp)
            {
                article.erase(article.find(id));
            }
            
        }
    }
    
    for(std::set<unsigned int>::iterator it = article.begin();
            it != article.end();it++)
    {
        Json::Value tmp;
        ARTICLE_INFO * INFO = 0;
        
        if(_DB->get_note(_sessionManager.GetSessionInfo(sessionKey).User,
                *it,INFO)==0)
            continue;
        
        tmp["id"] = (unsigned int)INFO->id;
        tmp["name"] = INFO->name;
        tmp["stamp"] = (unsigned int)INFO->timestamp;
        tmp["location"] = (unsigned int)INFO->pid;
        tmp["content"] = INFO->content;
        
        delete[] INFO;
        
        article2c.append(tmp);
    }
    
    result["deleted_node"] = node2d;
    result["changed_node"] = node2c;
    result["deleted_article"] = article2d;
    result["changed_article"] = article2c;
    
    return Json2String(result);
}

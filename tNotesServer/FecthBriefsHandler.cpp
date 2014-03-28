/* 
 * File:   FecthBriefsHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 2:30 PM
 */

#include "FecthBriefsHandler.h"

#include "Exception.hpp"

FecthBriefsHandler::FecthBriefsHandler() {
}

FecthBriefsHandler::~FecthBriefsHandler() {
}

std::string FecthBriefsHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey;
    int id;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("id"))
    {
        sessionKey = val["session"].asString();
        id = val["id"].asInt();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);
    
    /*  From here, it may cause some serious bug. 
     *  I don't like this interface, it is shitty! */
    vector<int> list;
    Json::Value article;
    _DB->get_note_list(_sessionManager.GetSessionInfo(sessionKey).User,
            id,
            list);
    for(vector<int>::iterator it = list.begin();it!=list.end();it++)
    {
        Json::Value tmp;
        ARTICLE_INFO * INFO;
        if(_DB->get_brief(*it,INFO)==0)
            continue;
        tmp["id"] = (unsigned int)INFO->id,
	tmp["name"] = INFO->name,
	tmp["stamp"] = (unsigned int)INFO->timestamp,
	tmp["location"]= (unsigned int)INFO->pid,
	tmp["brief"] = INFO ->content;
        article.append(tmp);
        delete[] INFO;
    }
    /* End */
    
    result["article"] = article;
    return Json2String(result);
}
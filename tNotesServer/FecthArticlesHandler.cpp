/* 
 * File:   FecthArticlesHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 2:59 PM
 */

#include "FecthArticlesHandler.h"

#include "Exception.hpp"

FecthArticlesHandler::FecthArticlesHandler() {
}

FecthArticlesHandler::~FecthArticlesHandler() {
}

std::string FecthArticlesHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("id"))
    {
        sessionKey = val["session"].asString();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
        
    _sessionManager.VeritySession(sessionKey);
    
    /*  From here, it may cause some serious bug. 
     *  I don't like this interface get_all_dir(), it is shitty! */
    Json::Value articles;
    for(Json::ValueIterator it = val["id"].begin(); it != val["id"].end(); it++ )
    {
        Json::Value tmp;
        ARTICLE_INFO * INFO = 0;
        
        if(_DB->get_note((*it).asInt(),INFO)==0)
            continue;
        
        tmp["id"] = (unsigned int)INFO->id;
        tmp["name"] = INFO->name;
        tmp["stamp"] = (unsigned int)INFO->timestamp;
        tmp["location"] = (unsigned int)INFO->pid;
        tmp["content"] = INFO->content;
        articles.append(tmp);
        
        delete[] INFO;
    }

    result["article"] = articles;
    /* END */
    
    return Json2String(result);
}
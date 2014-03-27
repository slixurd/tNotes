/* 
 * File:   ChangeArticleHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 4:25 PM
 */

#include "ChangeArticleHandler.h"

#include "Exception.hpp"

ChangeArticleHandler::ChangeArticleHandler() {
}

ChangeArticleHandler::~ChangeArticleHandler() {
}

std::string ChangeArticleHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey,name,content;
    unsigned int id;
    long location = -1;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("id"))
    {
        sessionKey = val["session"].asString();
        id = val["id"].asUInt();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);
    
    if(val.isMember("name"))
    {   
        name = val["name"].asString();
        if(name == "")
            name = " ";
    }
    
    if(val.isMember("content"))
    {   
        content = val["content"].asString();
        if(content == "")
            content = " ";
    }
    
    if(val.isMember("location"))
    {   
        location = val["location"].asUInt();
    }
    
    if(_DB->update_note(name,content,id,location)==0)
    {
        throw ArticleHandlingFailureException();
    }
    
    result["status"] = "success";
    return Json2String(result);
}
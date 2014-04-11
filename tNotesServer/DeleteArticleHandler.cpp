/* 
 * File:   DeleteArticleHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 4:24 PM
 */

#include "DeleteArticleHandler.h"

#include "Exception.hpp"

DeleteArticleHandler::DeleteArticleHandler() {
}

DeleteArticleHandler::~DeleteArticleHandler() {
}


std::string DeleteArticleHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey;
    unsigned int id;
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
    
    if(_DB->remove_note(id)==0)
    {
        throw ArticleHandlingFailureException();
    }
    
    result["status"] = "success";
    return Json2String(result);
}
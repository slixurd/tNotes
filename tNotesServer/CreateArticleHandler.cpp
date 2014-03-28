/* 
 * File:   CreateArticleHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 4:24 PM
 */

#include "CreateArticleHandler.h"

#include "Exception.hpp"

CreateArticleHandler::CreateArticleHandler() {
}

CreateArticleHandler::~CreateArticleHandler() {
}

std::string CreateArticleHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey,name,content;
    unsigned int nodeId;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("name")
            &&val.isMember("content")
            &&val.isMember("location"))
    {
        sessionKey = val["session"].asString();
        name = val["name"].asString();
        content = val["content"].asString();
        nodeId = val["location"].asUInt();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);
    
    unsigned int id = _DB->create_note(name,content,nodeId);
    unsigned int stamp = _DB->get_note_mtime(_sessionManager.GetSessionInfo(sessionKey).User,id);

    result["id"] = id;
    result["name"] = name;
    result["location"] = nodeId;
    result["stamp"] = stamp;
    
    return Json2String(result);
}
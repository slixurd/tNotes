/* 
 * File:   ChangeNode.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 8:12 PM
 */

#include "ChangeNodeHandler.h"

#include "Exception.hpp"

ChangeNodeHandler::ChangeNodeHandler() {
}

ChangeNodeHandler::~ChangeNodeHandler() {
}

std::string ChangeNodeHandler::Handle(std::string const& postStr){
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey,name;
    unsigned int id;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("name")
            &&val.isMember("id"))
    {
        sessionKey = val["session"].asString();
        name = val["name"].asString();
        id = val["id"].asUInt();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);

    if(_DB->update_dir(name,id)<=0)
    {
        throw NodeHandlingFailureException();
    }
    
    result["stamp"] = (unsigned int)_DB->get_dir_mtime(_sessionManager.GetSessionInfo(sessionKey).User,id);

    return Json2String(result);
    
}
/* 
 * File:   CreateNodeHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 7:39 PM
 */

#include "CreateNodeHandler.h"

#include "Exception.hpp"

CreateNodeHandler::CreateNodeHandler() {
}

CreateNodeHandler::~CreateNodeHandler() {
}

std::string CreateNodeHandler::Handle(std::string const& postStr){
    Json::Value val;
    String2Json(postStr,val);
    
    std::string sessionKey,name;
    Json::Value result;
    
    if(val.isMember("session")
            &&val.isMember("name"))
    {
        sessionKey = val["session"].asString();
        name = val["name"].asString();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);
    
    unsigned int stamp = 0;
    unsigned int id = _DB->create_dir(name,_sessionManager.GetSessionInfo(sessionKey).User);
    
    result["id"] = id;
    result["name"] = name;
    result["stamp"] = stamp;
    
    return  Json2String(result); 
}

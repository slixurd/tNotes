/* 
 * File:   DeleteNodeHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 8:12 PM
 */

#include "DeleteNodeHandler.h"

#include "Exception.hpp"

DeleteNodeHandler::DeleteNodeHandler() {
}

DeleteNodeHandler::~DeleteNodeHandler() {
}

std::string DeleteNodeHandler::Handle(std::string const& postStr){
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

    if(_DB->remove_dir(_sessionManager.GetSessionInfo(sessionKey).User,id)==-1)
    {
        throw NodeHandlingFailureException();
    }
    
    result["status"] = "success";
    return Json2String(result);
    
}

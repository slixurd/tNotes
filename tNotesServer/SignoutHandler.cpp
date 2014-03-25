/* 
 * File:   SignoutHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 25, 2014, 11:48 PM
 */

#include "SignoutHandler.h"

#include "Exception.hpp"

SignoutHandler::SignoutHandler() {
}

SignoutHandler::~SignoutHandler() {
}

std::string SignoutHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    std::string sessionKey;
    Json::Value result;
    
    if(val.isMember("session"))
    {
        sessionKey = val["session"].asString();
    }
    else
    {
        throw IncorrectDataFormatException();
    }
    
    _sessionManager.VeritySession(sessionKey);
    _sessionManager.DeleteSession(sessionKey);
    
    result["status"] = "success";
    return Json2String(result);
}

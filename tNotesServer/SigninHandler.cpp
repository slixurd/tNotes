/* 
 * File:   SigninHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 24, 2014, 11:26 PM
 */

#include "SigninHandler.h"

#include "Exception.hpp"

SigninHandler::SigninHandler() {
}

SigninHandler::~SigninHandler() {
}

std::string SigninHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    std::string user,pass;
    Json::Value result;
    
    try{
        if(val.isMember("user")
                &&val.isMember("pass"))
        {
            user = val["user"].asString();
            pass = val["pass"].asString();
        }
        else
        {
            throw IncorrectDataFormatException();
        }
    }catch(...)
    {
        throw IncorrectDataFormatException();
    }
    
    if(_DB->login(user,pass))
    {
        SessionInfo info;
        info.User = user;
        result["status"] = "success";
        result["session"] = _sessionManager.CreateSession(info);
    }
    else
    {
        result["status"] = "incorrect_password";
    }
    
    return Json2String(result);
}


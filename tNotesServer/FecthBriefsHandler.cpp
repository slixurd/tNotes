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
     *  I don't like this interface get_all_dir(), it is shitty! */
    throw UnimplementedMethodException();
    /* End */
    
    return Json2String(result);
}
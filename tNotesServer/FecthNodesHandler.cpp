/* 
 * File:   FecthnodesHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 27, 2014, 12:50 PM
 */

#include "FecthNodesHandler.h"
#include "Exception.hpp"

FecthNodesHandler::FecthNodesHandler() {
}

FecthNodesHandler::~FecthNodesHandler() {
}

std::string FecthNodesHandler::Handle(std::string const& postStr)
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
    
    /*  From here, it may cause some serious bug. 
     *  I don't like this interface get_all_dir(), it is shitty! */
    DIR_INFO* DIR;
    int count = _DB->get_all_dir(_sessionManager.GetSessionInfo(sessionKey).User,DIR);
    Json::Value note;
    for(int i = 0;i<count;i++)
    {
        Json::Value tmp;
        tmp["id"] = (unsigned int)DIR[i].pid;
        tmp["name"] = DIR[i].name;
        tmp["stamp"] = (unsigned int)DIR[i].timestamp;

        note.append(tmp);
    }
    delete[] DIR;
    /* End */
    
    result["note"] = note;
    
    return Json2String(result);
}


/* 
 * File:   SigninHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 24, 2014, 11:26 PM
 */

#include "SigninHandler.h"

SigninHandler::SigninHandler() {
}

SigninHandler::~SigninHandler() {
}

std::string SigninHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    return Json2String(val);
}


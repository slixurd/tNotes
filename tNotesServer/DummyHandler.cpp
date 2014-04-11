/* 
 * File:   DummyHandler.cpp
 * Author: wo1fsea
 * 
 * Created on March 20, 2014, 11:59 PM
 */

#include "DummyHandler.h"

#include "Exception.hpp"

DummyHandler::DummyHandler() {
}

DummyHandler::~DummyHandler() {
}

std::string DummyHandler::Handle(std::string const& postStr)
{
    Json::Value val;
    String2Json(postStr,val);
    return Json2String(val);
}


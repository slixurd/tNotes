/* 
 * File:   DummyHandler.cpp
 * Author: wo1fsea
 * 
 * Created on 2014年3月20日, 下午11:59
 */

#include "DummyHandler.h"

#include "Exception.hpp"

DummyHandler::DummyHandler() {
}

DummyHandler::~DummyHandler() {
}

std::string DummyHandler::Handle(std::string const& str)
{
    Json::Value val;
    String2Json(str,val);
    return Json2String(val);
}


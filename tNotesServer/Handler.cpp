/* 
 * File:   Handler.cpp
 * Author: wo1fsea
 * 
 * Created on 2014年3月20日, 上午1:26
 */

#include "Handler.h"

#include "Exception.hpp"

Handler::Handler() {
}

Handler::~Handler() {
}

void Handler::String2Json(std::string const& str, Json::Value& val){
    Json::Reader reader;
    
    if(!reader.parse(str,val))
    {
        throw IncorrectDataFormatException();
    }
}

std::string Handler::Json2String(Json::Value const& val){
    return Json::StyledWriter().write(val);
}

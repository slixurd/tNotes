/* 
 * File:   Handler.h
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 上午1:26
 */

#ifndef HANDLER_H
#define	HANDLER_H

#include <string>

#include "jsoncpp/json/json.h"

/* Base Handler 4 Features */
class Handler {
public:
    Handler();
    virtual ~Handler();
    
    void String2Json(std::string const& str, Json::Value& val);
    std::string Json2String(Json::Value const& val);
    
    virtual std::string Handle(std::string const& postStr) = 0;
private:

};

/* Macro Helper */
 
#define CREATE_HANDLER(HandlerName,SctiptName)          \
 if(scriptName==SctiptName){                            \
       return new HandlerName();                        \
 }else  

#endif	/* HANDLER_H */


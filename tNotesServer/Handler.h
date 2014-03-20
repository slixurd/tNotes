/* 
 * File:   Handler.h
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 上午1:26
 */

#ifndef HANDLER_H
#define	HANDLER_H

#include <string>

#include "json/json.h"

class Handler {
public:
    Handler();
    virtual ~Handler();
    
    void String2Json(std::string const&, Json::Value&);
    std::string Json2String(Json::Value const&);
    
    virtual std::string Handle(std::string const&) = 0;
private:

};

#endif	/* HANDLER_H */


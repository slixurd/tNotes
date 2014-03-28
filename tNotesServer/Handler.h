/* 
 * File:   Handler.h
 * Author: wo1fsea
 * 
 * Created on March 20, 2014, 1:26 AM
 */

#ifndef HANDLER_H
#define	HANDLER_H

#include <string>

#include "jsoncpp/json/json.h"

#include "SessionManager.h"
#include "SingletonAdapter.hpp"
#include "noteDB.h"

/* Base Handler 4 Features */
class Handler {
public:
    Handler();
    virtual ~Handler();
    
    void String2Json(std::string const& str, Json::Value& val);
    std::string Json2String(Json::Value const& val);
    
    virtual std::string Handle(std::string const& postStr) = 0;

protected:
     SessionManager _sessionManager;
     SingletonAdapter<NotesDB> _DB;
     
private:

};

/* Macro Helper */
 
#define CREATE_HANDLER(HandlerName,SctiptName)          \
 if(scriptName==SctiptName){                            \
       return new HandlerName();                        \
 }else  

#endif	/* HANDLER_H */


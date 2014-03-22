/* 
 * File:   HandlerFactory.h
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 上午1:22
 */

#ifndef HANDLERFACTORY_H
#define	HANDLERFACTORY_H

#include <string>

#include "Handler.h"

/* Use the simple factory pattern, HandlerFactory is a simple factory class. */
class HandlerFactory {
public:
    HandlerFactory();
    virtual ~HandlerFactory();
    
    Handler *CreatHandler(std::string const& scriptName);
private:

};

#endif	/* HANDLERFACTORY_H */


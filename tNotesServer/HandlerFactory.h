/* 
 * File:   HandlerFactory.h
 * Author: wo1fsea
 * 
 * Created on March 20, 2014, 1:22 AM
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


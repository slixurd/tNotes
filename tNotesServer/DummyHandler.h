/* 
 * File:   DummyHandler.h
 * Author: wo1fsea
 *
 * Created on March 20, 2014, 11:59 PM
 */

#ifndef DUMMYHANDLER_H
#define	DUMMYHANDLER_H

#include "Handler.h"

/* DummyHandler is a feature handler example. */
class DummyHandler: public Handler {
public:
    DummyHandler();
    virtual ~DummyHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* DUMMYHANDLER_H */


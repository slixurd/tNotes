/* 
 * File:   DummyHandler.h
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 下午11:59
 */

#ifndef DUMMYHANDLER_H
#define	DUMMYHANDLER_H

#include "Handler.h"

class DummyHandler: public Handler {
public:
    DummyHandler();
    virtual ~DummyHandler();
    
    std::string Handle(std::string const&);
};

#endif	/* DUMMYHANDLER_H */


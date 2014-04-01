/* 
 * File:   DummySyncHandler.h
 * Author: wo1fsea
 *
 * Created on March 31, 2014, 12:58 PM
 */

#include "Handler.h"

#ifndef DUMMYSYNCHANDLER_H
#define	DUMMYSYNCHANDLER_H

class DummySyncHandler : public Handler {
public:
    DummySyncHandler();
    virtual ~DummySyncHandler();

    std::string Handle(std::string const& postStr);
};

#endif	/* DUMMYSYNCHANDLER_H */


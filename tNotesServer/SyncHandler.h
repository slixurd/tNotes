/* 
 * File:   SyncHandler.h
 * Author: wo1fsea
 *
 * Created on March 31, 2014, 12:58 PM
 */

#include "Handler.h"

#ifndef SYNCHANDLER_H
#define	SYNCHANDLER_H

class SyncHandler : public Handler {
public:
    SyncHandler();
    virtual ~SyncHandler();

    std::string Handle(std::string const& postStr);
};

#endif	/* SYNCHANDLER_H */


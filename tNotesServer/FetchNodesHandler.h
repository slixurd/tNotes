/* 
 * File:   FetchNodesHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 12:50 PM
 */

#ifndef FETCHNODESHANDLER_H
#define	FETCHNODESHANDLER_H

#include "Handler.h"

/* FetchNodesHandler 4 fetching all the user's nodes */
class FetchNodesHandler: public Handler {
public:
    FetchNodesHandler();
    virtual ~FetchNodesHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* FETCHNODESHANDLER_H */


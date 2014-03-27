/* 
 * File:   FecthNodesHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 12:50 PM
 */

#ifndef FECTHNODESHANDLER_H
#define	FECTHNODESHANDLER_H

#include "Handler.h"

/* FecthNodesHandler 4 fecthing all the user's nodes */
class FecthNodesHandler: public Handler {
public:
    FecthNodesHandler();
    virtual ~FecthNodesHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* FECTHNODESHANDLER_H */


/* 
 * File:   FetchBriefsHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 2:30 PM
 */

#ifndef FETCHBRIEFSHANDLER_H
#define	FETCHBRIEFSHANDLER_H

#include "Handler.h"

class FetchBriefsHandler : public Handler {
public:
    FetchBriefsHandler();
    virtual ~FetchBriefsHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* FETCHBRIEFSHANDLER_H */


/* 
 * File:   FecthBriefsHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 2:30 PM
 */

#ifndef FECTHBRIEFSHANDLER_H
#define	FECTHBRIEFSHANDLER_H

#include "Handler.h"

class FecthBriefsHandler : public Handler {
public:
    FecthBriefsHandler();
    virtual ~FecthBriefsHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* FECTHBRIEFSHANDLER_H */


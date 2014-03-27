/* 
 * File:   CreateNodeHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 7:39 PM
 */

#ifndef CREATENODEHANDLER_H
#define	CREATENODEHANDLER_H

#include "Handler.h"

class CreateNodeHandler : public Handler{
public:
    CreateNodeHandler();
    virtual ~CreateNodeHandler();
    
    std::string Handle(std::string const& postStr);

};

#endif	/* CREATENODEHANDLER_H */


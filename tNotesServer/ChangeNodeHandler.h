/* 
 * File:   ChangeNodeHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 8:12 PM
 */

#ifndef CHANGENODEHANDLER_H
#define	CHANGENODEHANDLER_H

#include "Handler.h"

class ChangeNodeHandler: public Handler{
public:
    ChangeNodeHandler();
    virtual ~ChangeNodeHandler();
    
    std::string Handle(std::string const& postStr);

};

#endif	/* CHANGENODEHANDLER_H */


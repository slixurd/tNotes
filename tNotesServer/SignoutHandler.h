/* 
 * File:   SignoutHandler.h
 * Author: wo1fsea
 *
 * Created on March 25, 2014, 11:48 PM
 */

#ifndef SIGNOUTHANDLER_H
#define	SIGNOUTHANDLER_H
 
#include "Handler.h"

/* Sign Out Feature */
class SignoutHandler: public Handler{
public:
    SignoutHandler();
    virtual ~SignoutHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* SIGNOUTHANDLER_H */


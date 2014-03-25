/* 
 * File:   SigninHandler.h
 * Author: wo1fsea
 *
 * Created on March 24, 2014, 11:26 PM
 */

#ifndef SIGNINHANDLER_H
#define	SIGNINHANDLER_H

class SigninHandler : public Handler{
public:
    SigninHandler();
    virtual ~SigninHandler();
    
    std::string Handle(std::string const& postStr);
};

#endif	/* SIGNINHANDLER_H */


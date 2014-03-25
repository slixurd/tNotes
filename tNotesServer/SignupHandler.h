/*
 *File:		SignupHandler.h
 *Author:	黄嘉斌
 *
 *Created on 2014.3.24
 */
 
#ifndef SIGNUPHANDLER_H
#define SIGNUPHANDLER_H
 
#include "Handler.h"
#include "json/json.h"

/*SignupHandler for user sign up*/
class SignupHandler: public Handler{
public:
	SignupHandler();
	virtual ~SignupHandler();
	
	std::string Handle(std::string const& postStr);
};
 
#endif

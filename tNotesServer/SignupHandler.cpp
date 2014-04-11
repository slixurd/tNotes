/*
 *File:		SignupHandler.cpp
 *Author:	黄嘉斌
 *
 *Created on 2014.3.24
 */
 
#include "SignupHandler.h"
#include "Exception.hpp"
 
SignupHandler::SignupHandler(){
}

SignupHandler::~SignupHandler(){
}

std::string SignupHandler::Handle(std::string const& postStr){
	Json::Value val;
	Json::Reader reader;
	
	if (reader.parse(postStr, val)){
                if(!val.isMember("user")
                    ||!val.isMember("pass")){
			throw IncorrectDataFormatException();
		}
		
		std::string username = val["user"].asString();
		std::string psw = val["pass"].asString();
		
		std::string status = "used_username";
		if (_DB->add_user(username, psw)){
				status = "success";
		}
		Json::Value result;
		result["status"] = status;
		return result.toStyledString();
	}
	else{
		throw IncorrectDataFormatException();
	}
}

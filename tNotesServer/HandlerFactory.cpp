/* 
 * File:   HandlerFactory.cpp
 * Author: wo1fsea
 * 
 * Created on 2014年3月20日, 上午1:22
 */

#include "HandlerFactory.h"
#include "Exception.hpp"

#include "HandlerFactoryConfigure.h"

HandlerFactory::HandlerFactory() {
}

HandlerFactory::~HandlerFactory() {
}

Handler* HandlerFactory::CreatHandler(std::string const& scriptName){
    CREATE_HANDLERS
    throw IncorrectURLException();
}


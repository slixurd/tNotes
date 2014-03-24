/* 
 * File:   HandlerFactory.cpp
 * Author: wo1fsea
 * 
 * Created on March 20, 2014, 1:22 AM
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


/* 
 * File:   SimpleFactory.cpp
 * Author: wo1fsea
 * 
 * Created on 2014年3月20日, 上午1:22
 */

#include "SimpleFactory.h"

/* The Handler List*/
#include "DummyHandler.h"

SimpleFactory::SimpleFactory() {
}

SimpleFactory::~SimpleFactory() {
}

Handler* SimpleFactory::CreatHandler(std::string const& name){
    if(name=="/dummy.cgi")
        return new DummyHandler();
    
    return NULL;
}


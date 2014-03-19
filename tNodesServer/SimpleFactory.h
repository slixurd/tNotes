/* 
 * File:   SimpleFactory.h
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 上午1:22
 */

#ifndef SIMPLEFACTORY_H
#define	SIMPLEFACTORY_H

#include <string>

#include "Handler.h"

class SimpleFactory {
public:
    SimpleFactory();
    virtual ~SimpleFactory();
    
    Handler *CreatHandler(std::string);
private:

};

#endif	/* SIMPLEFACTORY_H */


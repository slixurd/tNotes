/* 
 * File:   CreateArticleHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 4:24 PM
 */

#ifndef CREATEARTICLEHANDLER_H
#define	CREATEARTICLEHANDLER_H

#include "Handler.h"

class CreateArticleHandler : public Handler {
public:
    CreateArticleHandler();
    virtual ~CreateArticleHandler();
    
    std::string Handle(std::string const& postStr);

};

#endif	/* CREATEARTICLEHANDLER_H */


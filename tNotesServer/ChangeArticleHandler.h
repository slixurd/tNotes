/* 
 * File:   ChangeArticleHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 4:25 PM
 */

#ifndef CHANGEARTICLEHANDLER_H
#define	CHANGEARTICLEHANDLER_H

#include "Handler.h"

class ChangeArticleHandler : public Handler {
public:
    ChangeArticleHandler();
    virtual ~ChangeArticleHandler();

    std::string Handle(std::string const& postStr);

};

#endif	/* CHANGEARTICLEHANDLER_H */


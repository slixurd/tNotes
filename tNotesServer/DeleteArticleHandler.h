/* 
 * File:   DeleteArticleHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 4:24 PM
 */

#ifndef DELETEARTICLEHANDLER_H
#define	DELETEARTICLEHANDLER_H

#include "Handler.h"

class DeleteArticleHandler : public Handler {
public:
    DeleteArticleHandler();
    virtual ~DeleteArticleHandler();

    std::string Handle(std::string const& postStr);
};

#endif	/* DELETEARTICLEHANDLER_H */


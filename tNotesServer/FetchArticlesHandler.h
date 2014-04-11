/* 
 * File:   FetchArticlesHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 2:59 PM
 */

#ifndef FETCHARTICLESHANDLER_H
#define	FETCHARTICLESHANDLER_H

#include "Handler.h"

class FetchArticlesHandler: public Handler {
public:
    FetchArticlesHandler();
    virtual ~FetchArticlesHandler();

    std::string Handle(std::string const& postStr);
};

#endif	/* FETCHARTICLESHANDLER_H */


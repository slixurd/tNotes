/* 
 * File:   FecthArticlesHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 2:59 PM
 */

#ifndef FECTHARTICLESHANDLER_H
#define	FECTHARTICLESHANDLER_H

#include "Handler.h"

class FecthArticlesHandler: public Handler {
public:
    FecthArticlesHandler();
    virtual ~FecthArticlesHandler();

    std::string Handle(std::string const& postStr);
};

#endif	/* FECTHARTICLESHANDLER_H */


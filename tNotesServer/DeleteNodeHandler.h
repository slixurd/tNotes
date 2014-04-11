/* 
 * File:   DeleteNodeHandler.h
 * Author: wo1fsea
 *
 * Created on March 27, 2014, 8:12 PM
 */

#ifndef DELETENODEHANDLER_H
#define	DELETENODEHANDLER_H

#include "Handler.h"

class DeleteNodeHandler: public Handler {
public:
    DeleteNodeHandler();
    virtual ~DeleteNodeHandler();

    std::string Handle(std::string const& postStr);

};

#endif	/* DELETENODEHANDLER_H */


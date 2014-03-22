/* 
 * File:   HandlerFactoryConfigure.h
 * Author: wo1fsea
 *
 * Created on 2014年3月22日, 下午10:46
 */

#ifndef HANDLERFACTORYCONFIGURE_H
#define	HANDLERFACTORYCONFIGURE_H

/* The Handler List*/
/* For a new feature handler, add c++ head here. */
/* For example: 
 *      #include "DummyHandler.h"
 */
#include "Handler.h"
#include "DummyHandler.h"


/* For a new feature handler, add the macro here. */
/* For example: 
 *      CREATE_HANDLER(DummyHandler,"/dummy.cgi")  
 */
#define CREATE_HANDLERS                                 \
 CREATE_HANDLER(DummyHandler,"/dummy.cgi")              \


#endif	/* HANDLERFACTORYCONFIGURE_H */


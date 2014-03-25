/* 
 * File:   HandlerFactoryConfigure.h
 * Author: wo1fsea
 *
 * Created on March 22, 2014, 10:56 PM
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
#include "SigninHandler.h"
#include "SignoutHandler.h"
#include "SignupHandler.h"

/* For a new feature handler, add the macro here. */
/* For example: 
 *      CREATE_HANDLER(DummyHandler,"/dummy.cgi")  
 */
#define CREATE_HANDLERS                                 \
 CREATE_HANDLER(DummyHandler,"/dummy.cgi")              \
 CREATE_HANDLER(SigninHandler,"/signin.cgi")            \
 CREATE_HANDLER(SignoutHandler,"/signout.cgi")          \
 CREATE_HANDLER(SignupHandler,"/signup.cgi") 
         
#endif	/* HANDLERFACTORYCONFIGURE_H */


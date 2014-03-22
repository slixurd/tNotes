/* 
 * File:   Exception.hpp
 * Author: wo1fsea
 *
 * Created on 2014年3月20日, 下午10:14
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <exception>

/* Base Exeption */
class Exception : public std::exception{
public:
    Exception() throw(){}
    virtual ~Exception() throw(){}

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char* what() const throw(){
        return "Undefined Exception";
    }
};

/* Unimplemented Method Exception 4 Developing */
class UnimplementedMethodException: public Exception{
public:
    const char* what() const throw(){
        return "Unimplemented Method";
    }
};

/* Incorrect Data Format Exception 4 Handling Json Data */
class IncorrectDataFormatException: public Exception{
public:
    const char* what() const throw(){
        return "Incorrect Data Format";
    }
};

/* Session Failure Exception */
class SessionFailureException: public Exception{
public:
    const char* what() const throw(){
        return "Session Failure";
    }
};

#endif	/* EXCEPTION_HPP */


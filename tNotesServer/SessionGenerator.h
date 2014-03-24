/* 
 * File:   SessionGenerator.h
 * Author: wo1fsea
 *
 * Created on March 21, 2014, 10:27 PM
 */

#ifndef SESSIONGENERATOR_H
#define	SESSIONGENERATOR_H

#include <string>

class SessionGenerator {
public:
    SessionGenerator();
    ~SessionGenerator();
    
    std::string Generate();
private:
    static const int __sessionKeyLen = 32;
    static long long  __seed;
};

#endif	/* SESSIONGENERATOR_H */


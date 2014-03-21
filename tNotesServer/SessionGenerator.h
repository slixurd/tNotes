/* 
 * File:   SessionGenerator.h
 * Author: wo1fsea
 *
 * Created on 2014年3月21日, 下午10:27
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


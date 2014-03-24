/* 
 * File:   SessionGenerator.cpp
 * Author: wo1fsea
 * 
 * Created on March 21, 2014, 10:27 PM
 */

#include "SessionGenerator.h"
#include "stdlib.h"

long long  SessionGenerator::__seed = 0;

SessionGenerator::SessionGenerator() {
    if(__seed!=0)
        return;
    
    /* Use time as the random seed */
    time_t now;
    time(&now);
    __seed = now;
}

SessionGenerator::~SessionGenerator() {
}

/* Warning: Collisions may occur, when the number of Session is greater than 10k.*/
std::string SessionGenerator::Generate() {
    using std::string;

    char sessionKey[__sessionKeyLen+1];
    
    srand(__seed);
    __seed = rand();
    for (int i = 0; i < __sessionKeyLen; i++) {
        srand(__seed);
        __seed = rand();
        sessionKey[i] = __seed % 26 + 'A';
    }
    sessionKey[__sessionKeyLen] = '\0';

    return string(sessionKey);
}

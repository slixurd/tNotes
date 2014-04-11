/* 
 * File:   UnitTest4SessionCache.cpp
 * Author: wo1fsea
 * 
 * Created on March 21, 2014, 7:07 PM
 */

#include <stdlib.h>
#include <iostream>

#include "SessionCache.h"
#include "SessionManager.h"

/*
 * Simple C++ Test 4 SeesionCache
 */

std::string Generate() {
    using std::string;

    static int seed = 0;
    char sessionKey[32+1];
    
    srand(seed);
    seed = rand();
    for (int i = 0; i < 32; i++) {
        srand(seed);
        seed = rand();
        sessionKey[i] = seed % 26 + 'A';
    }
    sessionKey[32] = '\0';

    return string(sessionKey);
}

void test1() {
    SessionCache* cache = SessionCache::GetInstant();
    std::string keys[200];
    
    for(int i = 0; i<200; i++)
    {
        SessionInfo si;
        keys[i] = Generate();

        if(cache->IsExist(keys[i]))
            std::cout <<keys[i]<< std::endl;
        
        si.User = keys[i];
        cache->Set(keys[i] ,si);
        if(!cache->IsExist(keys[i])
                ||cache->Get(keys[i]).User!=keys[i])
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Store Error" << std::endl;
        }
    }
    
    for(int i = 0; i<200; i++)
    {
        if(i>=100 && !cache->IsExist(keys[i])
                ||i<100 && cache->IsExist(keys[i]))
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Rank Error" << std::endl;
        }
    }
    
    for(int i = 100; i<200; i++)
    {
        if(i%2==0)
            cache->Erase(keys[i]);
    }
    
    for(int i = 100; i<200; i++)
    {
        if(i%2==0 && cache->IsExist(keys[i])
                ||i%2!=0 && !cache->IsExist(keys[i]))
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Erase Error" << std::endl;
        }
    }
    
    std::cout << "UnitTest4SessionCache test 1" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% UnitTest4SessionCache" << std::endl;
    
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (UnitTest4SessionCache)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (UnitTest4SessionCache)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


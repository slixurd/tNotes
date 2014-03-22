/* 
 * File:   UnitTest4SessionCache.cpp
 * Author: wo1fsea
 *
 * Created on 2014-3-21, 19:07:55
 */

#include <stdlib.h>
#include <iostream>

#include "SessionCache.h"
#include "SessionGenerator.h"

/*
 * Simple C++ Test 4 SeesionCache
 */

void test1() {
    SessionCache* cache = SessionCache::GetInstant();
    SessionGenerator gen;
    std::string keys[SESSION_CACHE_CAPCITY+20];
    std::cout << SESSION_CACHE_CAPCITY << std::endl;
    
    for(int i = 0; i<SESSION_CACHE_CAPCITY+20; i++)
    {
        SessionInfo si;
        keys[i] = gen.Generate();

        if(cache->IsSessionExist(keys[i]))
            std::cout <<keys[i]<< std::endl;
        
        si.User = keys[i];
        cache->SetSession(keys[i] ,si);
        if(!cache->IsSessionExist(keys[i])
                ||cache->GetSession(keys[i]).User!=keys[i])
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Store Error" << std::endl;
        }
    }
    
    for(int i = 0; i<SESSION_CACHE_CAPCITY+20; i++)
    {
        if(i>=20 && !cache->IsSessionExist(keys[i])
                ||i<20 && cache->IsSessionExist(keys[i]))
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


/* 
 * File:   UnitTest4SessionCache.cpp
 * Author: wo1fsea
 *
 * Created on 2014-3-21, 19:07:55
 */

#include <stdlib.h>
#include <iostream>

#define SESSION_CACHE_CAPCITY 10
#include "SessionCache.h"

/*
 * Simple C++ Test 4 SeesionCache
 */

void test1() {
    SessionCache* cache = SessionCache::GetInstant();
    
    for(char c = 'a'; c <= 'z'; c++)
    {
        std::string str = "";
        str.push_back(c);
        SessionInfo si;
        si.user = str+str;
        cache->SetSession(str,si);
        if(!cache->IsSessionExist(str)
                ||cache->GetSession(str).user!=str+str)
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Store Error" << std::endl;
        }
    }
    
    for(char c = 'a'; c <= 'z'; c++)
    {
        std::string str = "";
        str.push_back(c);
        if(c<='z'-SESSION_CACHE_CAPCITY && cache->IsSessionExist(str)
                ||c>'z'-SESSION_CACHE_CAPCITY && !cache->IsSessionExist(str))
        {
            std::cout << "%TEST_FAILED% time=0 testname=test1 (UnitTest4SessionCache) message=Cache Erase Error" << std::endl;
        }
    }
    
    std::cout << "UnitTest4SessionCache test 1" << std::endl;
}

void test2() {
    std::cout << "UnitTest4SessionCache test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (UnitTest4SessionCache) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% UnitTest4SessionCache" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (UnitTest4SessionCache)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (UnitTest4SessionCache)" << std::endl;

//    std::cout << "%TEST_STARTED% test2 (UnitTest4SessionCache)\n" << std::endl;
//    test2();
//    std::cout << "%TEST_FINISHED% time=0 test2 (UnitTest4SessionCache)" << std::endl;
//
//    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


/* 
 * File:   UnitTest4SyncHandler.cpp
 * Author: wo1fsea
 *
 * Created on 2014-3-31, 13:45:37
 */

#include <stdlib.h>
#include <iostream>

#include "SyncHandler.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::string str = "{\
\"session\": \"GIMVAVCQPSKPDWUWQGJHDEVYYXXJVTRX\",\
\"article\": [\
        {\
            \"id\": 88,\
            \"stamp\": 139618552\
        },\
        {\
            \"id\": 102,\
            \"stamp\": 1396233295\
        },\
        {\
            \"id\": 103,\
            \"stamp\": 1396233303\
        }\
    ],\
\"node\": []\
}";
    SyncHandler sHandler;
    str = sHandler.Handle(str);
    std::cout << "UnitTest4SyncHandler test 1" << std::endl;
}

void test2() {
    std::cout << "UnitTest4SyncHandler test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (UnitTest4SyncHandler) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% UnitTest4SyncHandler" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (UnitTest4SyncHandler)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (UnitTest4SyncHandler)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


/* 
 * File:   UnitTest4SigninHandler.cpp
 * Author: wo1fsea
 *
 * Created on Mar 25, 2014, 6:43:48 PM
 */

#include <stdlib.h>
#include <iostream>

#include "SigninHandler.h"
#include "SignupHandler.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::string post = "{\n \"user\":\"test\",\"pass\":\"test\"}";
    SignupHandler suhandler;
    std::string re0 = suhandler.Handle(post);
    SigninHandler handler;
    std::string re = handler.Handle(post);
    std::cout << "UnitTest4SigninHandler test 1" << std::endl;
}

void test2() {
    std::cout << "UnitTest4SigninHandler test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (UnitTest4SigninHandler) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% UnitTest4SigninHandler" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (UnitTest4SigninHandler)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (UnitTest4SigninHandler)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (UnitTest4SigninHandler)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (UnitTest4SigninHandler)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


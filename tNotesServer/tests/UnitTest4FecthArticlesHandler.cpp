/* 
 * File:   UnitTest4FecthArticlesHandler.cpp
 * Author: wo1fsea
 *
 * Created on Mar 28, 2014, 12:59:57 PM
 */

#include <stdlib.h>
#include <iostream>

#include "FecthArticlesHandler.h"
#include "ChangeNodeHandler.h"
/*
 * Simple C++ Test Suite
 */

void test1() {
    std::string str = "{ \"session\" : \"JCCEMNTBPEXVWMLXDPZGAAFBBZNYKGZW\",\"id\":[1]}";
    FecthArticlesHandler fHandler;
    str = fHandler.Handle(str);
    std::cout << "UnitTest4FecthArticlesHandler test 1" << std::endl;
}

void test2() {
    std::cout << "UnitTest4FecthArticlesHandler test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (UnitTest4FecthArticlesHandler) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% UnitTest4FecthArticlesHandler" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (UnitTest4FecthArticlesHandler)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (UnitTest4FecthArticlesHandler)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


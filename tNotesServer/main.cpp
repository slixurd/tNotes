/* 
 * File:   main.cpp
 * Author: wo1fsea (Quanyong Huang)
 *
 * Created on 2014年3月19日, 上午11:05
 */

#include <iostream>
#include <stdlib.h> 
#include <string>
#include <exception>

#include <fcgio.h>

#include "HandlerFactory.h"

/*
 * CGI Main
 */

using namespace std;

int main(int argc, char** argv) {

    // Backup the stdio streambufs
    streambuf * cin_streambuf = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    HandlerFactory simpleFactory;
    Handler* handler = NULL;

    while (FCGX_Accept_r(&request) == 0) {

        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        try {

            string scriptName = FCGX_GetParam("SCRIPT_NAME", request.envp);
            string method = FCGX_GetParam("REQUEST_METHOD", request.envp);
            string contextType = FCGX_GetParam("CONTENT_TYPE", request.envp);
            int postLen = atoi(FCGX_GetParam("CONTENT_LENGTH", request.envp));

            int i = 0;
            string postInfo;
            postInfo.resize(postLen);

            if (method == "POST") {
                while (i < postLen) {
                    postInfo[i++] = cin.get();
                }
            }

            /**/
            handler = simpleFactory.CreatHandler(scriptName);
            if (handler != NULL) {
                string result = handler->Handle(postInfo);
                cout << "Content-type: application/json\r\n"
                        << "\r\n"
                        << result;
            }
            delete handler;

            /*just 4 test*/
//            cout << "Content-type: text/html\r\n"
//                    << "\r\n"
//                    << "FastCGI Hello! "
//                    << "FileName:" << scriptName << ";"
//                    << "Context_type:" << contextType << ";"
//                    << "Method:" << method << ";"
//                    << "Post:" << postInfo;
            // Note: the fcgi_streambuf destructor will auto flush

        } catch (exception const& e) {
            cout << "Content-type: text/html\r\n"
                    << "\r\n"
                    << e.what();
            delete handler;
        }

    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
/* 
 * File:   main.cpp
 * Author: wo1fsea (Quanyong Huang)
 *
 * Created on 2014年3月19日, 上午11:05
 */

#include <iostream>
#include <fcgi_stdio.h> 
#include <stdlib.h> 
#include <string>

/*
 * 
 */

int main(int argc, char** argv) {

        while(FCGI_Accept() >= 0)
        {
            char* scriptName = getenv("SCRIPT_NAME");
            int postLen = atoi(getenv("CONTENT_LENGTH"));
            
            int i= 0;
            std::string postInfo;
            postInfo.resize(postLen);
            while( i < postLen )   
            {	    
                postInfo[i++] = FCGI_fgetc(stdin);   
            }	 
            
            printf("Content-type: text/html\r\n"
                "\r\n"
                ""
                "FastCGI Hello! "
                "FileName:%s; Post:%s",scriptName,postInfo.c_str());
        }
        
        return 0;
}
/* 
 * File:   structs.h
 * Author: slixurd
 *
 */

#ifndef STRUCTS_H
#define	STRUCTS_H
#include <string>

struct DIR_INFO{
    unsigned long pid;
    std::string name;
    unsigned long timestamp;
};

//如果只需要传送摘要,那么content截取固定字数
struct ARTICLE_INFO{
    unsigned long id;
    std::string name;
    unsigned long timestamp;
    unsigned long pid;
    std::string content;
};

//只有id号和时间戳
//用于比对时间戳,同步
struct ARTICLE_SYNC{
    unsigned long id;
    unsigned long timestamp;
};
#endif	/* STRUCTS_H */


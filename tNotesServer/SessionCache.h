/* 
 * File:   SessionCache.h
 * Author: wo1fsea
 * 
 * Created on March 21, 2014, 3:57 PM
 */

#ifndef SESSIONCACHE_H
#define	SESSIONCACHE_H

#include <string>
#include <map>

#include "stdlib.h"

#ifndef SESSION_CACHE_CAPCITY
#define SESSION_CACHE_CAPCITY 100 //1024*10
#endif

/* Define std::string as SessionKeyType */
typedef std::string SessionKeyType;

/* Session Infomation */
struct SessionInfo {
    std::string User;
    time_t Signin;
    time_t LastVisit;
};

/* SessionCache is a LRU Cache, which is also a singleton */
class SessionCache {
public:
    static SessionCache* GetInstant();

    bool IsExist(SessionKeyType const& sessionKey);
    SessionInfo & Get(SessionKeyType const& sessionKey);
    void Set(SessionKeyType const& sessionKey, SessionInfo const& sessionInfo);
    void Erase(SessionKeyType const& sessionKey);
    
    virtual ~SessionCache();

private:    
    static const int __capacity = SESSION_CACHE_CAPCITY;
    static SessionCache* __singleton;
    
    int __size;
        
    /* The construction function has to be private to make sure the cache is a singleton. */
    SessionCache();
    
    /* Double linked list node */
    struct __DLinkNode {
        __DLinkNode* Prev;
        __DLinkNode* Next;
        SessionKeyType Key;

        __DLinkNode() : Key(""), Prev(NULL), Next(NULL) {}
        __DLinkNode(SessionKeyType k) : Key(k), Prev(NULL), Next(NULL) {}
    };

    /* Data 4 map */
    class __Data {
    public:
        SessionInfo Value;
        __DLinkNode Link;

        __Data(){}
        __Data(SessionInfo v) : Value(v) {}
    };
    
    typedef std::map<SessionKeyType, __Data> Map;
    Map __map;
    __DLinkNode __head;
    __DLinkNode* __tail;
};

#endif	/* SESSIONCACHE_H */


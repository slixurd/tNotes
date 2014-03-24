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

#ifndef SESSION_CACHE_CAPCITY
#define SESSION_CACHE_CAPCITY 1024*10
#endif

/* Session Infomation */
struct SessionInfo {
    std::string User;
};

/* SessionCache is a LRU Cache, which is also a singleton */
class SessionCache {
public:
    /* Define std::string as SessionKeyType */
    typedef std::string SessionKeyType;
    static SessionCache* GetInstant();

    bool IsSessionExist(SessionKeyType const& sessionKey);
    SessionInfo GetSession(SessionKeyType const& sessionKey);
    void SetSession(SessionKeyType const& sessionKey, SessionInfo const& sessionInfo);
    
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


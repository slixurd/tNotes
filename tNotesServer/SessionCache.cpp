/* 
 * File:   SessionCache.cpp
 * Author: wo1fsea
 * 
 * Created on 2014年3月21日, 下午3:57
 */

#include "SessionCache.h"
#include "Exception.hpp"

SessionCache* SessionCache::__singleton = NULL;

SessionCache::SessionCache() {
    __size = 0;
    __tail = &__head;
}

SessionCache::~SessionCache() {

}

SessionCache* SessionCache::GetInstant() {
    if (__singleton == NULL)
        __singleton = new SessionCache();
    return __singleton;
}

bool SessionCache::IsSessionExist(SessionKeyType const& sessionKey) {
    Map::iterator it = __map.find(sessionKey);
    return it != __map.end();
}

SessionInfo SessionCache::GetSession(SessionKeyType const& sessionKey) {
    Map::iterator it = __map.find(sessionKey);
    if (it == __map.end()){
        /* Session Failure */
        throw SessionFailureException();
    }else {
        if (it->second.Link.Prev != &__head) {
            it->second.Link.Prev->Next = it->second.Link.Next;
            if (it->second.Link.Next == NULL) {
                __tail = it->second.Link.Prev;
            } else
                it->second.Link.Next->Prev = it->second.Link.Prev;

            it->second.Link.Next = __head.Next;
            if (__head.Next != NULL)
                __head.Next->Prev = &it->second.Link;
            __head.Next = &it->second.Link;
            it->second.Link.Prev = &__head;
        }
        return it->second.Value;
    }
}

void SessionCache::SetSession(SessionKeyType const& sessionKey, SessionInfo const& sessionInfo) {
    Map::iterator it = __map.find(sessionKey);
    
    if (it == __map.end()) {
        /* Set New Session */
        if (__size < __capacity) {
            ++__size;
        } else {
            __tail->Prev->Next = NULL;
            __DLinkNode *temp = __tail->Prev;
            __map.erase(__map.find(__tail->Key));
            __tail = temp;
        }
    } else {
        /* Reset Old Session */
        it->second.Link.Prev->Next = it->second.Link.Next;
        if (it->second.Link.Next == NULL) {
            __tail = it->second.Link.Prev;
        } else
            it->second.Link.Next->Prev = it->second.Link.Prev;
    }

    __map[sessionKey] = __Data(sessionInfo);
    __map[sessionKey].Link.Key = sessionKey;
    __map[sessionKey].Link.Next = __head.Next;
    if (__head.Next != NULL)
        __head.Next->Prev = &__map[sessionKey].Link;

    __head.Next = &__map[sessionKey].Link;
    __map[sessionKey].Link.Prev = &__head;
    if (__tail == &__head)
        __tail = __head.Next;
}





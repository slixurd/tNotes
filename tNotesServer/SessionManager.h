/* 
 * File:   SessionManager.h
 * Author: wo1fsea
 *
 * Created on March 21, 2014, 10:27 PM
 */

#ifndef SESSIONMANAGER_H
#define	SESSIONMANAGER_H

#include <string>

#include "SessionCache.h"

class SessionManager {
public:
    SessionManager();
    ~SessionManager();
    
    SessionKeyType CreateSession(SessionInfo const& sessionInfo);
    void VeritySession(SessionKeyType const& sessionKey);
    SessionInfo const& GetSessionInfo(SessionKeyType const& sessionKey);
    void DeleteSession(SessionKeyType const& sessionKey);
    
private:
    static const int __sessionKeyLen = 32;
    static long long  __seed;
      
    SessionCache* __cache;
    
    SessionKeyType __GenerateSessionKey();
    time_t __Now();
    
};

#endif	/* SESSIONMANAGER_H */


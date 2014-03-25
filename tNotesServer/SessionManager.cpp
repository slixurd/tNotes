/* 
 * File:   SessionManager.cpp
 * Author: wo1fsea
 * 
 * Created on March 21, 2014, 10:27 PM
 */

#include "SessionManager.h"

long long  SessionManager::__seed = 0;

SessionManager::SessionManager() {
    __cache = SessionCache::GetInstant();
    
    if(__seed!=0)
        return;
    
    /* Use time as the random seed */
    __seed = __Now();
}

SessionManager::~SessionManager() {
}

SessionKeyType SessionManager::CreateSession(SessionInfo const& sessionInfo)
{
    SessionInfo info = sessionInfo;
    info.LastVisit = __Now();
    info.Signin = __Now();
    
    std::string key;
    do{
        key = __GenerateSessionKey();
    }while(__cache->IsExist(key));
    
    __cache->Set(key,info);
    
    return key;
}

void SessionManager::VeritySession(SessionKeyType const& sessionKey)
{
    __cache->Get(sessionKey).LastVisit = __Now();
}

SessionInfo const& SessionManager::GetSessionInfo(SessionKeyType const& sessionKey)
{
    time_t now;
    time(&now);
    SessionInfo & info = __cache->Get(sessionKey);
    info.LastVisit = __Now();
    return info;
}

void SessionManager::DeleteSession(SessionKeyType const& sessionKey)
{
    __cache->Erase(sessionKey);
}

/* Warning: Collisions may occur, when the number of Session is greater than 10k.*/
std::string SessionManager::__GenerateSessionKey() {
    using std::string;

    char sessionKey[__sessionKeyLen+1];
    
    srand(__seed);
    __seed = rand();
    for (int i = 0; i < __sessionKeyLen; i++) {
        srand(__seed);
        __seed = rand();
        sessionKey[i] = __seed % 26 + 'A';
    }
    sessionKey[__sessionKeyLen] = '\0';

    return string(sessionKey);
}

time_t SessionManager::__Now()
{
    time_t now;
    time(&now);
    return now;
}

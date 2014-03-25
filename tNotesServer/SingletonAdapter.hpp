/* 
 * File:   SingletonAdapter.hpp
 * Author: wo1fsea
 *
 * Created on March 25, 2014, 7:43 PM
 */

#ifndef SINGLETONADAPTER_HPP
#define	SINGLETONADAPTER_HPP

template
<typename T>
class SingletonAdapter {
public:
    SingletonAdapter()
    {
        if(__singleton == 0)
            __singleton = new T();
    }
    
    ~SingletonAdapter()
    {
    
    }
    
    T* operator->()
    {
        return __singleton;
    }
private:
    static T* __singleton;
};

template<typename T>
T* SingletonAdapter<T>::__singleton = 0;

#endif	/* SINGLETONADAPTER_HPP */


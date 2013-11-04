/*
    Thread-safe Singleton Pattern with Double-checked Locking Pattern implementation
 
    Volatile is added to enforce sequential points thus no patially initialized object (pInstance)
    is presented in multi-threading system.
 */
#include "singleton.hpp"
#include <new>              // ::operator new

volatile Singleton* volatile Singleton::getInstance=NULL;

volatile Singleton* Singleton::getInstance()         // Double-checked Locking Pattern
{
    if (pInstance==NULL) {                  // 1st test: to avoid the locking if the instance is already initialized
        Lock lock(singleton_lock);          //  acquire lock               

        if (pInstance == NULL) {            // 2nd test: double-check because instance could be initialized 
                                            //           by other thread during locking above
 
            volatile Singleton* volatile tmp = new volatile Singleton; 
            pInstance = tmp;

            /* 
            pInstance = new Singleton;
    
            <==>

            pInstance                       // Step 3:  Make pInstance point to the allocated memory
                = operator new Singleton;   // Step 1:  Allocate memory to hold Singleton object
            new (pInstance) Singleton;      // Step 2:  Construct Singleton object (via ctor) on allocated memory
                                                        (Step 2 might throw an exception. Thus Step 3 cannot be ahead of Step 2)

            Note:  Double-checked Locking Pattern only works when Step 1 & 2 are completed before Step 3.
             */
        }
    }                                        // release lock via lock destructor

    return pInstance;
}


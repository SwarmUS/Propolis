#ifndef __IMUTEX_H_
#define __IMUTEX_H_

#include <mutex>

/**
 *@brief A class to manage mutual exclusion for guarding resources (uses static allocation for FreeRTOS)*/
class IMutex {
  public:
    virtual ~IMutex() = default;

    /**
     *@brief Locks the mutex, waits the maxWaitTime if the resouce is already locked
     *
     *@return true if the operation was successful, false on timeout */
    virtual bool lock() = 0;

    /**
     *@brief Unlocks the mutex, it releases the shared resource
     *
     *@return true if the operation was successful, false if not*/
    virtual bool unlock() = 0;
};

#endif // __IMUTEX_H_

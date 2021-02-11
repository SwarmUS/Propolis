#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <mutex>

/**
 *@brief A class to manage mutual exclusion for guarding resources using FreeRTOS static memory
 *allocation*/
class Mutex {
  public:
    /**
     *@brief Creates a Mutex instance
     *
     *@param maxWaitTime max time to wait in ticks when trying to lock
     **/
    Mutex(uint32_t maxWaitTime);

    ~Mutex() = default;

    /**
     *@brief Locks the mutex, waits the maxWaitTime if the resouce is already locked
     *
     *@return true if the operation was successful, false on timeout */
    bool lock();

    /**
     *@brief Unlocks the mutex, it releases the shared resource
     *
     *@return true if the operation was successful, false if not*/
    bool unlock();

  protected:
    std::mutex m_mutex;
    const uint32_t m_maxWaitTime;
};

#endif // __MUTEX_H_

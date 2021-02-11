#ifndef __MUTEX_H_
#define __MUTEX_H_

#include "IMutex.h"
#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <cstdint>
#include <semphr.h>

/**
 * @brief Create a mutex on the stack
 */
class Mutex : public IMutex {
  public:
    /**
     *@brief Creates a Mutex instance
     *
     *@param maxWaitTime max time to wait in ticks when trying to lock
     **/
    Mutex(uint32_t maxWaitTime);

    ~Mutex() = default;

    bool lock();

    bool unlock();

  protected:
    SemaphoreHandle_t m_mutex;
    StaticSemaphore_t m_mutexStaticMemory;
    const uint32_t m_maxWaitTime;
};

#endif // __MUTEX_H_

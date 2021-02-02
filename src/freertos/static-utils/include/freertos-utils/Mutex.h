#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <cstdint>
#include <semphr.h>

class Mutex {
  public:
    Mutex(uint32_t maxWaitTime);

    // should we release the semaphore&&
    ~Mutex() = default;

    bool lock();

    bool unlock();

  protected:
    SemaphoreHandle_t m_mutex;
    StaticSemaphore_t m_mutexStaticMemory;
    const uint32_t m_maxWaitTime;
};

#endif // __MUTEX_H_

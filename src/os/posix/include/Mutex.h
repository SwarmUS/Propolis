#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <mutex>
#include "IMutex.h"

class Mutex: IMutex {
  public:
    /**
     *@brief Creates a Mutex instance
     *
     *@param maxWaitTime not used
     **/
    Mutex(uint32_t maxWaitTime);

    ~Mutex() = default;

    bool lock();

    bool unlock();

  protected:
    std::mutex m_mutex;
};

#endif // __MUTEX_H_

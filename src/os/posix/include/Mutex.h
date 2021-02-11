#ifndef __MUTEX_H_
#define __MUTEX_H_

#include "IMutex.h"
#include <mutex>

class Mutex : public IMutex {
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

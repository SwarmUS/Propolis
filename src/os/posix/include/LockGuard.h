#ifndef __LOCKGUARD_H_
#define __LOCKGUARD_H_

#include "Mutex.h"

/**
 *@brief A class to guard mutex in the current scope, similar to std::lock_guard, locks the resource
 *on instanciation and releases it at destruction
 */
class LockGuard {
  public:
    /**
     *@brief Instanciate a LockGuard
     *
     *@param mutex a reference to the mutex used to lock/unlock
     */
    LockGuard(IMutex& mutex);

    ~LockGuard();

  private:
    IMutex& m_mutex;
};

#endif // __LOCKGUARD_H_

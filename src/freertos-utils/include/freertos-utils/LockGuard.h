#ifndef __LOCKGUARD_H_
#define __LOCKGUARD_H_

#include "Mutex.h"

class LockGuard {
  public:
    LockGuard(Mutex& mutex);

    ~LockGuard();

  private:
    Mutex& m_mutex;
};

#endif // __LOCKGUARD_H_

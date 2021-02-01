#include "LockGuard.h"

LockGuard::LockGuard(Mutex& mutex) {
    while (!m_mutex.lock())
        ;
}

LockGuard::~LockGuard() { m_mutex.unlock(); }

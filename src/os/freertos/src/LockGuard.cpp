#include "LockGuard.h"

LockGuard::LockGuard(IMutex& mutex) : m_mutex(mutex) {
    while (!m_mutex.lock()) {
    }
}

LockGuard::~LockGuard() { m_mutex.unlock(); }

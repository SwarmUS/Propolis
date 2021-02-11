#include "LockGuard.h"

LockGuard::LockGuard(Mutex& mutex) : m_mutex(mutex) { m_mutex.lock(); }

LockGuard::~LockGuard() { m_mutex.unlock(); }

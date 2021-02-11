#include "LockGuard.h"

LockGuard::LockGuard(IMutex& mutex) : m_mutex(mutex) { m_mutex.lock(); }

LockGuard::~LockGuard() { m_mutex.unlock(); }

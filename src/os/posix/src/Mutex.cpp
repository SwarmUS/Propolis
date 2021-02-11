#include "Mutex.h"

Mutex::Mutex(uint32_t maxWaitTime) { (void)maxWaitTime; }

bool Mutex::lock() { m_mutex.lock(); }

bool Mutex::unlock() { m_mutex.unlock(); }

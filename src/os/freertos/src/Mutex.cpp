#include "Mutex.h"

Mutex::Mutex(uint32_t maxWaitTime) : m_maxWaitTime(maxWaitTime) {
    m_mutex = xSemaphoreCreateMutexStatic(&m_mutexStaticMemory);
}

bool Mutex::lock() { return pdTRUE == xSemaphoreTake(m_mutex, m_maxWaitTime); }

bool Mutex::unlock() { return pdTRUE == xSemaphoreGive(m_mutex); }

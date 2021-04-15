#include "ConditionVariable.h"
#include <chrono>

ConditionVariable::ConditionVariable() : m_waiting(false) {}

void ConditionVariable::notify() { m_conditionVar.notify_one(); }

bool ConditionVariable::wait(uint32_t waitTime) {
    if (m_waiting) {
        return false;
    }

    m_waiting = true;
    std::unique_lock<std::mutex> lock(m_mutex);
    auto chronoTime = std::chrono::milliseconds(waitTime);
    m_conditionVar.wait_for(lock, chronoTime);
    m_waiting = false;

    return true;
}

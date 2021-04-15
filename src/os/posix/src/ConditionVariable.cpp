#include "ConditionVariable.h"
#include <chrono>

void ConditionVariable::notify() { m_conditionVar.notify_one(); }

void ConditionVariable::wait(uint32_t waitTime) {

    std::chrono::std::unique_lock<std::mutex> lock(m_mutex);
    if (waitTime > 0) {
        auto chronoTime = std::chrono::milliseconds(waitTime);
        m_conditionVar.wait_for(lock, chronoTime);
    } else {
        m_conditionVar.wait(lock);
    }
}

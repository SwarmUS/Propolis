#include "ConditionVariable.h"

ConditionVariable::ConditionVariable() : m_taskHandle(NULL) {}

void ConditionVariable::notify() {
    if (m_taskHandle != NULL) {
        xTaskNotifyGive(m_taskHandle);
    }
}

bool ConditionVariable::wait(uint32_t waitTime) {
    if (m_taskHandle == NULL) {
        m_taskHandle = xTaskGetCurrentTaskHandle();
        ulTaskNotifyTake(pdTRUE, waitTime);
        m_taskHandle = NULL;
        return true;
    }
    return false;
}

#include "FreeRTOSConditionVariable.h"

FreeRTOSConditionVariable::FreeRTOSConditionVariable() : m_taskHandle(NULL) {}

void FreeRTOSConditionVariable::notify() {
    if (m_taskHandle != NULL) {
        xTaskNotifyGive(m_taskHandle);
    }
}

void FreeRTOSConditionVariable::notifyFromISR() {
    BaseType_t toYield = pdFALSE;
    if (m_taskHandle != NULL) {
        vTaskNotifyGiveIndexedFromISR(m_receivingTaskHandle, 0, &toYield);
    }
    portYIELD_FROM_ISR(toYield);
}

bool FreeRTOSConditionVariable::wait(uint32_t waitTime) {
    if (m_taskHandle == NULL) {
        m_taskHandle = xTaskGetCurrentTaskHandle();
        ulTaskNotifyTake(pdTRUE, waitTime);
        m_taskHandle = NULL;
        return true;
    }
    return false;
}

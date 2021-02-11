#ifndef ABSTRACTTASK_TPP
#define ABSTRACTTASK_TPP

template <unsigned int stackSize>
AbstractTask<stackSize>::AbstractTask(const char* taskName, UBaseType_t priority) {
    m_taskName = taskName;
    m_priority = priority;
    m_taskHandle = NULL;
    m_taskBuffer = {};
}

template <unsigned int stackSize>
AbstractTask<stackSize>::~AbstractTask() {
    if (m_taskHandle != NULL) {
        vTaskDelete(m_taskHandle);
    }
}

template <unsigned int stackSize>
bool AbstractTask<stackSize>::start() {
    if (!m_taskRunning) {
        m_taskHandle = xTaskCreateStatic(wrapper, m_taskName, stackSize, this, m_priority,
                                         m_stackArray.data(), &m_taskBuffer);
        m_taskRunning = true;
        return true;
    }
    return false;
}

template <unsigned int stackSize>
TaskHandle_t& AbstractTask<stackSize>::getTaskHandle() {
    return m_taskHandle;
}

template <unsigned int stackSize>
void AbstractTask<stackSize>::wrapper(void* params) {
    AbstractTask* task = static_cast<AbstractTask*>(params);
    task->task();
    task->m_taskRunning = false;
}

#endif // ABSTRACTTASK_TPP

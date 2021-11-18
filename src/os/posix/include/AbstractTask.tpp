#ifndef ABSTRACTTASK_TPP
#define ABSTRACTTASK_TPP

template <unsigned int stackSize>
AbstractTask<stackSize>::AbstractTask(const char* taskName, UBaseType_t priority) {
    (void)taskName;
    (void)priority;
}

template <unsigned int stackSize>
AbstractTask<stackSize>::~AbstractTask() {
    if (m_taskRunning) {
        m_thread.join();
    }
}

template <unsigned int stackSize>
bool AbstractTask<stackSize>::start() {
    if (!m_taskRunning) {
        if (m_thread.joinable()) {
            m_thread.join();
        }

        m_thread = std::thread(wrapper, this);
        m_taskRunning = true;
        return true;
    }
    return false;
}

template <unsigned int stackSize>
const char* AbstractTask<stackSize>::getTaskName() {
    return m_taskName;
}

template <unsigned int stackSize>
bool AbstractTask<stackSize>::isRunning() {
    return m_taskRunning;
}

template <unsigned int stackSize>
void AbstractTask<stackSize>::wrapper(void* params) {
    AbstractTask* task = static_cast<AbstractTask*>(params);
    task->task();
    task->m_taskRunning = false;
}

template <unsigned int stackSize>
TaskHandle_t AbstractTask<stackSize>::getTaskHandle() {
    return m_thread;
}

#endif // ABSTRACTTASK_TPP

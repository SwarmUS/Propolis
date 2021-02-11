#ifndef __BASETASK_TPP_
#define __BASETASK_TPP_

#include "freertos-utils/BaseTask.h"

template <unsigned int stackSize>
BaseTask<stackSize>::BaseTask(const char* taskName,
                              UBaseType_t priority,
                              TaskFunction_t taskFunction,
                              void* context) :
    AbstractTask<stackSize>(taskName, priority),
    m_taskFunction(taskFunction),
    m_taskContext(context) {}

template <unsigned int stackSize>
void BaseTask<stackSize>::task() {
    m_taskFunction(m_taskContext);
}

#endif // __BASETASK_TPP_

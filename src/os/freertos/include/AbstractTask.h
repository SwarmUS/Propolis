#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include "IAbstractTask.h"
#include <FreeRTOS.h>
#include <array>
#include <task.h>

template <unsigned int stackSize>
class AbstractTask : IAbstractTask {
  public:
    AbstractTask(const char* taskName, UBaseType_t priority);

    virtual ~AbstractTask();

    bool start() override;

  protected:
    virtual void task() = 0;

    static void wrapper(void* params);

    const char* m_taskName;
    std::array<StackType_t, stackSize> m_stackArray;
    StaticTask_t m_taskBuffer;
    UBaseType_t m_priority;
    TaskHandle_t m_taskHandle;
    bool m_taskRunning = false;
};

#include "AbstractTask.tpp"

#endif // ABSTRACTTASK_H

#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include "IAbstractTask.h"
#include <FreeRTOS.h>
#include <array>
#include <atomic>
#include <task.h>

/**
 * @brief Creates a FreeRTOS task on the stack
 */
template <unsigned int stackSize>
class AbstractTask : public IAbstractTask {
  public:
    AbstractTask(const char* taskName, UBaseType_t priority);

    virtual ~AbstractTask();

    bool start() override;

    const char* getTaskName() override;

    bool isRunning() override;

    TaskHandle_t getTaskHandle() override;

  protected:
    virtual void task() = 0;

    static void wrapper(void* params);

    const char* m_taskName;
    std::array<StackType_t, stackSize> m_stackArray;
    StaticTask_t m_taskBuffer;
    UBaseType_t m_priority;
    TaskHandle_t m_taskHandle;
    std::atomic_bool m_taskRunning;
};

#include "AbstractTask.tpp"

#endif // ABSTRACTTASK_H

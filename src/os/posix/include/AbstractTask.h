#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include "IAbstractTask.h"
#include "Macros.h"
#include <stdint.h>
#include <thread>

template <unsigned int stackSize>
class AbstractTask : IAbstractTask {
  public:
    AbstractTask(const char* taskName, UBaseType_t priority);

    virtual ~AbstractTask();

    bool start() override;

  protected:
    virtual void task() = 0;

    static void wrapper(void* params);

    bool m_taskRunning = false;
    std::thread m_thread;
};

#include "AbstractTask.tpp"

#endif // ABSTRACTTASK_H

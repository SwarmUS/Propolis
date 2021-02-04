#ifndef __BASETASK_H_
#define __BASETASK_H_

#include "AbstractTask.h"

template <unsigned int stackSize>
class BaseTask : public AbstractTask<stackSize> {
  public:
    BaseTask(const char* taskName,
             UBaseType_t priority,
             TaskFunction_t taskFunction,
             void* context);

    ~BaseTask() override = default;

  protected:
    void task() override;
    TaskFunction_t m_taskFunction;
    void* m_taskContext;
};

#include "BaseTask.tpp"

#endif // __BASETASK_H_

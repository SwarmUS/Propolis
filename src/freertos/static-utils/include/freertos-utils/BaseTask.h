#ifndef __BASETASK_H_
#define __BASETASK_H_

#include "AbstractTask.h"

template <unsigned int stackSize, typename Functor>
class BaseTask : public AbstractTask<stackSize> {
  public:
    BaseTask(const char* taskName, UBaseType_t priority, Functor functor) :
        AbstractTask<stackSize>(taskName, priority), m_functor(functor) {}

    ~BaseTask() override = default;

  protected:
    void task() override { m_functor(); }

    Functor m_functor;
};

#endif // __BASETASK_H_

#ifndef __CONDITIONVARIABLE_H_
#define __CONDITIONVARIABLE_H_

#include "IConditionVariable.h"
#include <FreeRTOS.h>
#include <task.h>

class ConditionVariable : public IConditionVariable {
  public:
    ConditionVariable();
    ~ConditionVariable() override = default;
    void notify() override;
    bool wait(uint32_t waitTime) override;

  private:
    TaskHandle_t m_taskHandle;
};

#endif // __CONDITIONVARIABLE_H_

#ifndef __CONDITIONVARIABLE_H_
#define __CONDITIONVARIABLE_H_

#include "FreeRTOSConditionVariable.h"
#include "IConditionVariable.h"
#include <FreeRTOS.h>
#include <task.h>

class ConditionVariable : public IConditionVariable {
  public:
    ~ConditionVariable() override = default;
    void notify() override;
    bool wait(uint32_t waitTime) override;

  private:
    FreeRTOSConditionVariable m_conditionVar;
};

#endif // __CONDITIONVARIABLE_H_

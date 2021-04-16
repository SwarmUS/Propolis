#ifndef __FREERTOSCONDITIONVARIABLE_H_
#define __FREERTOSCONDITIONVARIABLE_H_

#include "IConditionVariable.h"
#include <FreeRTOS.h>
#include <task.h>

class FreeRTOSConditionVariable : public IConditionVariable {
  public:
    FreeRTOSConditionVariable();
    ~FreeRTOSConditionVariable() override = default;
    void notify() override;
    void notifyFromISR();
    bool wait(uint32_t waitTime) override;

  private:
    TaskHandle_t m_taskHandle;
};

#endif // __FREERTOSCONDITIONVARIABLE_H_

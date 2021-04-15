#ifndef __CONDITIONVARIABLE_H_
#define __CONDITIONVARIABLE_H_

#include "IConditionVariable.h"
#include <condition_variable>
#include <mutex>

class ConditionVariable : public IConditionVariable {
  public:
    ~ConditionVariable() override = default;
    void notify() override;
    void wait(uint32_t waitTime) override;

  private:
    std::mutex m_mutex;
    std::condition_variable m_conditionVar;
};

#endif // __CONDITIONVARIABLE_H_

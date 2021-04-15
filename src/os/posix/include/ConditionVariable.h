#ifndef __CONDITIONVARIABLE_H_
#define __CONDITIONVARIABLE_H_

#include "IConditionVariable.h"
#include <atomic>
#include <condition_variable>
#include <mutex>

class ConditionVariable : public IConditionVariable {
  public:
    ConditionVariable();
    ~ConditionVariable() override = default;
    void notify() override;
    bool wait(uint32_t waitTime) override;

  private:
    std::mutex m_mutex;
    std::condition_variable m_conditionVar;
    std::atomic_bool m_waiting;
};

#endif // __CONDITIONVARIABLE_H_

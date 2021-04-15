#ifndef __ICONDITIONVARIABLE_H_
#define __ICONDITIONVARIABLE_H_

#include <cstdint>

class IConditionVariable {
  public:
    virtual ~IConditionVariable() = default;
    virtual void notify() = 0;
    virtual void wait(uint32_t waitTime) = 0;
};

#endif // __ICONDITIONVARIABLE_H_

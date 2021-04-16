#include "ConditionVariable.h"

void ConditionVariable::notify() { m_conditionVar.notify(); }

bool ConditionVariable::wait(uint32_t waitTime) { return m_conditionVar.wait(waitTime); }

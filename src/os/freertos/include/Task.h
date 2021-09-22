#ifndef __TASK_H__
#define __TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>

namespace Task {

    typedef Time TickType_t;

    inline void delay(uint32_t ms);

    inline void delayUntil(Time& current, uint32_t ms);

    inline Task::Time getTime();

    inline void startScheduler();
} // namespace Task

#endif //__TASK_H__

#ifndef __TASK_H__
#define __TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>

namespace Task {

    typedef TickType_t Time;

    inline void delay(uint32_t ms);

    inline void delayUntil(Time& current, uint32_t ms);

    inline Time getTime();

    inline void startScheduler();
} // namespace Task

#endif //__TASK_H__

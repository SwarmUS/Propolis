#ifndef __TASK_H__
#define __TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>

namespace Task {
    inline void delay(TickType_t ms) { vTaskDelay(ms); }

    inline void startScheduler() { vTaskStartScheduler(); }
} // namespace Task

#endif //__TASK_H__

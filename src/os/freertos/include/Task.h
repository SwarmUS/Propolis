#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

namespace Task {
    inline void delay(TickType_t ms) { vTaskDelay(ms); }

    inline void startScheduler() { vTaskStartScheduler(); }
} // namespace Task

#endif //__TASK_H__

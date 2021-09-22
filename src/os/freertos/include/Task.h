#ifndef __TASK_H__
#define __TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>

namespace Task {

    typedef TickType_t Time;

    inline void delay(uint32_t ms) { vTaskDelay(ms); };

    inline void delayUntil(Time& current, uint32_t ms) { vTaskDelayUntil(&current, ms); };

    inline Time getTime() { return xTaskGetTickCount(); };

    inline void startScheduler() { vTaskStartScheduler(); };

} // namespace Task

#endif //__TASK_H__

#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>

namespace Task {
    inline void delay(int ms) { vTaskDelay(ms); }

    inline void startScheduler() { vTaskStartScheduler(); }
} // namespace Task

#endif //__TASK_H__

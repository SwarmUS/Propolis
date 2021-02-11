#ifndef __TASK_H__
#define __TASK_H__

#include <errno.h>
#include <stdint.h>
#include <thread>
#
#include <time.h>

namespace Task {
    inline void delay(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

    inline void startScheduler() {
        while (true) {
            delay(1000);
        }
    }
} // namespace Task

#endif //__TASK_H__

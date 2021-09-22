#ifndef __TASK_H__
#define __TASK_H__

#include <chrono>
#include <errno.h>
#include <stdint.h>
#include <thread>
#include <time.h>

namespace Task {

    typedef std::chrono::time_point<std::chrono::system_clock> Time;

    inline void delay(uint ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

    inline void delayUntil(Time& current, uint ms) {

        std::this_thread::sleep_until(current + std::chrono::milliseconds(ms));
        current = std::chrono::system_clock::now();
    }

    inline Time getTime() { return std::chrono::system_clock::now(); }

    inline void startScheduler() {
        while (true) {
            delay(1000);
        }
    }
} // namespace Task

#endif //__TASK_H__

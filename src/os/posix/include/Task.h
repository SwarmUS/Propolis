#ifndef __TASK_H__
#define __TASK_H__

#include <chrono>
#include <errno.h>
#include <stdint.h>
#include <thread>
#include <time.h>

namespace Task {

    typedef std::chrono::time_point<std::chrono::system_clock> Time;

    inline void delay(uint ms);

    inline void delayUntil(Time& current, uint ms);

    inline Time getTime();

    inline void startScheduler();
} // namespace Task

#endif //__TASK_H__

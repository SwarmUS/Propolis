#ifndef __TASK_H__
#define __TASK_H__

#include <errno.h>
#include <stdint.h>
#include <time.h>

namespace Task {
    inline void delay(int ms) {
        struct timespec ts;
        int res;

        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (ms % 1000) * 1000000;

        do {
            res = nanosleep(&ts, &ts);
        } while (res && errno == EINTR);
    }

    inline void startScheduler() {
        while (true) {
            delay(1000);
        }
    }
} // namespace Task

#endif //__TASK_H__

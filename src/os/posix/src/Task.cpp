#include "Task.h"

void Task::delay(uint ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

void Task::delayUntil(Time& current, uint ms) {
    std::this_thread::sleep_until(current + std::chrono::milliseconds(ms));
    current = std::chrono::system_clock::now();
}

Time Task::getTime() { return std::chrono::system_clock::now(); }

void Task::startScheduler() {
    while (true) {
        delay(1000);
    }
}

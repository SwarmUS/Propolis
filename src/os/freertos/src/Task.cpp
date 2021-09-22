#include "Task.h"

void Task::delay(TickType_t ms) { vTaskDelay(ms); }

void Task::delayUntil(Time& current, uint ms) { vTaskDelayUntil(&current, ms); }

Time Task::getTime() { return xTaskGetTickCount(); }

void Task::startScheduler() { vTaskStartScheduler(); }

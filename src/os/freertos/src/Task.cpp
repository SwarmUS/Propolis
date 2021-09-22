#include "Task.h"

void Task::delay(uint32_t ms) { vTaskDelay(ms); }

void Task::delayUntil(Task::Time& current, uint32_t ms) { vTaskDelayUntil(&current, ms); }

Task::Time Task::getTime() { return xTaskGetTickCount(); }

void Task::startScheduler() { vTaskStartScheduler(); }

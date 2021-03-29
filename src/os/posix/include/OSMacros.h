#ifndef __MACROS_H__
#define __MACROS_H__

#include <stdint.h>
#include <thread>

typedef unsigned long UBaseType_t;
typedef std::thread& TaskHandle_t;
typedef void (*TaskFunction_t)(void*);

#define configMINIMAL_STACK_SIZE 1
#define tskIDLE_PRIORITY 1

#endif //__MACROS_H__

#ifndef IABSTRACTTASK_H
#define IABSTRACTTASK_H

#include <Macros.h>

/**
 *@brief An abstract class for creating an OS dependent task To use, create a class that inherit the
 *AbstractTask and write your task logic in an overload of the task member function and start the
 *task, the template argument is the size of the stack for the task*/
class IAbstractTask {
  public:
    virtual ~IAbstractTask() = default;

    /**
     *@brief Starts the task, i.e. executes the task method in another FreeRTOS task or thread
     *without blocking the current thread execution
     *
     *@return true if the operation was successfull, false if not (i.e. if the task was started
     *multiple times)
     **/
    virtual bool start() = 0;

    virtual TaskHandle_t getTaskHandle() = 0;
};

#endif // IABSTRACTTASK_H

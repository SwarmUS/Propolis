#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <thread>

/**
 *@brief An abstract class for creating FreeRTOS task that uses the stack instead of the heap.
 *To use, create a class that inherit the AbtractTask and write your task logic in an overload of
 *the task member function and start the task, the template argument is the size of the stack for
 *the task*/
class AbstractTask {
  public:
    AbstractTask(const char* taskName, UBaseType_t priority);

    virtual ~AbstractTask();

    /**
     *@brief Starts the task, i.e. executes the task method in another FreeRTOS task without
     *blocking the current thread execution
     *
     *@return true if the operation was successfull, false if not (i.e. if the task was started
     *multiple times)
     **/
    bool start();

    /**
     *@brief Get the task handle
     *
     *@return A reference to the TaskHandle_t
     */
    TaskHandle_t& getTaskHandle();

  protected:
    virtual void task() = 0;

    static void wrapper(void* params);

    const char* m_taskName;
    UBaseType_t m_priority;
    TaskHandle_t m_taskHandle;
    bool m_taskRunning = false;
    std::thread m_thread;
};

#include "AbstractTask.tpp"

#endif // ABSTRACTTASK_H

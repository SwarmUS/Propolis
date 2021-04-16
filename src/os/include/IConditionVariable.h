#ifndef __ICONDITIONVARIABLE_H_
#define __ICONDITIONVARIABLE_H_

#include <cstdint>

/**@brief Conditin variable, can notify and wait on data
 *Only one thread can wait at the time */
class IConditionVariable {
  public:
    virtual ~IConditionVariable() = default;

    /**@brief notify the waiting thread, see the wait function*/
    virtual void notify() = 0;

    /**@brief wait for a notification or timeout. Only one thread can call wait at a time,
     *subsequent calls will return false.
     *@param waitTime the time to wait in ms
     *@return true if it was possible to wait, false if not (i.e. another thread is already
     *waiting)*/
    virtual bool wait(uint32_t waitTime) = 0;
};

#endif // __ICONDITIONVARIABLE_H_

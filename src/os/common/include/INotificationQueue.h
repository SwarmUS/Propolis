#ifndef __INOTIFICATIONQUEUE_H_
#define __INOTIFICATIONQUEUE_H_

#include <cpp-common/ICircularQueue.h>

/**
 *@brief A queue that notifies when a item is pushed*/
template <typename T>
class INotificationQueue : public ICircularQueue<T> {
  public:
    virtual ~INotificationQueue() override = default;

    virtual bool push(const T& item) override = 0;

    virtual const std::optional<std::reference_wrapper<const T>> peek() const = 0;

    virtual void pop() override = 0;

    virtual void clear() override = 0;

    virtual bool isFull() const = 0;

    virtual bool isEmpty() const = 0;

    virtual uint32_t getLength() const = 0;

    virtual uint32_t getFreeSize() const = 0;

    virtual std::optional<std::reference_wrapper<T>> getNextAllocation() override = 0;

    virtual bool advance() override = 0;

    /**@brief wait for a new value
     *@param waitTime the time to wait in ms
     *@return*/
    virtual bool wait(uint32_t waitTime) override = 0;
};

#endif // __INOTIFICATIONQUEUE_H_

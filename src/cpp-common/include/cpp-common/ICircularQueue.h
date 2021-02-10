#ifndef __ICIRCULARQUEUE_H_
#define __ICIRCULARQUEUE_H_

#include <cstdint>
#include <optional>

/**
 *@brief A queue that add and pop items circularly, similar to a circular buffer
 **/
template <typename T>
class ICircularQueue {
  public:
    ICircularQueue<T>() = default;

    virtual ~ICircularQueue<T>() = default;

    /**
     *@brief push an item into the queue
     *
     *@return true if the operation was successfull, false if not (i.e. buffer is full)
     **/
    virtual bool push(T item) = 0;

    /**
     *@brief get an item from queue and removes it. It gets then pop de data.
     *
     *@return the item or nothing if the queue was empty
     **/
    virtual std::optional<T> get() = 0;

    /**
     *@brief peek at the next data
     *
     *@return the next item to get
     **/
    virtual const std::optional<std::reference_wrapper<const T>> peek() const = 0;

    virtual void pop() = 0;

    virtual void clear() = 0;

    virtual bool isFull() const = 0;

    virtual bool isEmpty() const = 0;

    virtual uint16_t getLength() const = 0;

    virtual uint16_t getFreeSize() const = 0;
};

#endif // __ICIRCULARQUEUE_H_

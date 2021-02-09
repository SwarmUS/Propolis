#ifndef __ICIRCULARQUEUE_H_
#define __ICIRCULARQUEUE_H_

#include <cstdint>
#include <optional>

template <typename T>
class ICircularQueue {
  public:
    ICircularQueue<T>() = default;

    virtual ~ICircularQueue<T>() = default;

    virtual bool push(T item) = 0;

    virtual std::optional<T> get() = 0;

    virtual const std::optional<std::reference_wrapper<const T>> peek() const = 0;

    virtual void pop() = 0;

    virtual void clear() = 0;

    virtual bool isFull() const = 0;

    virtual bool isEmpty() const = 0;

    virtual uint16_t getLength() const = 0;

    virtual uint16_t getFreeSize() const = 0;
};

#endif // __ICIRCULARQUEUE_H_

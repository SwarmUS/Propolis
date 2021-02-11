#ifndef __ICIRCULARQUEUE_H_
#define __ICIRCULARQUEUE_H_

#include <cstdint>
#include <functional>
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
    virtual bool push(const T& item) = 0;

    /**
     *@brief peek at the next data
     *
     *@return the next item to get
     **/
    virtual const std::optional<std::reference_wrapper<const T>> peek() const = 0;

    /**
     *@brief pop the next item
     **/
    virtual void pop() = 0;

    /**
     *@brief clear the queue, expensive call since it needs to call the destrucstor of all the
     *object
     **/
    virtual void clear() = 0;

    /**
     *@brief check if the queue is full
     *
     *@return true if full, false if not
     **/
    virtual bool isFull() const = 0;

    /**
     *@brief check if the queue is empty
     *
     *@return true if empty, false if not
     * */
    virtual bool isEmpty() const = 0;

    /**
     *@brief get the length of the queue
     *
     *@return the number of items currently in it
     **/
    virtual uint16_t getLength() const = 0;

    /**
     * @brief get the number of free slots left in the queue
     *
     * @return the number of free slots in the queue
     * */
    virtual uint16_t getFreeSize() const = 0;

    /**
     * @brief get the next allocation, used to write inplace
     *
     * @b Warning, you need to advance if you write on the reference, so the data is released and
     * the destructor is called
     *
     * @return a writable reference, if there is a slot available in the queue
     * */
    virtual std::optional<std::reference_wrapper<T>> getNextAllocation() = 0;

    /**
     * @brief advance to the next allocation, used after the write on getNextAllocation
     *
     * @b Warning, only advance if there was a write, if not, you a destructor will be called on
     * uninitialiezed memory
     *
     * @return true if could advance (i.e. had space), false if not
     * */
    virtual bool advance() = 0;
};

#endif // __ICIRCULARQUEUE_H_

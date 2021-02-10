#ifndef __CIRCULARQUEUESTACK_H_
#define __CIRCULARQUEUESTACK_H_

#include "CircularQueue.h"

template <typename T, uint16_t maxSize>
class CircularQueueStack : public ICircularQueue<T> {
  public:
    CircularQueueStack() : m_queue(reinterpret_cast<T*>(this->m_queueData), maxSize) {}

    ~CircularQueueStack() override = default;

    bool push(const T& item) override { return m_queue.push(item); }

    const std::optional<std::reference_wrapper<const T>> peek() const override {
        return m_queue.peek();
    }

    void pop() override { return m_queue.pop(); }

    void clear() override { return m_queue.clear(); }

    bool isFull() const override { return m_queue.isFull(); }

    bool isEmpty() const override { return m_queue.isEmpty(); }

    uint16_t getLength() const override { return m_queue.getLength(); };

    uint16_t getFreeSize() const override { return m_queue.getFreeSize(); }

    std::optional<std::reference_wrapper<T>> getNextAllocation() override {
        return m_queue.getNextAllocation();
    }

    bool advance() override { return m_queue.advance(); }

  private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type m_queueData[maxSize];

    CircularQueue<T> m_queue;
};

#endif // __CIRCULARQUEUESTACK_H_

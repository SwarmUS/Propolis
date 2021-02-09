#ifndef __CIRCULAR_QUEUE_H_
#define __CIRCULAR_QUEUE_H_

#include <cstdint>
#include <optional>

template <typename T>
class CircularQueue {
  public:
    CircularQueue<T>(T* data, uint16_t size);

    ~CircularQueue<T>() = default;

    bool push(T item);

    std::optional<T> get();

    const std::optional<std::reference_wrapper<const T>> peek() const;

    void pop();

    void clear();

    bool isFull() const;

    bool isEmpty() const;

    uint16_t getLength() const;

    uint16_t getFreeSize() const;

  private:
    T* m_data;

    uint16_t m_size;

    uint16_t m_readPos;

    uint16_t m_writePos;

    bool m_isFull;
};

#include "CircularQueue.tpp"

#endif //__CIRCULAR_QUEUE_H_

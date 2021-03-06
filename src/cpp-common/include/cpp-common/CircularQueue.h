#ifndef __CIRCULAR_QUEUE_H_
#define __CIRCULAR_QUEUE_H_

#include "ICircularQueue.h"

template <typename T>
class CircularQueue : public ICircularQueue<T> {
  public:
    CircularQueue<T>(T* data, uint32_t size);

    ~CircularQueue<T>() override;

    bool push(const T& item) override;

    const std::optional<std::reference_wrapper<const T>> peek() const override;

    void pop() override;

    void clear() override;

    bool isFull() const override;

    bool isEmpty() const override;

    uint32_t getLength() const override;

    uint32_t getFreeSize() const override;

    std::optional<std::reference_wrapper<T>> getNextAllocation() override;

    bool advance() override;

  private:
    T* m_data;

    uint32_t m_size;

    uint32_t m_readPos;

    uint32_t m_writePos;

    bool m_isFull;
};

#include "CircularQueue.tpp"

#endif //__CIRCULAR_QUEUE_H_

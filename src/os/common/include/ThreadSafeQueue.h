#ifndef __THREADSAFEQUEUE_H_
#define __THREADSAFEQUEUE_H_

#include <LockGuard.h>
#include <cpp-common/ICircularQueue.h>

/**
 *@brief A queue that is thread safe */
template <typename T>
class ThreadSafeQueue : public ICircularQueue<T> {
  public:
    ThreadSafeQueue(ICircularQueue<T>& queue, IMutex& mutex) : m_queue(queue), m_mutex(mutex) {}

    ~ThreadSafeQueue() override = default;

    bool push(const T& item) override {
        LockGuard lock(m_mutex);
        return m_queue.push(item);
    }

    const std::optional<std::reference_wrapper<const T>> peek() const override {
        IMutex* mutableLock = const_cast<IMutex*>(&m_mutex);
        LockGuard lock(*mutableLock);
        return m_queue.peek();
    }

    void pop() override {
        LockGuard lock(m_mutex);
        return m_queue.pop();
    }

    void clear() override {
        LockGuard lock(m_mutex);
        return m_queue.clear();
    }

    bool isFull() const override {
        IMutex* mutableLock = const_cast<IMutex*>(&m_mutex);
        LockGuard lock(*mutableLock);
        return m_queue.isFull();
    }

    bool isEmpty() const override {
        IMutex* mutableLock = const_cast<IMutex*>(&m_mutex);
        LockGuard lock(*mutableLock);
        return m_queue.isEmpty();
    }

    uint16_t getLength() const override {
        IMutex* mutableLock = const_cast<IMutex*>(&m_mutex);
        LockGuard lock(*mutableLock);
        return m_queue.getLength();
    };

    uint16_t getFreeSize() const override {
        IMutex* mutableLock = const_cast<IMutex*>(&m_mutex);
        LockGuard lock(*mutableLock);
        return m_queue.getFreeSize();
    }

    std::optional<std::reference_wrapper<T>> getNextAllocation() override {
        LockGuard lock(m_mutex);
        return m_queue.getNextAllocation();
    }

    bool advance() override {
        LockGuard lock(m_mutex);
        return m_queue.advance();
    }

  private:
    ICircularQueue<T>& m_queue;
    IMutex& m_mutex;
};

#endif // __THREADSAFEQUEUE_H_

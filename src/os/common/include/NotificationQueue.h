#ifndef __NOTIFICATIONQUEUE_H_
#define __NOTIFICATIONQUEUE_H_

#include "IConditionVariable.h"
#include "INotificationQueue.h"

template <typename T>
class NotificationQueue : public INotificationQueue<T> {
  public:
    NotificationQueue(ICircularQueue<T>& queue, IConditionVariable& conditionVar) :
        m_queue(queue), m_conditionVar(conditionVar) {}

    ~NotificationQueue() override = default;

    bool push(const T& item) override {
        m_conditionVar.notify();
        return m_queue.push(item);
    }

    const std::optional<std::reference_wrapper<const T>> peek() const override {
        return m_queue.peek();
    }

    void pop() override { return m_queue.pop(); }

    void clear() override { return m_queue.clear(); }

    bool isFull() const override { return m_queue.isFull(); }

    bool isEmpty() const override { return m_queue.isEmpty(); }

    uint32_t getLength() const override { return m_queue.getLength(); };

    uint32_t getFreeSize() const override { return m_queue.getFreeSize(); }

    std::optional<std::reference_wrapper<T>> getNextAllocation() override {
        m_conditionVar.notify();
        return m_queue.getNextAllocation();
    }

    bool advance() override { return m_queue.advance(); }

    bool wait(uint32_t waitTime) override { return m_conditionVar.wait(waitTime); }

  private:
    ICircularQueue<T>& m_queue;
    IConditionVariable& m_conditionVar;
};

#endif // __NOTIFICATIONQUEUE_H_

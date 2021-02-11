#ifndef __CIRCULAR_QUEUE_TPP_
#define __CIRCULAR_QUEUE_TPP_

#include "CircularQueue.h"

template <typename T>
CircularQueue<T>::CircularQueue(T* data, uint16_t size) :
    m_data(data), m_size(size), m_readPos(0), m_writePos(0), m_isFull(false) {}

template <typename T>
CircularQueue<T>::~CircularQueue() {
    CircularQueue::clear();
}

template <typename T>
bool CircularQueue<T>::push(const T& item) {
    if (CircularQueue<T>::isFull()) {
        return false;
    }

    new (&m_data[m_writePos]) T(item);
    return CircularQueue<T>::advance();
}

template <typename T>
const std::optional<std::reference_wrapper<const T>> CircularQueue<T>::peek() const {
    if (CircularQueue<T>::getLength() == 0) {
        return {};
    }

    return m_data[m_readPos];
}

template <typename T>
void CircularQueue<T>::pop() {
    if (CircularQueue<T>::getLength() == 0) {
        return;
    }

    m_data[m_readPos].~T();
    m_readPos++;

    if (m_readPos >= m_size) {
        m_readPos = 0;
    }
    m_isFull = false;
}

template <typename T>
void CircularQueue<T>::clear() {
    while (!CircularQueue<T>::isEmpty()) {
        CircularQueue<T>::pop();
    }
}

template <typename T>
bool CircularQueue<T>::isFull() const {
    return m_isFull;
}

template <typename T>
bool CircularQueue<T>::isEmpty() const {
    return (m_readPos == m_writePos) && !CircularQueue<T>::isFull();
}

template <typename T>
uint16_t CircularQueue<T>::getLength() const {
    if (CircularQueue<T>::isFull()) {
        return m_size;
    }
    if (m_readPos > m_writePos) {
        return m_size - (m_readPos - m_writePos);
    }
    return m_writePos - m_readPos;
}

template <typename T>
uint16_t CircularQueue<T>::getFreeSize() const {
    if (CircularQueue<T>::isFull()) {
        return 0;
    }

    return m_size - CircularQueue<T>::getLength();
}

template <typename T>
std::optional<std::reference_wrapper<T>> CircularQueue<T>::getNextAllocation() {
    if (CircularQueue<T>::isFull()) {
        return {};
    }

    return m_data[m_readPos];
}

template <typename T>
bool CircularQueue<T>::advance() {
    if (CircularQueue<T>::isFull()) {
        return false;
    }

    m_writePos++;

    if (m_writePos >= m_size) {
        m_writePos = 0;
    }

    if (m_writePos == m_readPos) {
        m_isFull = true;
    }

    return true;
}

#endif //__CIRCULAR_QUEUE_TPP_

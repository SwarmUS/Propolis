#ifndef __CIRCULAR_QUEUE_TPP_
#define __CIRCULAR_QUEUE_TPP_

#include "CircularQueue.h"

template <typename T>
CircularQueue<T>::CircularQueue(T* data, uint16_t size) :
    m_data(data), m_size(size), m_readPos(0), m_writePos(0), m_isFull(false) {}

template <typename T>
bool CircularQueue<T>::push(T item) {
    if (isFull()) {
        return false;
    }
    m_data[m_writePos++] = item;

    if (m_writePos >= m_size) {
        m_writePos = 0;
    }

    if (m_writePos == m_readPos) {
        m_isFull = true;
    }

    return true;
}

template <typename T>
std::optional<T> CircularQueue<T>::get() {
    if (getLength() == 0) {
        return {};
    }

    T item = m_data[m_readPos];
    pop();

    return item;
}

template <typename T>
const std::optional<std::reference_wrapper<const T>> CircularQueue<T>::peek() const {
    if (getLength() == 0) {
        return {};
    }

    return m_data[m_readPos];
}

template <typename T>
void CircularQueue<T>::pop() {
    if (getLength() == 0) {
        return;
    }

    m_readPos++;

    if (m_readPos >= m_size) {
        m_readPos = 0;
    }
    m_isFull = false;
}

template <typename T>
void CircularQueue<T>::clear() {
    m_readPos = 0;
    m_writePos = 0;
    m_isFull = false;
}

template <typename T>
bool CircularQueue<T>::isFull() const {
    return m_isFull;
}

template <typename T>
bool CircularQueue<T>::isEmpty() const {
    return (m_readPos == m_writePos) && !isFull();
}

template <typename T>
uint16_t CircularQueue<T>::getLength() const {
    if (isFull()) {
        return m_size;
    }
    if (m_readPos > m_writePos) {
        return m_size - (m_readPos - m_writePos);
    }
    return m_writePos - m_readPos;
}

template <typename T>
uint16_t CircularQueue<T>::getFreeSize() const {
    if (isFull()) {
        return 0;
    }

    return m_size - getLength();
}

#endif //__CIRCULAR_QUEUE_TPP_

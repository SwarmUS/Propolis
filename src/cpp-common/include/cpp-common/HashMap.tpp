#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

enum TupleIndices { USED_FLAG_INDEX = 0, KEY_INDEX, VALUE_INDEX };

template <typename Key, typename MappedType, uint16_t maxSize>
HashMap<Key, MappedType, maxSize>::HashMap() : m_usedSpaces(0) {
    for (size_t i = 0; i < maxSize; i++) {
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[i]);
        std::get<USED_FLAG_INDEX>(tuple) = false;
    }
}
template <typename Key, typename MappedType, uint16_t maxSize>
HashMap<Key, MappedType, maxSize>::~HashMap() {
    clear();
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::insert(const std::pair<Key, MappedType>& item) {
    if (isFull()) {
        return false;
    }
    bool loopedOnce = false;
    uint16_t index = hash(item.first);
    do {
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        // Insert forbids overwriting
        if (std::get<USED_FLAG_INDEX>(tuple) && std::get<KEY_INDEX>(tuple) == item.first) {
            return false;
        }
        if (std::get<USED_FLAG_INDEX>(tuple) == false) {
            new (&m_storage[index])
                std::tuple<bool, Key, MappedType>(true, item.first, item.second);
            m_usedSpaces++;
            return true;
        }

        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            loopedOnce = true;
            index = 0;
        }
    } while (index < maxSize);
    return false;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::upsert(const std::pair<Key, MappedType>& item) {
    bool loopedOnce = false;
    uint16_t index = hash(item.first);
    do {
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        // Try to overwrite first
        if (std::get<USED_FLAG_INDEX>(tuple) && std::get<KEY_INDEX>(tuple) == item.first) {
            new (&m_storage[index])
                std::tuple<bool, Key, MappedType>(true, item.first, item.second);
            return true;
        }
        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            loopedOnce = true;
            index = 0;
        }
    } while (index < maxSize);
    // If cannot overwrite, try to insert
    return insert(item);
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::remove(Key key) {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        if (std::get<USED_FLAG_INDEX>(tuple) && std::get<KEY_INDEX>(tuple) == key) {
            std::get<VALUE_INDEX>(tuple).~MappedType();
            std::get<USED_FLAG_INDEX>(tuple) = false;
            m_usedSpaces--;
            return true;
        }
        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            index = 0;
            loopedOnce = true;
        }
    } while (index < maxSize);
    return false;
}

template <typename Key, typename MappedType, uint16_t maxSize>
void HashMap<Key, MappedType, maxSize>::clear() {
    for (size_t i = 0; i < maxSize; i++) {
        // Could forego calling constructor since using placement new
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[i]);
        if (std::get<USED_FLAG_INDEX>(tuple)) {
            std::get<VALUE_INDEX>(tuple).~MappedType();
            std::get<USED_FLAG_INDEX>(tuple) = false;
        }
    }
    m_usedSpaces = 0;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::get(Key k, MappedType& item) const {
    const auto& obj = at(k);
    if (obj.has_value()) {
        item = obj.value().get();
        return true;
    }
    return false;
}
template <typename Key, typename MappedType, uint16_t maxSize>
std::optional<std::reference_wrapper<MappedType>> HashMap<Key, MappedType, maxSize>::at(Key key) {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        if (std::get<USED_FLAG_INDEX>(tuple) && std::get<KEY_INDEX>(tuple) == key) {
            return std::get<VALUE_INDEX>(tuple);
        }
        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            index = 0;
            loopedOnce = true;
        }
    } while (index < maxSize);
    return {};
}

template <typename Key, typename MappedType, uint16_t maxSize>
std::optional<std::reference_wrapper<const MappedType>> HashMap<Key, MappedType, maxSize>::at(
    Key key) const {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        const auto& tuple =
            reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        if (std::get<USED_FLAG_INDEX>(tuple) && std::get<KEY_INDEX>(tuple) == key) {
            return std::get<VALUE_INDEX>(tuple);
        }
        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            index = 0;
            loopedOnce = true;
        }
    } while (index < maxSize);
    return {};
}

template <typename Key, typename MappedType, uint16_t maxSize>
uint16_t HashMap<Key, MappedType, maxSize>::getMaxSize() const {
    return maxSize;
}

template <typename Key, typename MappedType, uint16_t maxSize>
uint16_t HashMap<Key, MappedType, maxSize>::getFreeSpace() const {
    return maxSize - m_usedSpaces;
}

template <typename Key, typename MappedType, uint16_t maxSize>
uint16_t HashMap<Key, MappedType, maxSize>::getUsedSpace() const {
    return m_usedSpaces;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::isEmpty() const {
    return m_usedSpaces == 0;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::isFull() const {
    return m_usedSpaces == maxSize;
}

template <typename Key, typename MappedType, uint16_t maxSize>
uint16_t HashMap<Key, MappedType, maxSize>::hash(Key key) {
    return std::hash<Key>{}(key) % maxSize;
}

#endif // __HASH_MAP_TPP_
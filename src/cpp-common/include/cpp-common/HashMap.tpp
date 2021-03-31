#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

#define USED_FLAG_INDEX (0)
#define KEY_INDEX       (1)
#define VALUE_INDEX     (2)

template <typename Key, typename MappedType, uint16_t maxSize>
HashMap<Key, MappedType, maxSize>::HashMap() : m_usedSpaces(0) {
    for (int i; i <maxSize;i++) {
        std::get<USED_FLAG_INDEX>(m_storage[i]) = false;
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
        if (std::get<USED_FLAG_INDEX>(m_storage[index])  == false) {
            new (&m_storage[index]) std::pair<Key, MappedType>(item);
            m_usedSpaces++;
            std::get<USED_FLAG_INDEX>(m_storage[index]) = true;
            return true;
        }
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) == true) {
            // If a key is already present in the map, do not overwrite its value
            if (std::get<KEY_INDEX>(reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index])) ==
                item.first) {
                return false;
            }
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
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) &&
            std::get<KEY_INDEX>(reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index])) ==
                item.first) {
            new (&m_storage[index]) std::pair<Key, MappedType>(item);
            return true;
        }
        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            loopedOnce = true;
            index = 0;
        }
    } while (index < maxSize);
    // Failed to update, trying insert
    return insert(item);
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::remove(Key key) {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) == true &&
            std::get<KEY_INDEX>(reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index])) == key) {
            reinterpret_cast<const std::pair<Key, MappedType>&>(m_storage[index])
                .second.~MappedType();
            std::get<USED_FLAG_INDEX>(m_storage[index]) = false;
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
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) == true) {
            reinterpret_cast<std::pair<Key, MappedType>*>(&m_storage[i])->second.~MappedType();
            std::get<USED_FLAG_INDEX>(m_storage[index]) = false;
        }
    }
    m_usedSpaces = 0;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::get(Key k, MappedType& item) const {
    uint16_t index = hash(k);
    bool loopedOnce = false;
    do {
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) == true) {
            auto& tuple = reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index]);
            if (std::get<KEY_INDEX>(tuple) == k) {
                // emplace on reference passed
                new (&item) MappedType(tuple.second);
                return true;
            }
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
std::optional<std::reference_wrapper<MappedType>> HashMap<Key, MappedType, maxSize>::at(Key key) {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        if (std::get<USED_FLAG_INDEX>(m_storage[index]) == true) {
            auto& tuple = reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[index]);
            if (std::get<KEY_INDEX>(tuple) == key) {
                return std::get<VALUE_INDEX>(tuple);
            }
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
    auto obj = const_cast<const MappedType*>(this)->at(key); // Using the const function
    return const_cast<std::optional<std::reference_wrapper<MappedType>>>(obj);
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
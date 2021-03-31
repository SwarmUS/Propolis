#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

template <typename Key, typename MappedType, uint16_t maxSize>
HashMap<Key, MappedType, maxSize>::HashMap() : m_usedSpaces(0) {
    memset(m_usedSpacesFlag, 0, sizeof(m_usedSpacesFlag));
}
template <typename Key, typename MappedType, uint16_t maxSize>
HashMap<Key, MappedType, maxSize>::~HashMap() {
    // clear();
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::insert(const std::pair<Key, MappedType>& item) {
    bool loopedOnce = false;
    uint16_t index = hash(item.first);
    do {
        if (m_usedSpacesFlag[index] == false) {
            new (&m_storage[index]) std::pair<Key, MappedType>(item);
            m_usedSpaces++;
            m_usedSpacesFlag[index] = true;
            return true;
        }
        if (m_usedSpacesFlag[index] == true) {
            // If a key is already present in the map, do not overwrite its value
            if (reinterpret_cast<const std::pair<Key, MappedType>&>(m_storage[index]).first ==
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
bool HashMap<Key, MappedType, maxSize>::remove(Key key) {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        if (m_usedSpacesFlag[index] == true) {
            auto pair = reinterpret_cast<const std::pair<Key, MappedType>&>(m_storage[index]);
            if (pair.first == key) {
                pair.second.~MappedType();
                m_usedSpacesFlag[index] = false;
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
    return {};
}

template <typename Key, typename MappedType, uint16_t maxSize>
void HashMap<Key, MappedType, maxSize>::clear() {
    for (int i = 0; i < maxSize; i++) {
        // Could forego calling constructor since using placement new
        reinterpret_cast<std::pair<Key, MappedType>*>(&m_storage[i])->second.~MappedType();
        m_usedSpacesFlag[i] = false;
    }
    m_usedSpaces = 0;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::get(Key k, MappedType& item) const {
    uint16_t index = hash(k);
    bool loopedOnce = false;
    do {
        if (m_usedSpacesFlag[index] == true) {
            auto pair = reinterpret_cast<const std::pair<Key, MappedType>&>(m_storage[index]);
            if (pair.first == k) {
                // emplace on reference passed
                new (&item) MappedType(pair.second);
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
std::optional<MappedType> HashMap<Key, MappedType, maxSize>::at(Key key) const {
    uint16_t index = hash(key);
    bool loopedOnce = false;
    do {
        if (m_usedSpacesFlag[index] == true) {
            auto pair = reinterpret_cast<const std::pair<Key, MappedType>&>(m_storage[index]);
            if (pair.first == key) {
                return pair.second;
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
uint16_t HashMap<Key, MappedType, maxSize>::getMaxSize() const {
    return maxSize;
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
    return key % maxSize;
}

#endif // __HASH_MAP_TPP_
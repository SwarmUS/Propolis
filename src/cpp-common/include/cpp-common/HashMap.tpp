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
    std::optional<uint16_t> idxOpt = findIdx(item.first, false);

    if (!idxOpt) {
        return false;
    }

    uint16_t idx = idxOpt.value();
    auto& [used, mapKey, obj] =
        reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[idx]);

    if (used) {
        return false;
    }

    m_usedSpaces++;
    new (&m_storage[idx]) std::tuple<bool, Key, MappedType>(true, item.first, item.second);
    return true;
}

// TODO: remove std pair
template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::upsert(const std::pair<Key, MappedType>& item) {

    std::optional<uint16_t> idxOpt = findIdx(item.first, false);

    if (!idxOpt) {
        return false;
    }

    uint16_t idx = idxOpt.value();
    auto& [used, mapKey, obj] =
        reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[idx]);

    if (used) {
        obj.~MappedType();
    } else {
        m_usedSpaces++;
    }

    new (&m_storage[idx]) std::tuple<bool, Key, MappedType>(true, item.first, item.second);
    return true;
}

template <typename Key, typename MappedType, uint16_t maxSize>
bool HashMap<Key, MappedType, maxSize>::remove(Key key) {
    std::optional<uint16_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return {};
    }

    uint16_t idx = idxOpt.value();
    auto& [used, mapKey, obj] =
        reinterpret_cast<std::tuple<bool, Key, MappedType>&>(m_storage[idx]);

    if (!used) {
        return false;
    }

    obj.~MappedType();
    used = false;
    m_usedSpaces--;
    return true;
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
    // TODO fix
    const HashMap<Key, MappedType, maxSize>* thisConst = static_cast<const HashMap<Key, MappedType, maxSize>*>(this);
    const auto obj = thisConst->at(key);
    if(obj){
        return const_cast<MappedType&>(obj.value().get());
    }
    return {};
}

template <typename Key, typename MappedType, uint16_t maxSize>
std::optional<std::reference_wrapper<const MappedType>> HashMap<Key, MappedType, maxSize>::at(
    Key key) const {
    std::optional<uint16_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return {};
    }

    uint16_t idx = idxOpt.value();
    const auto& [used, mapKey, obj] =
        reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[idx]);

    // if not used is that the object does not exists;
    if (!used) {
        return {};
    }

    return obj;
}

template <typename Key, typename MappedType, uint16_t maxSize>
std::optional<uint16_t> HashMap<Key, MappedType, maxSize>::findIdx(Key key, bool findEmpty) const {
    (void) findEmpty;

    bool loopedOnce = false;
    uint16_t index = hash(key);
    do {
        const auto& [used, mapKey, obj] =
            reinterpret_cast<const std::tuple<bool, Key, MappedType>&>(m_storage[index]);
        // If we found the key or found an empty slot
        if ((used && mapKey == key) || (used == false)) {
            return index;
        }

        index++;
        // Only loop across array once
        if (!loopedOnce && index == maxSize) {
            loopedOnce = true;
            index = 0;
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

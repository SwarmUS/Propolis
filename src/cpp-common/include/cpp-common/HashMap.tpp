#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

template <typename Key, typename MappedType>

HashMap<Key, MappedType>::HashMap(std::tuple<bool, Key, MappedType>* storage,
                                  uint32_t storageSize) :
    m_storage(storage), m_storageSize(storageSize), m_usedSpaces(0) {
    for (size_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];
        used = false;
    }
}
template <typename Key, typename MappedType>
HashMap<Key, MappedType>::~HashMap() {
    HashMap<Key, MappedType>::clear();
}

template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::insert(const Key& key, const MappedType& obj) {
    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return false;
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    if (used) {
        return false;
    }

    m_usedSpaces++;
    new (&m_storage[idx]) std::tuple<bool, Key, MappedType>(true, key, obj);
    return true;
}

// TODO: remove std pair
template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::upsert(const Key& key, const MappedType& obj) {

    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return false;
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    if (used) {
        mapObj.~MappedType();
    } else {
        m_usedSpaces++;
    }

    new (&m_storage[idx]) std::tuple<bool, Key, MappedType>(true, key, obj);
    return true;
}

template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::remove(const Key& key) {
    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return {};
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    if (!used) {
        return false;
    }

    mapObj.~MappedType();
    used = false;
    m_usedSpaces--;
    return true;
}

template <typename Key, typename MappedType>
void HashMap<Key, MappedType>::clear() {
    for (size_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];

        if (used) {
            mapObj.~MappedType();
            used = false;
        }
    }
    m_usedSpaces = 0;
}

template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::get(const Key& k, MappedType& item) const {
    const auto& obj = at(k);
    if (obj.has_value()) {
        item = obj.value().get();
        return true;
    }
    return false;
}
template <typename Key, typename MappedType>
std::optional<std::reference_wrapper<MappedType>> HashMap<Key, MappedType>::at(const Key& key) {
    const auto* thisConst = static_cast<const HashMap<Key, MappedType>*>(this);
    const auto obj = thisConst->at(key);
    if (obj) {
        return const_cast<MappedType&>(obj.value().get());
    }
    return {};
}

template <typename Key, typename MappedType>
std::optional<std::reference_wrapper<const MappedType>> HashMap<Key, MappedType>::at(
    const Key& key) const {
    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return {};
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    // if not used is that the object does not exists;
    if (!used) {
        return {};
    }

    return mapObj;
}

template <typename Key, typename MappedType>
std::optional<uint32_t> HashMap<Key, MappedType>::findIdx(Key key, bool findEmpty) const {
    (void)findEmpty;

    bool loopedOnce = false;
    uint32_t index = hash(key);
    do {
        auto& [used, mapKey, mapObj] = m_storage[index];
        // If we found the key or found an empty slot
        if ((used && mapKey == key) || (used == false)) {
            return index;
        }

        index++;
        // Only loop across array once
        if (!loopedOnce && index == m_storageSize) {
            loopedOnce = true;
            index = 0;
        }
    } while (index < m_storageSize);

    return {};
}

template <typename Key, typename MappedType>
uint32_t HashMap<Key, MappedType>::getMaxSize() const {
    return m_storageSize;
}

template <typename Key, typename MappedType>
uint32_t HashMap<Key, MappedType>::getFreeSpace() const {
    return m_storageSize - m_usedSpaces;
}

template <typename Key, typename MappedType>
uint32_t HashMap<Key, MappedType>::getUsedSpace() const {
    return m_usedSpaces;
}

template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::isEmpty() const {
    return m_usedSpaces == 0;
}

template <typename Key, typename MappedType>
bool HashMap<Key, MappedType>::isFull() const {
    return m_usedSpaces == m_storageSize;
}

template <typename Key, typename MappedType>
uint32_t HashMap<Key, MappedType>::hash(const Key& key) const {
    return std::hash<Key>{}(key) % m_storageSize;
}

#endif // __HASH_MAP_TPP_

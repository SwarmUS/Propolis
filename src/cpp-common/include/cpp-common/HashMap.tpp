#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

template <typename Key, typename Value, class HashFunc>
HashMap<Key, Value, HashFunc>::HashMap(std::tuple<bool, Key, Value>* storage,
                                       uint32_t storageSize) :
    m_storage(storage), m_storageSize(storageSize), m_usedSpaces(0) {
    for (size_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];
        used = false;
    }
}
template <typename Key, typename Value, class HashFunc>
HashMap<Key, Value, HashFunc>::~HashMap() {
    HashMap<Key, Value, HashFunc>::clear();
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::insert(const Key& key, const Value& obj) {
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
    new (&m_storage[idx]) std::tuple<bool, Key, Value>(true, key, obj);
    return true;
}

// TODO: remove std pair
template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::upsert(const Key& key, const Value& obj) {

    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return false;
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    if (used) {
        mapObj.~Value();
    } else {
        m_usedSpaces++;
    }

    new (&m_storage[idx]) std::tuple<bool, Key, Value>(true, key, obj);
    return true;
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::remove(const Key& key) {
    std::optional<uint32_t> idxOpt = findIdx(key, false);

    if (!idxOpt) {
        return {};
    }

    uint32_t idx = idxOpt.value();
    auto& [used, mapKey, mapObj] = m_storage[idx];

    if (!used) {
        return false;
    }

    mapObj.~Value();
    used = false;
    m_usedSpaces--;
    return true;
}

template <typename Key, typename Value, class HashFunc>
void HashMap<Key, Value, HashFunc>::clear() {
    for (size_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];

        if (used) {
            mapObj.~Value();
            used = false;
        }
    }
    m_usedSpaces = 0;
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::get(const Key& k, Value& item) const {
    const auto& obj = at(k);
    if (obj.has_value()) {
        item = obj.value().get();
        return true;
    }
    return false;
}
template <typename Key, typename Value, class HashFunc>
std::optional<std::reference_wrapper<Value>> HashMap<Key, Value, HashFunc>::at(const Key& key) {
    const auto* thisConst = static_cast<const HashMap<Key, Value, HashFunc>*>(this);
    const auto obj = thisConst->at(key);
    if (obj) {
        return const_cast<Value&>(obj.value().get());
    }
    return {};
}

template <typename Key, typename Value, class HashFunc>
std::optional<std::reference_wrapper<const Value>> HashMap<Key, Value, HashFunc>::at(
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

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::forEach(HashMapForEachCallback<const Key&, Value&> callback,
                                            void* context) {
    for (uint32_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];
        if (used) {
            if (!callback(mapKey, mapObj, context)) {
                return false;
            }
        }
    }
    return true;
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::forEach(
    HashMapForEachCallback<const Key&, const Value&> callback, void* context) const {
    // Cannot simply call the non const function since it's the callback arg the need to get it's
    // constness remove
    for (uint32_t i = 0; i < m_storageSize; i++) {
        auto& [used, mapKey, mapObj] = m_storage[i];
        if (used) {
            if (!callback(mapKey, mapObj, context)) {
                return false;
            }
        }
    }
    return true;
}

template <typename Key, typename Value, class HashFunc>
std::optional<uint32_t> HashMap<Key, Value, HashFunc>::findIdx(Key key, bool findEmpty) const {
    (void)findEmpty;

    bool loopedOnce = false;
    uint32_t index = m_hashFunction(key, m_storageSize);
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

template <typename Key, typename Value, class HashFunc>
uint32_t HashMap<Key, Value, HashFunc>::getMaxSize() const {
    return m_storageSize;
}

template <typename Key, typename Value, class HashFunc>
uint32_t HashMap<Key, Value, HashFunc>::getFreeSpace() const {
    return m_storageSize - m_usedSpaces;
}

template <typename Key, typename Value, class HashFunc>
uint32_t HashMap<Key, Value, HashFunc>::getUsedSpace() const {
    return m_usedSpaces;
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::isEmpty() const {
    return m_usedSpaces == 0;
}

template <typename Key, typename Value, class HashFunc>
bool HashMap<Key, Value, HashFunc>::isFull() const {
    return m_usedSpaces == m_storageSize;
}

#endif // __HASH_MAP_TPP_

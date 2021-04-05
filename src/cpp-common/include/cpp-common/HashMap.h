#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "HashFunction.h"
#include "IHashMap.h"
#include <array>
#include <tuple>
#include <type_traits>

// TODO: Implement quadratic jumping instead of linear
template <typename Key, typename Value, class HashFunc = HashFunction<Key>>
class HashMap : public IHashMap<Key, Value> {
  public:
    HashMap(std::tuple<bool, Key, Value>* storage, uint32_t storageSize);
    ~HashMap() override;

    bool insert(const Key& key, const Value& obj) override;
    bool upsert(const Key& key, const Value& obj) override;
    bool get(const Key& key, Value& obj) const override;
    std::optional<std::reference_wrapper<Value>> at(const Key& key) override;
    std::optional<std::reference_wrapper<const Value>> at(const Key& key) const override;
    bool remove(const Key& key) override;
    void clear() override;
    bool isFull() const override;
    bool isEmpty() const override;
    uint32_t getMaxSize() const override;
    uint32_t getUsedSpace() const override;
    uint32_t getFreeSpace() const override;

    // TODO: implement an iterator

  private:
    // Return either the idx matching the key, the next free slot or nothing if there is no more
    // space
    std::optional<uint32_t> findIdx(Key key, bool findEmpty) const;
    std::tuple<bool, Key, Value>* const m_storage;
    const uint32_t m_storageSize;
    uint32_t m_usedSpaces;
    HashFunc m_hashFunction;
};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

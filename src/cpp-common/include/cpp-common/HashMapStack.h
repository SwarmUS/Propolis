#ifndef __HASHMAPSTACK_H_
#define __HASHMAPSTACK_H_

#include "HashMap.h"
#include "IHashMap.h"

template <typename Key, typename MappedType, uint32_t maxSize>
class HashMapStack : public IHashMap<Key, MappedType> {
  public:
    HashMapStack() :
        m_map(reinterpret_cast<std::tuple<bool, Key, MappedType>>(this->m_queueData), maxSize) {}

    ~HashMapStack() override;

    bool insert(const Key& key, const MappedType& obj) override { return m_map.insert(key, obj); }

    bool upsert(const Key& key, const MappedType& obj) override { return m_map.upsert(key, obj); }

    bool get(const Key& key, MappedType& obj) const override { return m_map.get(key, obj); }

    std::optional<std::reference_wrapper<MappedType>> at(const Key& key) override {
        return m_map.at(key);
    }

    std::optional<std::reference_wrapper<const MappedType>> at(const Key& key) const override {
        return m_map.at(key);
    }

    bool remove(const Key& key) override { return m_map.remove(key); }
    void clear() override { m_map.clear(); }

    bool isFull() const override { return m_map.isFull(); }

    bool isEmpty() const override { return m_map.isEmpty(); }
    uint32_t getMaxSize() const override { return m_map.getMaxSize(); }
    uint32_t getUsedSpace() const override { return m_map.getUsedSpace(); }
    uint32_t getFreeSpace() const override { return m_map.getFreeSpace(); }

  private:
    // Using aligned storage for placement new usage when inserting
    typename std::aligned_storage<sizeof(std::tuple<bool, Key, MappedType>),
                                  alignof(std::tuple<bool, Key, MappedType>)>::type

        m_storage[maxSize];
    HashMap<Key, MappedType> m_map;
};

#endif // __HASHMAPSTACK_H_

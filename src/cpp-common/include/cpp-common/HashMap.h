#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "IHashMap.h"
#include <array>
#include <tuple>
#include <type_traits>

// TODO: Implement quadratic jumping instead of linear and inject memory
template <typename Key, typename MappedType, uint16_t maxSize>
class HashMap : public IHashMap<Key, MappedType> {
  public:
    HashMap();
    ~HashMap() override;

    bool insert(const Key& key, const MappedType& obj) override;
    bool upsert(const Key& key, const MappedType& obj) override;
    bool get(const Key& key, MappedType& obj) const override;
    std::optional<std::reference_wrapper<MappedType>> at(const Key& key) override;
    std::optional<std::reference_wrapper<const MappedType>> at(const Key& key) const override;
    bool remove(const Key& key) override;
    void clear() override;
    bool isFull() const override;
    bool isEmpty() const override;
    uint16_t getMaxSize() const override;
    uint16_t getUsedSpace() const override;
    uint16_t getFreeSpace() const override;

    // TODO: implement an iterator

  private:
    // Return either the idx matching the key, the next free slot or nothing if there is no more
    // space
    std::optional<uint16_t> findIdx(Key key, bool findEmpty) const;
    static uint16_t hash(Key key);

    // Using aligned storage for placement new usage when inserting
    typename std::aligned_storage<sizeof(std::tuple<bool, Key, MappedType>),
                                  alignof(std::tuple<bool, Key, MappedType>)>::type
        m_storage[maxSize];

    uint16_t m_usedSpaces;
};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

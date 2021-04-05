#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "IHashMap.h"
#include <array>
#include <tuple>
#include <type_traits>

// TODO: Implement quadratic jumping instead of linear and inject memory
template <typename Key, typename MappedType>
class HashMap : public IHashMap<Key, MappedType> {
  public:
    HashMap(std::tuple<bool, Key, MappedType>* storage, uint32_t storageSize);
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
    uint32_t getMaxSize() const override;
    uint32_t getUsedSpace() const override;
    uint32_t getFreeSpace() const override;

    // TODO: implement an iterator

  private:
    // Return either the idx matching the key, the next free slot or nothing if there is no more
    // space
    std::optional<uint32_t> findIdx(Key key, bool findEmpty) const;
    uint32_t hash(const Key& key) const;

    std::tuple<bool, Key, MappedType>* const m_storage;
    const uint32_t m_storageSize;
    uint32_t m_usedSpaces;
};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

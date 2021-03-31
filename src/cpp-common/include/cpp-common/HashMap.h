#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "IHashMap.h"
#include <array>
#include <type_traits>

// TODO: Implement quadratic jumping instead of linear
template <typename Key, typename MappedType, uint16_t maxSize>
class HashMap : public IHashMap<Key, MappedType, maxSize> {
  public:
    HashMap();
    ~HashMap() override;

    bool insert(const std::pair<Key, MappedType>& item) override;
    bool upsert(const std::pair<Key, MappedType>& item) override;
    bool get(Key key, MappedType& item) const override;
    std::optional<std::reference_wrapper<MappedType>> at(Key key) override;
    std::optional<std::reference_wrapper<const MappedType>> at(Key key) const override;
    bool remove(Key key) override;
    void clear() override;
    bool isFull() const override;
    bool isEmpty() const override;
    uint16_t getMaxSize() const override;
    uint16_t getUsedSpace() const override;
    uint16_t getFreeSpace() const override;

    // TODO: implement an iterator

  private:
    // Using aligned storage for placement new usage when inserting
    typename std::aligned_storage<sizeof(std::pair<Key, MappedType>),
                                  alignof(std::pair<Key, MappedType>)>::type m_storage[maxSize];
    std::array<bool, maxSize> m_usedSpacesFlag;

    // Hashing function of the Key
    static uint16_t hash(Key key);
    uint16_t m_usedSpaces;
};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

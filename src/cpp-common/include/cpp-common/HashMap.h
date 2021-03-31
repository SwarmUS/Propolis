#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "IHashMap.h"
#include <type_traits>

template <typename Key, typename MappedType, uint16_t maxSize>
class HashMap : public IHashMap<Key, MappedType, maxSize> {
  public:
    HashMap();
    ~HashMap() override;

    bool insert(const std::pair<Key, MappedType>& item) override;
    bool get(Key k, MappedType& item) const override;
    std::optional<MappedType> at(Key key) const override;
    bool remove(Key key) override;
    void clear() override;
    bool isFull() const override;
    bool isEmpty() const override;
    uint16_t getMaxSize() const override;

  private:
    // Using aligned storage for placement new usage when inserting
    typename std::aligned_storage<sizeof(std::pair<Key, MappedType>),
                                  alignof(std::pair<Key, MappedType>)>::type m_storage[maxSize];
    bool m_usedSpacesFlag[maxSize];

    // Hashing function of the Key
    static uint16_t hash(Key k);
    uint16_t m_usedSpaces;
};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

#ifndef PROPOLIS_HASHMAP_H
#define PROPOLIS_HASHMAP_H

#include "IHashMap.h"
#include <type_traits>

template <typename key, typename type, uint16_t maxSize>
class HashMap : public IHashMap<key,type,maxSize> {
  public:
    HashMap();
    ~HashMap() override;

    bool insert(const std::pair<key,type>& item) override;
    bool get(key k, type& item) override;
    void clear() override;
    bool isFull() const override;
    bool isEmpty() const override;
    uint16_t getMaxSize() const override;

  protected:
    // Using aligned storage for placement new usage when inserting
    std::aligned_storage< sizeof(type), alignof(type)> m_storage[maxSize];

};

#include "HashMap.tpp"
#endif // PROPOLIS_HASHMAP_H

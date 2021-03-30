#ifndef __HASH_MAP_TPP_
#define __HASH_MAP_TPP_

#include "HashMap.h"

template <typename key, typename type, uint16_t maxSize>
HashMap<key,type,maxSize>::HashMap() {

}

template <typename key, typename type, uint16_t maxSize>
bool HashMap<key,type,maxSize>::insert(const std::pair<key, type>& item) {}

template <typename key, typename type, uint16_t maxSize>
void HashMap<key,type,maxSize>::clear() {}

template <typename key, typename type, uint16_t maxSize>
bool HashMap<key,type,maxSize>::get(key k, type& item) {}

template <typename key, typename type, uint16_t maxSize>
uint16_t HashMap<key,type,maxSize>::getMaxSize() const {return maxSize;}

template <typename key, typename type, uint16_t maxSize>
bool HashMap<key,type,maxSize>::isEmpty() const{}

template <typename key, typename type, uint16_t maxSize>
bool HashMap<key,type,maxSize>::isFull() const {}

#endif // __HASH_MAP_TPP_
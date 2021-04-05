#ifndef __HASHFUNCTION_H_
#define __HASHFUNCTION_H_

#include <functional>

// Uses std::hash as default hash function
template <typename T>
struct HashFunction {
    uint32_t operator()(const T& key, const uint32_t& hashSize) const {
        return std::hash<T>()(key) % hashSize;
    }
};

#endif // __HASHFUNCTION_H_

#ifndef PROPOLIS_IHASHMAP_H
#define PROPOLIS_IHASHMAP_H


#include <cstdint>
#include <utility>

template <typename key, typename type, uint16_t maxSize>
class IHashMap {
  public:
    ~IHashMap<key,type,maxSize>() = default;

    /**
     * @brief Insert an item into the hash map
     * @return true if succesfull, false if the map was full
     */
     virtual bool insert(const std::pair<key,type>& item) = 0;

    /**
    * @brief Return an item from the hash map based on a key
    * @return true if succesfull, false if no item found based on key
    */
     virtual bool get(key k, type& item) = 0;

     /**
      * @brief Clears all items in the map
      */
     virtual void clear() = 0;

     /**
      * @brief Check if the map is full
      * @return true if map is full, false otherwise
      */
     virtual bool isFull() const = 0;

     /**
      * @brief Check if the map is empty
      * @return true if empty, false otherwise
      */
     virtual bool isEmpty() const = 0;

     /**
      * @brief Get the maximum size of the map
      * @return the maximum number of items in the map
      */
     virtual uint16_t getMaxSize() const = 0;
};


#endif // PROPOLIS_IHASHMAP_H

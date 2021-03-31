#ifndef PROPOLIS_IHASHMAP_H
#define PROPOLIS_IHASHMAP_H


#include <cstdint>
#include <utility>
#include <optional>

template <typename Key, typename MappedType, uint16_t maxSize>
class IHashMap {
  public:
    virtual ~IHashMap<Key, MappedType ,maxSize>() = default;

    /**
     * @brief Insert an item into the hash map
     * @return true if successfull, false if the map was full or key already present in map
     */
     virtual bool insert(const std::pair<Key,MappedType>& item) = 0;

    /**
    * @brief Obtain the copy of an item from the hash map based on a Key
    * @param [in] key The key to get the item to get
    * @param [out] item The reference to the item to store the value wanted
    * @return true if succesfull, false if no item found based on Key
    */
     virtual bool get(Key k, MappedType& item) const = 0;

     /**
      * @brief Obtain the copy of an item from the hash map based on a Key
      * @param key The key to get the item to get
      * @return A reference to the mapped type if key was found in map, otherwise an empty optional
      */
     virtual const std::optional<std::reference_wrapper<const MappedType>> at(Key key) const = 0;

     /**
      * @brief Remove an item from the map based on its key
      * @param key The key to the item to remove
      * @return True if an item with desired was found and removed from the map, false otherwise
      */
     virtual bool remove(Key key) = 0;

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

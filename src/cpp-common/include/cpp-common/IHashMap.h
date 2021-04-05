#ifndef PROPOLIS_IHASHMAP_H
#define PROPOLIS_IHASHMAP_H

#include <cstdint>
#include <functional>
#include <optional>
#include <utility>

/**
 * @brief A templated hash map that can store a fixed number of items
 * @tparam Key The key used to find elements in the hash map. Must be some sort of integer
 * @tparam MappedType The type to store in the map. Can be any type
 */
template <typename Key, typename MappedType>
class IHashMap {
  public:
    virtual ~IHashMap<Key, MappedType>() = default;

    /**
     * @brief Insert an item into the hash map
     * @param [in] key the key to store
     * @param [in] obj the object to store
     * @return true if successfull, false if the map was full or key already present in map
     */
    virtual bool insert(const Key& key, const MappedType& obj) = 0;

    /**
     * @brief Update or insert an item into the hash map
     * @param [in] key the key to store
     * @param [in] obj the object to store
     * @return true if successfull, false if the map was full
     */
    virtual bool upsert(const Key& key, const MappedType& obj) = 0;

    /**
     * @brief Obtain the copy of an item from the hash map based on a Key
     * @param [in] key The key to get the item to get
     * @param [out] item The reference to the item to store the value wanted
     * @return true if succesfull, false if no item found based on Key
     */
    virtual bool get(const Key& key, MappedType& item) const = 0;

    /**
     * @brief Obtain a reference of an item from the hash map based on a Key
     * @param key The key to get the item to get
     * @return A an optional reference to the mapped type if key was found in map, otherwise an
     * empty optional
     */
    virtual std::optional<std::reference_wrapper<MappedType>> at(const Key& key) = 0;

    /**
     * @brief Obtain a const reference of an item from the hash map based on a Key
     * @param key The key to get the item to get
     * @return A an optional const reference to the mapped type if key was found in map, otherwise
     * an empty optional
     */
    virtual std::optional<std::reference_wrapper<const MappedType>> at(const Key& key) const = 0;

    /**
     * @brief Remove an item from the map based on its key
     * @param key The key to the item to remove
     * @return True if an item with desired was found and removed from the map, false otherwise
     */
    virtual bool remove(const Key& key) = 0;

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

    /**
     * @brief Get the used space in the map
     * @return the used space in the map, so the number of items
     */
    virtual uint16_t getUsedSpace() const = 0;

    /**
     * @brief Get the free space in the map
     * @return the free space in the map
     */
    virtual uint16_t getFreeSpace() const = 0;
};

#endif // PROPOLIS_IHASHMAP_H

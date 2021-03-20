#ifndef __CPPUTILS_H__
#define __CPPUTILS_H__

/**
 * @brief Function to cast a C++ class enum to its underlying int value
 * @tparam Enumeration Type of enum
 * @param value Enum value
 * @return The int value associated with the enum value
 */
template <typename Enumeration>
constexpr auto as_integer(Enumeration const value) ->
typename std::underlying_type<Enumeration>::type {
    static_assert(std::is_enum<Enumeration>::value, "parameter is not of type enum or enum class");
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

#endif //__CPPUTILS_H__

#ifndef __IHIVEMINDHOSTDESERIALIZER_H_
#define __IHIVEMINDHOSTDESERIALIZER_H_

#include "MessageDTO.h"
#include <variant>

/**
 *@brief Manages the deserialization of messages between the  host and the hivemind. This is one of
 *the entry point for the hivemind-host library
 **/
class IHiveMindHostDeserializer {
  public:
    virtual ~IHiveMindHostDeserializer() = default;

    virtual std::variant<std::monostate, MessageDTO> deserializeFromStream() = 0;
};

#endif // __IHIVEMINDHOSTDESERIALIZER_H_

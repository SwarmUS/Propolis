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

    /**
     *@brief Deserializes a DTO message from a data stream
     *
     *@return a MessageDTO if the operation was successful, a monostate if not*/
    virtual std::variant<std::monostate, MessageDTO> deserializeFromStream() = 0;
};

#endif // __IHIVEMINDHOSTDESERIALIZER_H_

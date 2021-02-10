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
     *@brief Deserializes a DTO message from a data stream, you need to provide the memory where the
     *response will be written
     *
     *@param [out] message where the deserialized message will be written
     *
     *@return bool if the deserialization is success full, false if not. Discard the message if
     *false*/
    virtual bool deserializeFromStream(MessageDTO& message) = 0;
};

#endif // __IHIVEMINDHOSTDESERIALIZER_H_

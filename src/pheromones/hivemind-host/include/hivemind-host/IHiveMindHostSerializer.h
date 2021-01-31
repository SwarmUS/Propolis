#ifndef __IHIVEMINDHOSTSERIALIZER_H_
#define __IHIVEMINDHOSTSERIALIZER_H_

#include "MessageDTO.h"

/**
 *@brief Manages the serialization of messages between the  host and the hivemind. This is one of
 *the entry point for the hivemind-host library
 **/
class IHiveMindHostSerializer {
  public:
    virtual ~IHiveMindHostSerializer() = default;

    /**
     *@brief Serializes a DTO message
     *
     *@return true if the operation was successful, false if not*/
    virtual bool serialize(const MessageDTO& message) = 0;
};

#endif // __IHIVEMINDHOSTSERIALIZER_H_

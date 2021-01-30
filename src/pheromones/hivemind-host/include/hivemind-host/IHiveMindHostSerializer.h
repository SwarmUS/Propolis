#ifndef __IHIVEMINDHOSTSERIALIZER_H_
#define __IHIVEMINDHOSTSERIALIZER_H_

#include "MessageDTO.h"

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

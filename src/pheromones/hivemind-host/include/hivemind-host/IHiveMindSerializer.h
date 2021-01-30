#ifndef __IHIVEMINDSERIALIZER_H_
#define __IHIVEMINDSERIALIZER_H_

#include "MessageDTO.h"

class IHiveMindSerializer {
  public:
    virtual ~IHiveMindSerializer() = default;

    /**
     *@brief Serializes a DTO message
     *
     *@return true if the operation was successful, false if not*/
    virtual bool serialize(const MessageDTO& message) = 0;
};

#endif // __IHIVEMINDSERIALIZER_H_

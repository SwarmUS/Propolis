#ifndef __IHIVEMINDDESERIALIZER_H_
#define __IHIVEMINDDESERIALIZER_H_

#include "MessageDTO.h"
#include <variant>

class IHiveMindDeserializer {
  public:
    virtual ~IHiveMindDeserializer() = default;

    virtual std::variant<std::monostate, MessageDTO> deserialize() = 0;
};

#endif // __IHIVEMINDDESERIALIZER_H_

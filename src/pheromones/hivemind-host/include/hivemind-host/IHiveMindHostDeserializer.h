#ifndef __IHIVEMINDHOSTDESERIALIZER_H_
#define __IHIVEMINDHOSTDESERIALIZER_H_

#include "MessageDTO.h"
#include <variant>

class IHiveMindHostDeserializer {
  public:
    virtual ~IHiveMindHostDeserializer() = default;

    virtual std::variant<std::monostate, MessageDTO> deserialize() = 0;
};

#endif // __IHIVEMINDHOSTDESERIALIZER_H_

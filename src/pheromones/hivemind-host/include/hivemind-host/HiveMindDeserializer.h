#ifndef __HIVEMINDDESERIALIZER_H_
#define __HIVEMINDDESERIALIZER_H_

#include "MessageDTO.h"
#include <common/IProtobufStream.h>
#include <pb_decode.h>
#include <variant>

class HiveMindDeserializer {
  public:
    HiveMindDeserializer(IProtobufStream& stream);

    std::variant<std::monostate, MessageDTO> deserialize();

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDDESERIALIZER_H_

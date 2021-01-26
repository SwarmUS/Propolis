#ifndef __HIVEMINDDESERIALIZER_H_
#define __HIVEMINDDESERIALIZER_H_

#include "Request.h"
#include <common/IProtobufStream.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <variant>

class HiveMindDeserializer {
  public:
    HiveMindDeserializer(IProtobufStream& stream);
    ~HiveMindDeserializer() = default;

    std::variant<std::monostate, Request> deserialize();

  private:
    IProtobufStream& m_stream;
    const pb_ostream_t m_outputStream;
    const pb_istream_t m_inputStream;
};

#endif // __HIVEMINDDESERIALIZER_H_

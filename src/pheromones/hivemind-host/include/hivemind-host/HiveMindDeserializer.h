#ifndef __HIVEMINDDESERIALIZER_H_
#define __HIVEMINDDESERIALIZER_H_

#include "IHiveMindDeserializer.h"
#include <common/IProtobufStream.h>
#include <pb_decode.h>

class HiveMindDeserializer : public IHiveMindDeserializer {
  public:
    HiveMindDeserializer(IProtobufStream& stream);

    ~HiveMindDeserializer() override = default;

    std::variant<std::monostate, MessageDTO> deserialize() override;

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDDESERIALIZER_H_

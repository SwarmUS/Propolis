#ifndef __HIVEMINDHOSTDESERIALIZER_H_
#define __HIVEMINDHOSTDESERIALIZER_H_

#include "IHiveMindHostDeserializer.h"
#include <common/IProtobufStream.h>
#include <pb_decode.h>

class HiveMindHostDeserializer : public IHiveMindHostDeserializer {
  public:
    HiveMindHostDeserializer(IProtobufStream& stream);

    ~HiveMindHostDeserializer() override = default;

    std::variant<std::monostate, MessageDTO> deserializeFromStream() override;

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDHOSTDESERIALIZER_H_

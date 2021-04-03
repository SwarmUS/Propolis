#ifndef __HIVEMINDHOSTDESERIALIZER_H_
#define __HIVEMINDHOSTDESERIALIZER_H_

#include "IHiveMindHostDeserializer.h"
#include <pb_decode.h>
#include <pheromones/IProtobufStream.h>

class HiveMindHostDeserializer : public IHiveMindHostDeserializer {
  public:
    HiveMindHostDeserializer(IProtobufInputStream& stream);

    ~HiveMindHostDeserializer() override = default;

    bool deserializeFromStream(MessageDTO& message) override;

  private:
    IProtobufInputStream& m_stream;

    static bool streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDHOSTDESERIALIZER_H_

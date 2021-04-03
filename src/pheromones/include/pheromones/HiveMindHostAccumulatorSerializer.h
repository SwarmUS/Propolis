#ifndef PROPOLIS_HIVEMINDHOSTACCUMULATORSERIALIZER_H
#define PROPOLIS_HIVEMINDHOSTACCUMULATORSERIALIZER_H

#include "IHiveMindHostSerializer.h"
#include "pheromones/IProtobufStream.h"
#include <array>

constexpr uint32_t g_maxBufferSize = 1024;

class HiveMindHostAccumulatorSerializer : public IHiveMindHostSerializer {
  public:
    HiveMindHostAccumulatorSerializer(IProtobufOutputStream& stream);
    ~HiveMindHostAccumulatorSerializer() override = default;

    bool serializeToStream(const MessageDTO& message) override;

  private:
    IProtobufOutputStream& m_stream;
    static bool streamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count);

    std::array<uint8_t, g_maxBufferSize> m_data;
    uint32_t m_messageLength;
};

#endif // PROPOLIS_HIVEMINDHOSTACCUMULATORSERIALIZER_H

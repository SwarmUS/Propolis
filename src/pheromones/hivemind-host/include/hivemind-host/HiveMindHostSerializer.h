#ifndef __HIVEMINDHOSTSERIALIZER_H_
#define __HIVEMINDHOSTSERIALIZER_H_

#include "IHiveMindHostSerializer.h"
#include "MessageDTO.h"
#include <common/IProtobufStream.h>
#include <pb_encode.h>
#include <variant>

class HiveMindHostSerializer : public IHiveMindHostSerializer {
  public:
    HiveMindHostSerializer(IProtobufStream& stream);

    ~HiveMindHostSerializer() override = default;

    bool serialize(const MessageDTO& message) override;

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDHOSTSERIALIZER_H_

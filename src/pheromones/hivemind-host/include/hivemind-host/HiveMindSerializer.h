#ifndef __HIVEMINDSERIALIZER_H_
#define __HIVEMINDSERIALIZER_H_

#include "IHiveMindSerializer.h"
#include "MessageDTO.h"
#include <common/IProtobufStream.h>
#include <pb_encode.h>
#include <variant>

class HiveMindSerializer : public IHiveMindSerializer {
  public:
    HiveMindSerializer(IProtobufStream& stream);

    ~HiveMindSerializer() override = default;

    bool serialize(const MessageDTO& message) override;

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDSERIALIZER_H_

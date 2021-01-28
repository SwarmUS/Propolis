#ifndef __HIVEMINDSERIALIZER_H_
#define __HIVEMINDSERIALIZER_H_

#include "MessageDTO.h"
#include <common/IProtobufStream.h>
#include <pb_encode.h>
#include <variant>

class HiveMindSerializer {
  public:
    HiveMindSerializer(IProtobufStream& stream);

    bool serialize(const MessageDTO& message);

  private:
    IProtobufStream& m_stream;

    static bool streamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count);
};

#endif // __HIVEMINDSERIALIZER_H_

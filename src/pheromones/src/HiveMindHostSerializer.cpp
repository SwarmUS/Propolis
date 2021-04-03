#include "HiveMindHostSerializer.h"
#include <pb_encode.h>

HiveMindHostSerializer::HiveMindHostSerializer(IProtobufOutputStream& stream) : m_stream(stream) {}

bool HiveMindHostSerializer::serializeToStream(const MessageDTO& message) {

    Message msgSend;
    message.serialize(msgSend);

    pb_ostream_t outputStream{HiveMindHostSerializer::streamCallback, this, SIZE_MAX, 0, 0};

    return pb_encode_ex(&outputStream, Message_fields, &msgSend, PB_ENCODE_DELIMITED);
}

bool HiveMindHostSerializer::streamCallback(pb_ostream_t* stream,
                                            const pb_byte_t* buf,
                                            size_t count) {

    HiveMindHostSerializer* serializer = (HiveMindHostSerializer*)stream->state;
    return serializer->m_stream.send(buf, count);
}

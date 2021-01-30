#include "HiveMindHostSerializer.h"
#include <pb_encode.h>

HiveMindHostSerializer::HiveMindHostSerializer(IProtobufStream& stream) : m_stream(stream) {}

bool HiveMindHostSerializer::serialize(const MessageDTO& message) {

    Message msg_send;
    message.serialize(msg_send);

    pb_ostream_t outputStream{HiveMindHostSerializer::streamCallback, this, SIZE_MAX, 0, 0};

    return pb_encode_ex(&outputStream, Message_fields, &msg_send, PB_ENCODE_DELIMITED);
}

bool HiveMindHostSerializer::streamCallback(pb_ostream_t* stream,
                                            const pb_byte_t* buf,
                                            size_t count) {

    HiveMindHostSerializer* _this = (HiveMindHostSerializer*)stream->state;
    return _this->m_stream.send(buf, count);
}

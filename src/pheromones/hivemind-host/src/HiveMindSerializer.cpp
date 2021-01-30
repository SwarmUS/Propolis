#include "HiveMindSerializer.h"

HiveMindSerializer::HiveMindSerializer(IProtobufStream& stream) : m_stream(stream) {}

bool HiveMindSerializer::serialize(const MessageDTO& message) {

    Message msg_send;
    message.serialize(msg_send);

    pb_ostream_t outputStream{HiveMindSerializer::streamCallback, this, SIZE_MAX, 0, 0};

    bool status = pb_encode_ex(&outputStream, Message_fields, &msg_send, PB_ENCODE_DELIMITED);
    return status;
}

bool HiveMindSerializer::streamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count) {

    HiveMindSerializer* _this = (HiveMindSerializer*)stream->state;
    return _this->m_stream.send(buf, count);
}

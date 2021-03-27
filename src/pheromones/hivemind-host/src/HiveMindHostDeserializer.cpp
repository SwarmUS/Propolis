#include "HiveMindHostDeserializer.h"
#include <message.pb.h>
#include <pb_decode.h>

HiveMindHostDeserializer::HiveMindHostDeserializer(IProtobufInputStream& stream) : m_stream(stream) {}

bool HiveMindHostDeserializer::deserializeFromStream(MessageDTO& message) {
    Message msgReceive = Message_init_default;

    pb_istream_t inputStream{HiveMindHostDeserializer::streamCallback, this, SIZE_MAX, 0};

    bool status = pb_decode_ex(&inputStream, Message_fields, &msgReceive, PB_DECODE_DELIMITED);

    if (status) {
        message = MessageDTO(msgReceive);
    }

    return status;
}

bool HiveMindHostDeserializer::streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count) {

    HiveMindHostDeserializer* deserializer = (HiveMindHostDeserializer*)stream->state;
    return deserializer->m_stream.receive(buf, count);
}

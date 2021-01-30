#include "HiveMindHostDeserializer.h"
#include <message.pb.h>
#include <pb_decode.h>

HiveMindHostDeserializer::HiveMindHostDeserializer(IProtobufStream& stream) :
    m_stream(stream) {}

std::variant<std::monostate, MessageDTO> HiveMindHostDeserializer::deserialize() {
    Message msg_receive = Message_init_default;

    pb_istream_t inputStream{HiveMindHostDeserializer::streamCallback, this, SIZE_MAX, 0};

    bool status = pb_decode_ex(&inputStream, Message_fields, &msg_receive, PB_DECODE_DELIMITED);

    if (status) {
        return MessageDTO(msg_receive);
    }

    return std::monostate();
}

bool HiveMindHostDeserializer::streamCallback(pb_istream_t* stream, pb_byte_t* buf, size_t count) {

    HiveMindHostDeserializer* _this = (HiveMindHostDeserializer*)stream->state;
    return _this->m_stream.receive(buf, count);
}

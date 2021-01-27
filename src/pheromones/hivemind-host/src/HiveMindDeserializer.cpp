#include "HiveMindDeserializer.h"
#include <message.pb.h>
#include <pb_decode.h>
#include <pb_encode.h>

HiveMindDeserializer::HiveMindDeserializer(IProtobufStream& stream) : m_stream(stream) {}

std::variant<std::monostate, Request2> HiveMindDeserializer::deserialize() {
    // stream definition

    /*-------- SENDER -------*/
    Message msg_receive = Message_init_default;

    pb_istream_t inputStream;

    inputStream.callback = HiveMindDeserializer::streamCallback;
    inputStream.state = this;

    bool status = pb_decode(&inputStream, Message_fields, &msg_receive);
    (void) status;

    return std::monostate();
}

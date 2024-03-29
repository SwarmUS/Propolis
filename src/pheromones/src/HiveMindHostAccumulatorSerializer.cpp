#include "HiveMindHostAccumulatorSerializer.h"
#include <cstring>
#include <pb_encode.h>

HiveMindHostAccumulatorSerializer::HiveMindHostAccumulatorSerializer(
    IProtobufOutputStream& stream) :
    m_stream(stream), m_data({}), m_messageLength(0) {}

bool HiveMindHostAccumulatorSerializer::serializeToStream(const MessageDTO& message) {
    Message msgSend;
    message.serialize(msgSend);

    pb_ostream_t outputStream{HiveMindHostAccumulatorSerializer::streamCallback, this,
                              2 * Message_size, 0, 0};

    if (pb_encode_ex(&outputStream, Message_fields, &msgSend, PB_ENCODE_DELIMITED)) {
        bool ret = m_stream.send(m_data.data(), m_messageLength);
        m_messageLength = 0;
        return ret;
    }
    return false;
}

bool HiveMindHostAccumulatorSerializer::streamCallback(pb_ostream_t* stream,
                                                       const pb_byte_t* buf,
                                                       size_t count) {
    auto* serializer = (HiveMindHostAccumulatorSerializer*)stream->state;
    // set index to write
    if (serializer->m_messageLength + count >= g_maxBufferSize) {
        return false;
    }
    std::memcpy(&serializer->m_data[serializer->m_messageLength], buf, count);
    serializer->m_messageLength += count;
    return true;
}

#ifndef __PROTOBUFSTREAMBUFFERINTERFACEMOCK_H_
#define __PROTOBUFSTREAMBUFFERINTERFACEMOCK_H_

#include <array>
#include <pheromones/IProtobufStream.h>
#include <message.pb.h>
#include <pb_decode.h>
#include <pb_encode.h>

class ProtobufStreamInterfaceBufferMock : public IProtobufStream {

  public:
    ProtobufStreamInterfaceBufferMock() {
        m_ostream = pb_ostream_from_buffer(m_array.data(), s_maxArraySize);
        m_istream = pb_istream_from_buffer(m_array.data(), sizeof(Message));
    }

    ~ProtobufStreamInterfaceBufferMock() = default;

    bool receive(uint8_t* data, uint16_t length) override {
        return pb_read(&m_istream, data, length);
    }

    bool send(const uint8_t* data, uint16_t length) override {
        return pb_write(&m_ostream, data, length);
    }

    const static uint16_t s_maxArraySize = 1024;
    std::array<uint8_t, s_maxArraySize> m_array;
    pb_ostream_t m_ostream;
    pb_istream_t m_istream;
};

#endif // __PROTOBUFSTREAMBUFFERINTERFACEMOCK_H_

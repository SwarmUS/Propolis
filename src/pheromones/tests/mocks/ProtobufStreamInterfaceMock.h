#ifndef __PROTOBUFSTREAMINTERFACEMOCK_H_
#define __PROTOBUFSTREAMINTERFACEMOCK_H_

#include <gmock/gmock.h>
#include <pheromones/IProtobufStream.h>

class ProtobufStreamInterfaceMock : public IProtobufStream {

  public:
    ~ProtobufStreamInterfaceMock() = default;

    MOCK_METHOD(bool, receive, (uint8_t * data, uint16_t length), (override));

    MOCK_METHOD(bool, send, (const uint8_t* data, uint16_t length), (override));
};

#endif // __PROTOBUFSTREAMINTERFACEMOCK_H_

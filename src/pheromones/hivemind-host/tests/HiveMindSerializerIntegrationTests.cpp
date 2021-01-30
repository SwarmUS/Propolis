#include "mocks/ProtobufStreamBufferInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindSerializer.h>

class HiveMindSerializerIntegrationFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceBufferMock m_streamInterfaceBufferMock;
    HiveMindSerializer* m_serializer;
    MessageDTO* m_messageDTO;
    std::string m_functionName = "Hello world";

    void SetUp() override {

        FunctionCallRequestDTO funRequestDTO(m_functionName.c_str(), (FunctionCallArgumentDTO*)NULL,
                                             0);
        RequestDTO requestDTO(1, funRequestDTO);
        m_messageDTO = new MessageDTO(1, 2, requestDTO);

        m_serializer = new HiveMindSerializer(m_streamInterfaceBufferMock);
    }

    void TearDown() override { delete m_serializer; }
};

TEST_F(HiveMindSerializerIntegrationFixture, HiveMindSerializer_integration_valid_message) {
    // Given

    // Then
    bool ret = m_serializer->serialize(*m_messageDTO);

    // Expect
    Message messageReceived;
    bool retDecode = pb_decode_ex(&m_streamInterfaceBufferMock.m_istream, Message_fields,
                                  &messageReceived, PB_DECODE_DELIMITED);

    EXPECT_EQ(ret, true);
    EXPECT_EQ(retDecode, true);
    EXPECT_STREQ(messageReceived.message.request.message.function_call.function_name,
                 m_functionName.c_str());
}

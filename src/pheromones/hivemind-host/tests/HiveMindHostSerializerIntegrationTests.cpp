#include "mocks/ProtobufStreamBufferInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindHostSerializer.h>

class HiveMindHostSerializerIntegrationFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceBufferMock m_streamInterfaceBufferMock;
    HiveMindHostSerializer* m_serializer;
    MessageDTO* m_messageDTO;
    std::string m_functionName = "Hello world";

    void SetUp() override {

        FunctionCallRequestDTO funRequestDTO(m_functionName.c_str(), (FunctionCallArgumentDTO*)NULL,
                                             0);
        UserCallRequestDTO ureq(UserCallTargetDTO::BUZZ, UserCallTargetDTO::BUZZ, funRequestDTO);
        RequestDTO requestDTO(1, ureq);
        m_messageDTO = new MessageDTO(1, 2, requestDTO);

        m_serializer = new HiveMindHostSerializer(m_streamInterfaceBufferMock);
    }

    void TearDown() override { delete m_serializer; }
};

TEST_F(HiveMindHostSerializerIntegrationFixture, HiveMindSerializer_integration_valid_message) {
    // Given

    // Then
    bool ret = m_serializer->serializeToStream(*m_messageDTO);

    // Expect
    Message messageReceived;
    bool retDecode = pb_decode_ex(&m_streamInterfaceBufferMock.m_istream, Message_fields,
                                  &messageReceived, PB_DECODE_DELIMITED);

    EXPECT_EQ(ret, true);
    EXPECT_EQ(retDecode, true);
    EXPECT_STREQ(
        messageReceived.message.request.message.userCall.request.functionCall.function_name,
        m_functionName.c_str());
}

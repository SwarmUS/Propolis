#include "mocks/ProtobufStreamBufferInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindHostDeserializer.h>

class HiveMindHostDeserializerIntegrationFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceBufferMock m_streamInterfaceBufferMock;
    HiveMindHostDeserializer* m_deserializer;
    std::string m_functionName = "Hello world";
    Message m_message;

    void SetUp() override {

        FunctionCallRequestDTO funRequestDTO(m_functionName.c_str(), (FunctionCallArgumentDTO*)NULL,
                                             0);
        UserCallRequestDTO ureq(UserCallDestinationDTO::BUZZ, funRequestDTO);
        RequestDTO requestDTO(1, ureq);
        MessageDTO messageDTO(1, 2, requestDTO);
        messageDTO.serialize(m_message);

        m_deserializer = new HiveMindHostDeserializer(m_streamInterfaceBufferMock);
    }

    void TearDown() override { delete m_deserializer; }
};

TEST_F(HiveMindHostDeserializerIntegrationFixture, HiveMindDeserializer_integration_valid_message) {
    // Given
    pb_encode_ex(&m_streamInterfaceBufferMock.m_ostream, Message_fields, &m_message,
                 PB_ENCODE_DELIMITED);

    // Then
    MessageDTO message;
    bool messageReceived = m_deserializer->deserializeFromStream(message);

    // Expect
    const RequestDTO* request = std::get_if<RequestDTO>(&message.getMessage());
    const UserCallRequestDTO* uRequest = std::get_if<UserCallRequestDTO>(&request->getRequest());
    const FunctionCallRequestDTO* fRequest =
        std::get_if<FunctionCallRequestDTO>(&uRequest->getRequest());

    EXPECT_TRUE(messageReceived);
    EXPECT_TRUE(request != NULL);
    EXPECT_TRUE(uRequest != NULL);
    EXPECT_TRUE(fRequest != NULL);
    EXPECT_STREQ(fRequest->getFunctionName(), m_functionName.c_str());
}

TEST_F(HiveMindHostDeserializerIntegrationFixture,
       HiveMindDeserializer_integration_invalidMessage) {
    // Given
    // Corrupting the message with un unknown field
    m_message.which_message = (pb_size_t)UINT32_MAX;
    pb_encode_ex(&m_streamInterfaceBufferMock.m_ostream, Message_fields, &m_message,
                 PB_ENCODE_DELIMITED);

    // Then
    MessageDTO message;
    bool messageReceived = m_deserializer->deserializeFromStream(message);

    // Expect
    const RequestDTO* request = std::get_if<RequestDTO>(&message.getMessage());
    // The message will still be valid, only the sub message won't
    EXPECT_TRUE(messageReceived);
    EXPECT_TRUE(request == NULL);
}

TEST_F(HiveMindHostDeserializerIntegrationFixture,
       HiveMindDeserializer_integration_invalidSerialization) {
    // Given
    // Simply not sending a message, shouldn't be able to parse it
    m_streamInterfaceBufferMock.m_istream =
        pb_istream_from_buffer(m_streamInterfaceBufferMock.m_array.data(), 0);

    // Then
    MessageDTO message;
    auto messageReceived = m_deserializer->deserializeFromStream(message);

    // Expect
    EXPECT_FALSE(messageReceived);
}

#include <gtest/gtest.h>
#include <hivemind-host/MessageDTO.h>

class MessageDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_sourceId = 42;
    static constexpr uint32_t gc_destinationId = 69;
    MessageDTO* m_message;

    void SetUp() override {
        // Inserting garbage
        FunctionCallRequestDTO freq(NULL, NULL, 0);
        UserCallRequestDTO ureq(UserCallDestinationDTO::BUZZ, freq);
        RequestDTO reqDTO = RequestDTO(1, ureq);
        m_message = new MessageDTO(gc_sourceId, gc_destinationId, reqDTO);
    }

    void TearDown() override { delete m_message; }
};

TEST_F(MessageDTOFixture, MessageDTO_serialize_request_valid) {
    // Given
    Message msg;

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.sourceId, gc_sourceId);
    EXPECT_EQ(msg.destinationId, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_request_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_response_valid) {
    // Given
    Message msg;

    // Then
    FunctionCallResponseDTO fResponse(GenericResponseStatusDTO::Ok, NULL);
    UserCallResponseDTO uResponse(UserCallDestinationDTO::BUZZ, fResponse);
    ResponseDTO response(1, uResponse);
    m_message->setMessage(response);

    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.sourceId, gc_sourceId);
    EXPECT_EQ(msg.destinationId, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_response_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_invalid) {
    // Given
    Message msg;

    // Then
    m_message->setMessage(std::monostate());
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_FALSE(ret);
}

#include <gtest/gtest.h>
#include <pheromones/MessageDTO.h>

class MessageDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_sourceId = 42;
    static constexpr uint32_t gc_destinationId = 69;
    MessageDTO* m_message;

    void SetUp() override {
        // Inserting garbage
        FunctionCallRequestDTO freq(NULL, NULL, 0);
        UserCallRequestDTO ureq(UserCallTargetDTO::BUZZ, UserCallTargetDTO::BUZZ, freq);
        RequestDTO reqDTO = RequestDTO(1, ureq);
        m_message = new MessageDTO(gc_sourceId, gc_destinationId, reqDTO);
    }

    void TearDown() override { delete m_message; }
};

TEST_F(MessageDTOFixture, MessageDTO_constructor_hiveconnecthivemind_valid) {
    // Given
    Message msg;
    msg.which_message = Message_hiveconnect_hivemind_tag;

    // Then
    MessageDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<HiveConnectHiveMindApiDTO>(message.getMessage()));
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_request_valid) {
    // Given
    Message msg;

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_request_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_response_valid) {
    // Given
    Message msg;

    // Then
    FunctionCallResponseDTO fResponse(GenericResponseStatusDTO::Ok, NULL);
    UserCallResponseDTO uResponse(UserCallTargetDTO::BUZZ, UserCallTargetDTO::BUZZ, fResponse);
    ResponseDTO response(1, uResponse);
    m_message->setMessage(response);

    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_response_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_greeting_valid) {
    // Given
    GreetingDTO greeting(gc_sourceId);
    Message msg;
    m_message->setMessage(greeting);

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_greeting_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_buzz_valid) {
    // Given
    VmMessage vmMsg;
    vmMsg.which_message = VmMessage_buzz_tag;
    VmMessageDTO vmMsgDto(vmMsg);
    Message msg;
    m_message->setMessage(vmMsgDto);

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_vm_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_networkAPI_valid) {
    // Given
    NetworkApiDTO networkApiDto(IPDiscoveryDTO(1));
    Message msg;
    m_message->setMessage(networkApiDto);

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_network_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_interlocAPI_valid) {
    // Given
    SetInterlocStateDTO interlocApidto = SetInterlocStateDTO(InterlocStateDTO::STANDBY);
    Message msg;
    m_message->setMessage(interlocApidto);

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_interloc_tag);
}

TEST_F(MessageDTOFixture, MessageDTO_serialize_hiveconnect_hivemind_valid) {
    // Given
    Message msg;
    m_message->setMessage(HiveConnectHiveMindApiDTO(1, GetAgentsListRequestDTO()));

    // Then
    bool ret = m_message->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.source_id, gc_sourceId);
    EXPECT_EQ(msg.destination_id, gc_destinationId);
    EXPECT_EQ(msg.which_message, Message_hiveconnect_hivemind_tag);
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

#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocOutputMessageDTO.h>

class InterlocOutputMessageTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_deserialize_StateChange) {
    InterlocOutputMessage msg;
    InterlocStateChange internalMsg{};

    msg.which_outputMessage = InterlocOutputMessage_stateChange_tag;
    msg.outputMessage.stateChange = internalMsg;

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(msg);
    auto ret = dto.getMessage();

    EXPECT_TRUE(std::holds_alternative<InterlocStateChangeDTO>(ret));
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_deserialize_RawAngleData) {
    InterlocOutputMessage msg;
    InterlocRawAngleData internalMsg{};

    msg.which_outputMessage = InterlocOutputMessage_rawAngleData_tag;
    msg.outputMessage.rawAngleData = internalMsg;

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(msg);
    auto ret = dto.getMessage();

    EXPECT_TRUE(std::holds_alternative<InterlocRawAngleDataDTO>(ret));
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_deserialize_Dump) {
    InterlocOutputMessage msg;
    InterlocDump internalMsg{};

    msg.which_outputMessage = InterlocOutputMessage_interlocDump_tag;
    msg.outputMessage.interlocDump = internalMsg;

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(msg);
    auto ret = dto.getMessage();

    EXPECT_TRUE(std::holds_alternative<InterlocDumpDTO>(ret));
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_deserialize_Invalid) {
    InterlocOutputMessage msg;
    msg.which_outputMessage = PB_SIZE_MAX;

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(msg);
    auto ret = dto.getMessage();

    EXPECT_TRUE(std::holds_alternative<std::monostate>(ret));
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_serialize_StateChange) {
    InterlocOutputMessage msg;
    InterlocStateChangeDTO stateChange =
        InterlocStateChangeDTO(InterlocStateDTO::STANDBY, InterlocStateDTO::OPERATING);

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(stateChange);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_outputMessage, InterlocOutputMessage_stateChange_tag);
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_serialize_RawAngleData) {
    InterlocOutputMessage msg;
    InterlocRawAngleDataDTO rawAngleData = InterlocRawAngleDataDTO();

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(rawAngleData);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_outputMessage, InterlocOutputMessage_rawAngleData_tag);
}

TEST_F(InterlocOutputMessageTestFixture, InterlocOutputMessage_serialize_Dump) {
    InterlocOutputMessage msg;
    InterlocDump dumpMsg;
    dumpMsg.positionUpdates_count = 0;
    InterlocDumpDTO dumpDto = InterlocDumpDTO(dumpMsg);

    InterlocOutputMessageDTO dto = InterlocOutputMessageDTO(dumpDto);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_outputMessage, InterlocOutputMessage_interlocDump_tag);
}
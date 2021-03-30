#include <gtest/gtest.h>
#include <hivemind-host/CalibrationMessageDTO.h>

class CalibrationMessageFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_deserialize_startCalib) {
    CalibrationMessage msg;
    StartCalibration call{};
    msg.which_call = CalibrationMessage_startCalib_tag;
    msg.call.startCalib = call;

    CalibrationMessageDTO dto = CalibrationMessageDTO(msg);
    auto ret = dto.getCall();

    EXPECT_TRUE(std::holds_alternative<StartCalibrationDTO>(ret));
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_deserialize_stopCalib) {
    CalibrationMessage msg;
    StopCalibration call{};
    msg.which_call = CalibrationMessage_stopCalib_tag;
    msg.call.stopCalib = call;

    CalibrationMessageDTO dto = CalibrationMessageDTO(msg);
    auto ret = dto.getCall();

    EXPECT_TRUE(std::holds_alternative<StopCalibrationDTO>(ret));
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_deserialize_setCalibDistance) {
    CalibrationMessage msg;
    SetCalibrationDistance call{};
    msg.which_call = CalibrationMessage_setDistance_tag;
    msg.call.setDistance = call;

    CalibrationMessageDTO dto = CalibrationMessageDTO(msg);
    auto ret = dto.getCall();

    EXPECT_TRUE(std::holds_alternative<SetCalibrationDistanceDTO>(ret));
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_deserialize_invalid) {
    CalibrationMessage msg;
    msg.which_call = PB_SIZE_MAX;

    CalibrationMessageDTO dto = CalibrationMessageDTO(msg);
    auto ret = dto.getCall();

    EXPECT_TRUE(std::holds_alternative<std::monostate>(ret));
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_serialize_startCalib) {
    auto call = StartCalibrationDTO(CalibrationModeDTO::UNSUPORTED);
    CalibrationMessage msg;

    CalibrationMessageDTO dto = CalibrationMessageDTO(call);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_call, CalibrationMessage_startCalib_tag);
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_serialize_stopCalib) {
    auto call = StopCalibrationDTO();
    CalibrationMessage msg;

    CalibrationMessageDTO dto = CalibrationMessageDTO(call);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_call, CalibrationMessage_stopCalib_tag);
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_serialize_setCalibDistance) {
    auto call = SetCalibrationDistanceDTO(42.42);
    CalibrationMessage msg;

    CalibrationMessageDTO dto = CalibrationMessageDTO(call);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_call, CalibrationMessage_setDistance_tag);
}

TEST_F(CalibrationMessageFixture, CalibrationMessageDTO_serialize_invalid) {
    CalibrationMessage msgIn;
    CalibrationMessage msgOut;
    msgIn.which_call = PB_SIZE_MAX;

    CalibrationMessageDTO dto = CalibrationMessageDTO(msgIn);
    auto ret = dto.serialize(msgOut);

    EXPECT_FALSE(ret);
}

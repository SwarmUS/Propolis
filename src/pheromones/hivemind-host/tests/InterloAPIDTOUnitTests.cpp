#include <gtest/gtest.h>
#include <hivemind-host/InterlocAPIDTO.h>

class InterlocAPIFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_calibrationCall) {
    InterlocAPI msg;
    Calibration call;
    msg.which_message = InterlocAPI_calibration_tag;
    msg.message.calibration = call;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<CalibrationMessageDTO>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_invalidCall) {
    InterlocAPI msg;
    msg.which_message = -1;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<std::monostate>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_calibrationCall) {
    InterlocAPI msg;
    auto callDto = CalibrationMessageDTO(StopCalibrationDTO());
    auto dto = InterlocAPIDTO(callDto);

    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, InterlocAPI_calibration_tag);
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_invalidCall) {
    InterlocAPI msgIn;
    InterlocAPI msgOut;
    msgIn.which_message = -1;
    auto dto = InterlocAPIDTO(msgIn);

    auto ret = dto.serialize(msgOut);

    EXPECT_FALSE(ret);
}
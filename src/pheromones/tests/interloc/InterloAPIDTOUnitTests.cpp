#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocAPIDTO.h>
#include <pheromones/interloc/SetInterlocStateDTO.h>

class InterlocAPIFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_setState) {
    InterlocAPI msg;
    SetInterlocState call{};
    msg.which_message = InterlocAPI_setState_tag;
    msg.message.setState = call;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<SetInterlocStateDTO>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_configure) {
    InterlocAPI msg;
    InterlocConfiguration call{};
    msg.which_message = InterlocAPI_configure_tag;
    msg.message.configure = call;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<InterlocConfigurationDTO>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_output) {
    InterlocAPI msg;
    InterlocOutputMessage call{};
    msg.which_message = InterlocAPI_output_tag;
    msg.message.output = call;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<InterlocOutputMessageDTO>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_deserialize_invalidCall) {
    InterlocAPI msg;
    msg.which_message = PB_SIZE_MAX;
    auto dto = InterlocAPIDTO(msg);

    auto ret = dto.getAPICall();

    EXPECT_TRUE(std::holds_alternative<std::monostate>(ret));
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_calibrationCall) {
    InterlocAPI msg;
    auto callDto = SetInterlocStateDTO(InterlocStateDTO::STANDBY);
    auto dto = InterlocAPIDTO(callDto);

    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, InterlocAPI_setState_tag);
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_configure) {
    InterlocAPI msg;
    auto callDto = InterlocConfigurationDTO(ConfigureAngleCalibrationDTO(10));
    auto dto = InterlocAPIDTO(callDto);

    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, InterlocAPI_configure_tag);
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_output) {
    InterlocAPI msg;
    auto callDto = InterlocOutputMessageDTO(
        InterlocStateChangeDTO(InterlocStateDTO::STANDBY, InterlocStateDTO::OPERATING));
    auto dto = InterlocAPIDTO(callDto);

    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, InterlocAPI_output_tag);
}

TEST_F(InterlocAPIFixture, InterlocAPIDTO_serialize_invalidCall) {
    InterlocAPI msgIn;
    InterlocAPI msgOut;
    msgIn.which_message = PB_SIZE_MAX;
    auto dto = InterlocAPIDTO(msgIn);

    auto ret = dto.serialize(msgOut);

    EXPECT_FALSE(ret);
}
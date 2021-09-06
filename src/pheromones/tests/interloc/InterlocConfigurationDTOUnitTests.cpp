#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocConfigurationDTO.h>

class InterlocConfigurationTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Construct_AngleConfig) {
    ConfigureAngleCalibration configMsg{};
    InterlocConfiguration msg{};

    msg.configurationMessage.configureAngleCalibration = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureAngleCalibration_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);

    EXPECT_TRUE(
        std::holds_alternative<ConfigureAngleCalibrationDTO>(dto.getConfigurationMessage()));
}

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Construct_TWRConfig) {
    ConfigureTWRCalibration configMsg{};
    InterlocConfiguration msg{};

    msg.configurationMessage.configureTWRCalibration = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureTWRCalibration_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);

    EXPECT_TRUE(std::holds_alternative<ConfigureTWRCalibrationDTO>(dto.getConfigurationMessage()));
}

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Serialize_AngleConfig) {
    ConfigureAngleCalibration configMsg{};
    InterlocConfiguration msg{};
    InterlocConfiguration outputMsg{};

    configMsg.numberOfFrames = 42;
    msg.configurationMessage.configureAngleCalibration = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureAngleCalibration_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);
    auto ret = dto.serialize(outputMsg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(outputMsg.configurationMessage.configureAngleCalibration.numberOfFrames,
              configMsg.numberOfFrames);
}

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Serialize_TWRConfig) {
    ConfigureTWRCalibration configMsg;
    InterlocConfiguration msg;
    InterlocConfiguration outputMsg;

    configMsg.distance = 42.42;
    msg.configurationMessage.configureTWRCalibration = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureTWRCalibration_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);
    auto ret = dto.serialize(outputMsg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(outputMsg.configurationMessage.configureTWRCalibration.distance, configMsg.distance);
}
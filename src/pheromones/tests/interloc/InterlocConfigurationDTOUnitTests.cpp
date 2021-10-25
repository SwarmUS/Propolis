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

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Construct_DumpConfig) {
    ConfigureInterlocDumps configMsg{};
    InterlocConfiguration msg{};

    msg.configurationMessage.configureInterlocDumps = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureInterlocDumps_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);

    EXPECT_TRUE(std::holds_alternative<ConfigureInterlocDumpsDTO>(dto.getConfigurationMessage()));
}

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Construct_AngleParameters) {
    ConfigureAngleParameters configMsg{};
    InterlocConfiguration msg{};

    msg.configurationMessage.configureAngleParameters = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureAngleParameters_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);

    EXPECT_TRUE(std::holds_alternative<ConfigureAngleParametersDTO>(dto.getConfigurationMessage()));
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

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Serialize_DumpConfig) {
    ConfigureInterlocDumps configMsg;
    InterlocConfiguration msg;
    InterlocConfiguration outputMsg;

    configMsg.enable = true;
    msg.configurationMessage.configureInterlocDumps = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureInterlocDumps_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);
    auto ret = dto.serialize(outputMsg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(outputMsg.configurationMessage.configureInterlocDumps.enable, configMsg.enable);
}

TEST_F(InterlocConfigurationTestFixture, InterlocConfiguration_Serialize_AngleParameters) {
    ConfigureAngleParameters configMsg;
    InterlocConfiguration msg;
    InterlocConfiguration outputMsg;

    configMsg.anglePairId = 42;
    msg.configurationMessage.configureAngleParameters = configMsg;
    msg.which_configurationMessage = InterlocConfiguration_configureAngleParameters_tag;

    InterlocConfigurationDTO dto = InterlocConfigurationDTO(msg);
    auto ret = dto.serialize(outputMsg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(outputMsg.configurationMessage.configureAngleParameters.anglePairId,
              configMsg.anglePairId);
}
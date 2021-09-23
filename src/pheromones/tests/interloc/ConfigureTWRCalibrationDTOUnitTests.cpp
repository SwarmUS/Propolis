#include <gtest/gtest.h>
#include <pheromones/interloc/ConfigureTWRCalibrationDTO.h>

class ConfigureTWRCalibrationTestFixutre : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(ConfigureTWRCalibrationTestFixutre, ConfigureTWRCalibration_deserialize_distanceSet) {
    ConfigureTWRCalibration msg;
    msg.distance = 42.42;

    ConfigureTWRCalibrationDTO dto = ConfigureTWRCalibrationDTO(msg);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, msg.distance);
}

TEST_F(ConfigureTWRCalibrationTestFixutre, ConfigureTWRCalibration_construct_distanceSet) {
    float distance = 42.42;

    ConfigureTWRCalibrationDTO dto = ConfigureTWRCalibrationDTO(distance);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, distance);
}

TEST_F(ConfigureTWRCalibrationTestFixutre, ConfigureTWRCalibration_setDistance) {
    ConfigureTWRCalibration msg;
    ConfigureTWRCalibrationDTO dto = ConfigureTWRCalibrationDTO(msg);
    float distance = 42.42;

    dto.setDistance(distance);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, distance);
}

TEST_F(ConfigureTWRCalibrationTestFixutre, ConfigureTWRCalibration_serialize_setDistance) {
    ConfigureTWRCalibration msg;
    float distance = 42.42;
    ConfigureTWRCalibrationDTO dto = ConfigureTWRCalibrationDTO(distance);

    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.distance, distance);
}
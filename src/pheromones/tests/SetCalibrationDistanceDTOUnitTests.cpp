#include <gtest/gtest.h>
#include <pheromones/SetCalibrationDistanceDTO.h>

class SetCalibrationDistanceFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(SetCalibrationDistanceFixture, SetCalibrationDistanceDTO_deserialize_distanceSet) {
    SetCalibrationDistance msg;
    msg.distance = 42.42;

    SetCalibrationDistanceDTO dto = SetCalibrationDistanceDTO(msg);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, msg.distance);
}

TEST_F(SetCalibrationDistanceFixture, SetCalibrationDistanceDTO_construct_distanceSet) {
    float distance = 42.42;

    SetCalibrationDistanceDTO dto = SetCalibrationDistanceDTO(distance);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, distance);
}

TEST_F(SetCalibrationDistanceFixture, SetCalibrationDistanceDTO_setDistance) {
    SetCalibrationDistance msg;
    SetCalibrationDistanceDTO dto = SetCalibrationDistanceDTO(msg);
    float distance = 42.42;

    dto.setDistance(distance);
    float ret = dto.getDistance();

    EXPECT_EQ(ret, distance);
}

TEST_F(SetCalibrationDistanceFixture, SetCalibrationDistanceDTO_serialize_setDistance) {
    SetCalibrationDistance msg;
    float distance = 42.42;
    SetCalibrationDistanceDTO dto = SetCalibrationDistanceDTO(distance);

    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.distance, distance);
}
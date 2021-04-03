#include <gtest/gtest.h>
#include <pheromones/StopCalibrationDTO.h>

class StopCalibrationDTOFixture : public testing::Test {
  public:
    StopCalibrationDTO* m_dto;
    StopCalibration m_msg;

    void SetUp() override { m_dto = new StopCalibrationDTO(m_msg); }

    void TearDown() override { delete m_dto; }
};

TEST_F(StopCalibrationDTOFixture, StopCalibrationDTO_serialize_returnsTrue) {
    StopCalibration outMsg;

    bool ret = m_dto->serialize(outMsg);

    EXPECT_TRUE(ret);
}

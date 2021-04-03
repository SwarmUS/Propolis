#include <gtest/gtest.h>
#include <pheromones/CalibrationModeDTO.h>

class CalibrationModeDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_initiator) {
    auto ret = dtoToCalibrationMode(CalibrationModeDTO::INITIATOR);

    EXPECT_EQ(ret, CalibrationMode_INITIATOR);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_responder) {
    auto ret = dtoToCalibrationMode(CalibrationModeDTO::RESPONDER);

    EXPECT_EQ(ret, CalibrationMode_RESPONDER);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_unsuporter) {
    auto ret = dtoToCalibrationMode(CalibrationModeDTO::UNSUPORTED);

    EXPECT_EQ(ret, CalibrationMode_UNSUPORTED);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_initiator) {
    auto ret = calibrationModeToDTO(CalibrationMode_INITIATOR);

    EXPECT_EQ(ret, CalibrationModeDTO::INITIATOR);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_responder) {
    auto ret = calibrationModeToDTO(CalibrationMode_RESPONDER);

    EXPECT_EQ(ret, CalibrationModeDTO::RESPONDER);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_unsuporter) {
    auto ret = calibrationModeToDTO(CalibrationMode_UNSUPORTED);

    EXPECT_EQ(ret, CalibrationModeDTO::UNSUPORTED);
}

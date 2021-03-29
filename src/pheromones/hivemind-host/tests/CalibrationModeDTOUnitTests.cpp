#include <gtest/gtest.h>
#include <hivemind-host/CalibrationModeDTO.h>

class CalibrationModeDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_initiator) {
    auto ret = dtoToTarget(CalibrationModeDTO::INITIATOR);

    EXPECT_EQ(ret, CalibrationMode_INITIATOR);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_responder) {
    auto ret = dtoToTarget(CalibrationModeDTO::RESPONDER);

    EXPECT_EQ(ret, CalibrationMode_RESPONDER);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_dtoToTarget_unsuporter) {
    auto ret = dtoToTarget(CalibrationModeDTO::UNSUPORTED);

    EXPECT_EQ(ret, CalibrationMode_UNSUPORTED);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_initiator) {
    auto ret = targetToDTO(CalibrationMode_INITIATOR);

    EXPECT_EQ(ret, CalibrationModeDTO::INITIATOR);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_responder) {
    auto ret = targetToDTO(CalibrationMode_RESPONDER);

    EXPECT_EQ(ret, CalibrationModeDTO::RESPONDER);
}

TEST_F(CalibrationModeDTOFixture, CalibrationModeDTO_targetToDto_unsuporter) {
    auto ret = targetToDTO(CalibrationMode_UNSUPORTED);

    EXPECT_EQ(ret, CalibrationModeDTO::UNSUPORTED);
}

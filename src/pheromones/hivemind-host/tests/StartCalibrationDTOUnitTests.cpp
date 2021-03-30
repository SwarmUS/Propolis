#include <gtest/gtest.h>
#include <hivemind-host/StartCalibrationDTO.h>

class StartCalibtionDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(StartCalibtionDTOFixture, StartCalibrationDTO_deserialize_valid) {
    // Given
    StartCalibration msg;
    msg.mode = CalibrationMode_INITIATOR;
    StartCalibrationDTO dto = StartCalibrationDTO(msg);

    // Then
    auto ret = dto.getCalibrationMode();

    // Expect
    EXPECT_EQ(ret, calibrationModeToDTO(msg.mode));
}

TEST_F(StartCalibtionDTOFixture, StartCalibrationDTO_setMode) {
    // Given
    auto mode = CalibrationModeDTO::INITIATOR;
    StartCalibrationDTO dto = StartCalibrationDTO(mode);

    // Then
    auto ret = dto.getCalibrationMode();

    // Expect
    EXPECT_EQ(ret, mode);
}

TEST_F(StartCalibtionDTOFixture, StartCalibrationDTO_serialize_valid) {
    // Given
    StartCalibration msg;
    auto mode = CalibrationModeDTO::INITIATOR;
    StartCalibrationDTO dto = StartCalibrationDTO(mode);

    // Then
    auto ret = dto.serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.mode, dtoToCalibrationMode(mode));
}

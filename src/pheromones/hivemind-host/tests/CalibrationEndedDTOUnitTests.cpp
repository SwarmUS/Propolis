#include <gtest/gtest.h>
#include <hivemind-host/CalibrationEndedDTO.h>

class CalibrationEndedFixture : public testing::Test {
  public:
    CalibrationEndedDTO* m_dto;
    CalibrationEnded m_msg;

    void SetUp() override { m_dto = new CalibrationEndedDTO(m_msg); }

    void TearDown() override {}
};

TEST_F(CalibrationEndedFixture, CalibrationEndedDTO_serialize_returnsTrue) {
    CalibrationEnded outMsg;

    bool ret = m_dto->serialize(outMsg);

    EXPECT_TRUE(ret);
}

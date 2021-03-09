#include <gtest/gtest.h>
#include <hivemind-host/FunctionListLengthRequestDTO.h>

class FunctionListLengthRequestDTOFixture : public testing::Test {
  public:
    FunctionListLengthRequestDTO* m_fListResquest;

    void SetUp() override { m_fListResquest = new FunctionListLengthRequestDTO(); }

    void TearDown() override { delete m_fListResquest; }
};

TEST_F(FunctionListLengthRequestDTOFixture, FunctionListLengthRequestDTO_serialize_valid) {
    // Given
    FunctionListLengthRequest fListReq;

    // Then
    bool ret = m_fListResquest->serialize(fListReq);

    // Expect
    EXPECT_TRUE(ret);
}

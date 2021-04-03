#include <gtest/gtest.h>
#include <pheromones/FunctionListLengthResponseDTO.h>

class FunctionListLengthResponseDTOFixture : public testing::Test {
  public:
    FunctionListLengthResponseDTO* m_fListResquest;
    const uint16_t m_length = 42;

    void SetUp() override { m_fListResquest = new FunctionListLengthResponseDTO(m_length); }

    void TearDown() override { delete m_fListResquest; }
};

TEST_F(FunctionListLengthResponseDTOFixture, FunctionListLengthResponseDTO_serialize_valid) {
    // Given
    FunctionListLengthResponse fListResp;

    // Then
    bool ret = m_fListResquest->serialize(fListResp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(fListResp.function_array_length, m_length);
}

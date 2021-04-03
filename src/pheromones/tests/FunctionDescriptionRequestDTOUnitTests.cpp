#include <gtest/gtest.h>
#include <pheromones/FunctionDescriptionRequestDTO.h>

class FunctionDescriptionRequestDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_index = 42;
    FunctionDescriptionRequestDTO* m_descReq;

    void SetUp() override { m_descReq = new FunctionDescriptionRequestDTO(gc_index); }

    void TearDown() override { delete m_descReq; }
};

TEST_F(FunctionDescriptionRequestDTOFixture, FunctionDescriptionRequestDTO_serialize_valid) {
    // Given
    FunctionDescriptionRequest descReq;

    // Then
    bool ret = m_descReq->serialize(descReq);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(descReq.function_list_index, gc_index);
}

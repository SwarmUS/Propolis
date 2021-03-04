#include <gtest/gtest.h>
#include <hivemind-host/IdResponseDTO.h>

class IdResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    IdResponseDTO* m_idResponse;

    void SetUp() override { m_idResponse = new IdResponseDTO(gc_id); }

    void TearDown() override { delete m_idResponse; }
};

TEST_F(IdResponseDTOFixture, IdResponseDTO_serialize_valid) {
    // Given
    IdResponse idResp;

    // Then
    bool ret = m_idResponse->serialize(idResp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(idResp.id, gc_id);
}

#include <gtest/gtest.h>
#include <hivemind-host/IdRequestDTO.h>

class IdRequestDTOFixture : public testing::Test {
  public:
    IdRequestDTO* m_idResquest;

    void SetUp() override { m_idResquest = new IdRequestDTO(); }

    void TearDown() override { delete m_idResquest; }
};

TEST_F(IdRequestDTOFixture, IdRequestDTO_serialize_valid) {
    // Given
    IdRequest idReq;

    // Then
    bool ret = m_idResquest->serialize(idReq);

    // Expect
    EXPECT_TRUE(ret);
}

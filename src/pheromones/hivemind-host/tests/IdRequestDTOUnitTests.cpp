#include <gtest/gtest.h>
#include <hivemind-host/IdRequestDTO.h>

class IdRequestDTOFixture : public testing::Test {
  public:
    IdRequestDTO* m_idRequest;

    void SetUp() override { m_idRequest = new IdRequestDTO(); }

    void TearDown() override { delete m_idRequest; }
};

TEST_F(IdRequestDTOFixture, IdRequestDTO_serialize_valid) {
    // Given
    IdRequest idReq;

    // Then
    bool ret = m_idRequest->serialize(idReq);

    // Expect
    EXPECT_TRUE(ret);
}

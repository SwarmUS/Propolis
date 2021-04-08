
#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetNeighborsListResponseDTO.h>

class GetNeighborsListResponseDTOFixture : public testing::Test {
  public:
    GetNeighborsListResponseDTO* m_resp;

    void SetUp() override { m_resp = new GetNeighborsListResponseDTO(NULL, 0); }

    void TearDown() override { delete m_resp; }
};

TEST_F(GetNeighborsListResponseDTOFixture, GetNeighborsListResponse_constructor_noOverflow) {
    // Given
    std::string rndString = randomString(1024);

    // Then
    GetNeighborsListResponseDTO resp((uint16_t*)rndString.data(), rndString.size());

    // Expect
    EXPECT_EQ(resp.getNeighborsLength(), GetNeighborsListResponseDTO::NEIGHBORS_MAX_SIZE);
}

TEST_F(GetNeighborsListResponseDTOFixture, GetNeighborsListResponse_serialize_valid) {
    // Given
    GetNeighborsListResponse resp;

    // Then
    bool ret = m_resp->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.neighbors_count, m_resp->getNeighborsLength());
}

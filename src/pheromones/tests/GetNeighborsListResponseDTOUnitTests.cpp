
#include "mocks/Utils.h"
#include <cstring>
#include <gtest/gtest.h>
#include <pheromones/GetNeighborsListResponseDTO.h>

class GetNeighborsListResponseDTOFixture : public testing::Test {
  public:
    GetNeighborsListResponseDTO* m_resp;

    void SetUp() override {
        uint16_t neighbors[] = {11, 22, 33, 44};
        m_resp = new GetNeighborsListResponseDTO(neighbors, 4);
    }

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

TEST_F(GetNeighborsListResponseDTOFixture, GetNeighborsListResponse_constructor_wellKnownValues) {
    // Given
    uint16_t neighbors[] = {11, 22, 33, 44};

    // Then
    GetNeighborsListResponseDTO list(neighbors, 4);

    // Expect
    EXPECT_EQ(0, std::memcmp(neighbors, list.getNeighbors().data(), 4));
}

TEST_F(GetNeighborsListResponseDTOFixture, GetNeighborsListResponse_serialize_valid) {
    // Given
    GetNeighborsListResponse resp;

    // Then
    bool ret = m_resp->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.neighbors_count, m_resp->getNeighborsLength());
    for (uint16_t i = 0; i < m_resp->getNeighborsLength(); i++) {
        EXPECT_EQ(resp.neighbors[i], m_resp->getNeighbors()[i]);
    }
}

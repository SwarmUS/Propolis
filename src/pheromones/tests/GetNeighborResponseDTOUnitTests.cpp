#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetNeighborResponseDTO.h>

class GetNeighborResponseDTOFixture : public testing::Test {
  public:
    const uint32_t m_robotId = 42;
    GetNeighborResponseDTO* m_resp;

    void SetUp() override {
        m_resp = new GetNeighborResponseDTO(m_robotId, RelativePositionDTO(42, 24, true));
    }

    void TearDown() override { delete m_resp; }
};

TEST_F(GetNeighborResponseDTOFixture, GetNeighborResponse_serialize_valid) {
    // Given
    GetNeighborResponse resp;

    // Then
    bool ret = m_resp->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(m_robotId, resp.neighbor_id);
}

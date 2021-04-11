#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetNeighborRequestDTO.h>

class GetNeighborRequestDTOFixture : public testing::Test {
  public:
    const uint32_t m_robotId = 42;

    GetNeighborRequestDTO* m_req;

    void SetUp() override { m_req = new GetNeighborRequestDTO(m_robotId); }

    void TearDown() override { delete m_req; }
};

TEST_F(GetNeighborRequestDTOFixture, GetNeighborRequest_serialize_valid) {
    // Given
    GetNeighborRequest req;

    // Then
    bool ret = m_req->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.neighbor_id, m_req->getNeighborId());
}

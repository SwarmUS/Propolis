#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/NeighborPositionDTO.h>

class NeighborPositionDTOFixture : public testing::Test {
  public:
    const float m_distance = 42;
    const uint32_t m_orientation = 24;
    const bool m_inLos = true;

    NeighborPositionDTO* m_pos;

    void SetUp() override { m_pos = new NeighborPositionDTO(m_distance, m_orientation, m_inLos); }

    void TearDown() override { delete m_pos; }
};

TEST_F(NeighborPositionDTOFixture, NeighborPosition_serialize_valid) {
    // Given
    NeighborPosition pos;

    // Then
    bool ret = m_pos->serialize(pos);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(pos.distance, m_pos->getDistance());
    EXPECT_EQ(pos.azimuth, m_pos->getAzimuth());
    EXPECT_EQ(pos.in_los, m_pos->inLOS());
}

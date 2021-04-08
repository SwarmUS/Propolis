#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/RelativePositionDTO.h>

class RelativePositionDTOFixture : public testing::Test {
  public:
    const float m_distance = 42;
    const uint32_t m_orientation = 24;
    const bool m_inLos = true;

    RelativePositionDTO* m_pos;

    void SetUp() override { m_pos = new RelativePositionDTO(m_distance, m_orientation, m_inLos); }

    void TearDown() override { delete m_pos; }
};

TEST_F(RelativePositionDTOFixture, RelativePosition_serialize_valid) {
    // Given
    RelativePosition pos;

    // Then
    bool ret = m_pos->serialize(pos);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(pos.distance, m_pos->getDistance());
    EXPECT_EQ(pos.relative_orientation, m_pos->getRelativeOrientation());
    EXPECT_EQ(pos.inLOS, m_pos->inLOS());
}

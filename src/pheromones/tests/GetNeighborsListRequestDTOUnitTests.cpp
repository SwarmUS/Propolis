#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetNeighborsListRequestDTO.h>

class GetNeighborsListRequestDTOFixture : public testing::Test {
  public:
    const uint32_t m_robotId = 42;

    GetNeighborsListRequestDTO* m_req;

    void SetUp() override { m_req = new GetNeighborsListRequestDTO(); }

    void TearDown() override { delete m_req; }
};

TEST_F(GetNeighborsListRequestDTOFixture, GetNeighborsListRequest_serialize_valid) {
    // Given
    GetNeighborsListRequest req;

    // Then
    bool ret = m_req->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
}

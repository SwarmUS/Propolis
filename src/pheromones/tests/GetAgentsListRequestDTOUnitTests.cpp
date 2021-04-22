#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetAgentsListRequestDTO.h>

class GetAgentsListRequestDTOFixture : public testing::Test {
  public:
    const uint32_t m_robotId = 42;

    GetAgentsListRequestDTO* m_req;

    void SetUp() override { m_req = new GetAgentsListRequestDTO(); }

    void TearDown() override { delete m_req; }
};

TEST_F(GetAgentsListRequestDTOFixture, GetAgentsListRequest_serialize_valid) {
    // Given
    GetAgentsListRequest req;

    // Then
    bool ret = m_req->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
}

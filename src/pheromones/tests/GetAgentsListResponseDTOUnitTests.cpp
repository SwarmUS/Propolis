#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GetAgentsListResponseDTO.h>

class GetAgentsListResponseDTOFixture : public testing::Test {
  public:
    GetAgentsListResponseDTO* m_resp;

    void SetUp() override { m_resp = new GetAgentsListResponseDTO(NULL, 0); }

    void TearDown() override { delete m_resp; }
};

TEST_F(GetAgentsListResponseDTOFixture, GetAgentsListResponse_constructor_noOverflow) {
    // Given
    std::string rndString = randomString(1024);

    // Then
    GetAgentsListResponseDTO resp((uint16_t*)rndString.data(), rndString.size());

    // Expect
    EXPECT_EQ(resp.getAgentsLength(), GetAgentsListResponseDTO::AGENTS_MAX_SIZE);
}

TEST_F(GetAgentsListResponseDTOFixture, GetAgentsListResponse_serialize_valid) {
    // Given
    GetAgentsListResponse resp;

    // Then
    bool ret = m_resp->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.agents_count, m_resp->getAgentsLength());
}

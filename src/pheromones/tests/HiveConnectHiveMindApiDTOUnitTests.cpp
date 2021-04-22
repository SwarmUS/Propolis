#include <gtest/gtest.h>
#include <pheromones/HiveConnectHiveMindApiDTO.h>

class HiveConnectHiveMindApiDTOFixture : public testing::Test {
  public:
    HiveConnectHiveMindApiDTO* m_request;

    void SetUp() override { m_request = new HiveConnectHiveMindApiDTO(HiveConnectHiveMindApi{}); }

    void TearDown() override { delete m_request; }
};

TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_agentsReq) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_agents_req_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetAgentsListRequestDTO>(message.getMessage()));
}

TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_agentsResp) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_agents_resp_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetAgentsListResponseDTO>(message.getMessage()));
}

TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_getAgentsRequest) {
    // Given
    m_request->setMessage(GetAgentsListRequestDTO());
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_agents_req_tag);
}

TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_getAgentsResponse) {
    // Given
    m_request->setMessage(GetAgentsListResponseDTO(NULL, 0));
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_agents_resp_tag);
}

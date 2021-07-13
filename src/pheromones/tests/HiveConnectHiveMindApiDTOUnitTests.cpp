#include <gtest/gtest.h>
#include <pheromones/HiveConnectHiveMindApiDTO.h>

class HiveConnectHiveMindApiDTOFixture : public testing::Test {
  public:
    HiveConnectHiveMindApiDTO* m_request;
    const uint32_t m_messageId = 42;

    void SetUp() override {
        HiveConnectHiveMindApi api;
        api.message_id = m_messageId;
        m_request = new HiveConnectHiveMindApiDTO(api);
    }

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


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_config_get_request) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_network_config_get_request_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<HiveConnectNetworkConfigGetRequestDTO>(message.getMessage()));
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_config_set_request) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_network_config_set_request_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<HiveConnectNetworkConfigSetRequestDTO>(message.getMessage()));
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_config_get_response) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_network_config_get_response_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<HiveConnectNetworkConfigGetResponseDTO>(message.getMessage()));
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_constructor_config_set_response) {
    // Given
    HiveConnectHiveMindApi msg;
    msg.which_message = HiveConnectHiveMindApi_network_config_set_response_tag;

    // Then
    HiveConnectHiveMindApiDTO message(msg);

    // Expect
    EXPECT_TRUE(std::holds_alternative<HiveConnectNetworkConfigSetResponseDTO>(message.getMessage()));
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
    EXPECT_EQ(msg.message_id, m_messageId);
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
    EXPECT_EQ(msg.message_id, m_messageId);
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_getConfigRequest) {
    // Given
    m_request->setMessage(HiveConnectNetworkConfigGetRequestDTO());
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_network_config_get_request_tag);
    EXPECT_EQ(msg.message_id, m_messageId);
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_setConfigRequest) {
    // Given
    m_request->setMessage(HiveConnectNetworkConfigSetRequestDTO());
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_network_config_set_request_tag);
    EXPECT_EQ(msg.message_id, m_messageId);
}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_getConfigResponse) {
    // Given
    HiveConnectNetworkAccessDTO networkAccessDto("test_ssid", "test_password");
    HiveConnectRootNodeDTO rootNodeDto(true);
    HiveConnectMeshEnableDTO meshEnableDto(true);
    m_request->setMessage(HiveConnectNetworkConfigGetResponseDTO(networkAccessDto, rootNodeDto, meshEnableDto));
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_network_config_get_response_tag);
    EXPECT_EQ(msg.message_id, m_messageId);

    EXPECT_TRUE(msg.message.network_config_get_response.has_network_access);
    EXPECT_STREQ(msg.message.network_config_get_response.network_access.ssid, "test_ssid");
    EXPECT_STREQ(msg.message.network_config_get_response.network_access.password, "test_password");

    EXPECT_TRUE(msg.message.network_config_get_response.has_root_node);
    EXPECT_TRUE(msg.message.network_config_get_response.root_node.is_root);

    EXPECT_TRUE(msg.message.network_config_get_response.has_mesh_enable);
    EXPECT_TRUE(msg.message.network_config_get_response.mesh_enable.use_mesh);

}


TEST_F(HiveConnectHiveMindApiDTOFixture, HiveConnectHiveMindApi_serialize_setConfigResponse) {
    // Given
    GenericResponseDTO genericResponseDto(GenericResponseStatusDTO::Ok, "Response Ok");
    m_request->setMessage(HiveConnectNetworkConfigSetResponseDTO(genericResponseDto));
    HiveConnectHiveMindApi msg;

    // Then
    bool ret = m_request->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.which_message, HiveConnectHiveMindApi_network_config_set_response_tag);
    EXPECT_EQ(msg.message_id, m_messageId);

    EXPECT_TRUE(msg.message.network_config_set_response.has_response);
    EXPECT_EQ(msg.message.network_config_set_response.response.status, GenericResponseStatus_OK);
    EXPECT_STREQ(msg.message.network_config_set_response.response.details, "Response Ok");
}
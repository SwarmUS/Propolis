#include "pheromones/HiveConnectNetowrkConfigGetResponseDTO.h"
#include <gtest/gtest.h>

class HiveConnectNetworkConfigGetResponseDTOTests : public testing::Test {
  protected:
    HiveConnectNetworkAccessDTO* m_networkAccess;
    HiveConnectRootNodeDTO* m_rootNode;
    HiveConnectMeshEnableDTO* m_meshEnable;

    static constexpr char gc_ssid[] = "test_ssid";
    static constexpr char gc_password[] = "test_password";
    bool m_isRootNode = true;
    bool m_meshEnabled = true;

    HiveConnectNetworkConfigGetResponse m_expectedResponse;

    void SetUp() override {
        m_networkAccess = new HiveConnectNetworkAccessDTO(gc_ssid, gc_password);
        m_rootNode = new HiveConnectRootNodeDTO(m_isRootNode);
        m_meshEnable = new HiveConnectMeshEnableDTO(m_meshEnabled);

        m_expectedResponse.has_network_access = true;
        m_expectedResponse.has_root_node = true;
        m_expectedResponse.has_mesh_enable = true;
        snprintf(m_expectedResponse.network_access.ssid, NETWORK_SSID_MAX_LENGTH, "%s", gc_ssid);
        snprintf(m_expectedResponse.network_access.password, NETWORK_PASSWORD_MAX_LENGTH, "%s",
                 gc_password);
        m_expectedResponse.root_node.is_root = m_isRootNode;
        m_expectedResponse.mesh_enable.use_mesh = m_meshEnabled;
    }

    void TearDown() override {
        delete m_networkAccess;
        delete m_rootNode;
        delete m_meshEnable;
    }
};

TEST_F(HiveConnectNetworkConfigGetResponseDTOTests, test_constructor_valid_dtos) {
    // Given
    HiveConnectNetworkConfigGetResponseDTO getResponseDto(*m_networkAccess, *m_rootNode,
                                                          *m_meshEnable);

    // Expect
    EXPECT_STREQ(getResponseDto.getSSID(), gc_ssid);
    EXPECT_STREQ(getResponseDto.getPassword(), gc_password);
    EXPECT_EQ(getResponseDto.isRootNode(), m_isRootNode);
    EXPECT_EQ(getResponseDto.isMeshEnabled(), m_meshEnabled);
}

TEST_F(HiveConnectNetworkConfigGetResponseDTOTests, test_contructor_valid_struct) {
    // Given
    HiveConnectNetworkConfigGetResponseDTO getResponseDto(m_expectedResponse);

    // Expect
    EXPECT_STREQ(getResponseDto.getSSID(), gc_ssid);
    EXPECT_STREQ(getResponseDto.getPassword(), gc_password);
    EXPECT_EQ(getResponseDto.isRootNode(), m_isRootNode);
    EXPECT_EQ(getResponseDto.isMeshEnabled(), m_meshEnabled);
}

TEST_F(HiveConnectNetworkConfigGetResponseDTOTests, test_serialize) {
    // Given
    HiveConnectNetworkConfigGetResponseDTO getResponseDto(m_expectedResponse);

    // Then
    HiveConnectNetworkConfigGetResponse getResponse;
    EXPECT_TRUE(getResponseDto.serialize(getResponse));

    // Expect
    ASSERT_TRUE(getResponse.has_network_access);
    ASSERT_TRUE(getResponse.has_root_node);
    ASSERT_TRUE(getResponse.has_mesh_enable);
    EXPECT_STREQ(getResponse.network_access.ssid, gc_ssid);
    EXPECT_STREQ(getResponse.network_access.password, gc_password);
    EXPECT_EQ(getResponse.root_node.is_root, m_isRootNode);
    EXPECT_EQ(getResponse.mesh_enable.use_mesh, m_meshEnabled);
}
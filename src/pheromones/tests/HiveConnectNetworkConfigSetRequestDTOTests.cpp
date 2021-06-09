#include "pheromones/HiveConnectNetworkConfigSetRequestDTO.h"
#include <gtest/gtest.h>

class HiveConnectNetworkConfigSetRequestDTOTestsFixture : public testing::Test {
  protected:
    char m_ssid[NETWORK_SSID_MAX_LENGTH] = "test_ssid";
    char m_password[NETWORK_PASSWORD_MAX_LENGTH] = "test_password";
    bool m_isRootNode = true;
    bool m_useMesh = true;
};

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_constructor_valid_default) {
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;
    ASSERT_FALSE(setRequestDto.getSSID().has_value());
    ASSERT_FALSE(setRequestDto.getPassword().has_value());
    ASSERT_FALSE(setRequestDto.getRootNode().has_value());
    ASSERT_FALSE(setRequestDto.getMeshEnable().has_value());
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture,
       test_constructor_valid_partial_structs_network_access) {
    // Given
    HiveConnectNetworkConfigSetRequest setRequest;
    HiveConnectNetworkAccess networkAccess;
    snprintf(networkAccess.ssid, NETWORK_SSID_MAX_LENGTH, "%s", m_ssid);
    snprintf(networkAccess.password, NETWORK_PASSWORD_MAX_LENGTH, "%s", m_password);
    setRequest.has_network_access = true;
    setRequest.has_root_node = false;
    setRequest.has_mesh_enable = false;
    setRequest.network_access = networkAccess;

    // Then
    HiveConnectNetworkConfigSetRequestDTO setRequestDto(setRequest);

    // Expect
    ASSERT_TRUE(setRequestDto.getSSID().has_value());
    ASSERT_STREQ(setRequestDto.getSSID().value(), m_ssid);
    ASSERT_TRUE(setRequestDto.getPassword().has_value());
    ASSERT_STREQ(setRequestDto.getPassword().value(), m_password);

    ASSERT_FALSE(setRequestDto.getRootNode().has_value());
    ASSERT_FALSE(setRequestDto.getMeshEnable().has_value());
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture,
       test_constructor_valid_partial_structs_root_node) {
    // Given
    HiveConnectNetworkConfigSetRequest setRequest;
    setRequest.has_network_access = false;
    setRequest.root_node.is_root = m_isRootNode;
    setRequest.has_root_node = true;
    setRequest.has_mesh_enable = false;

    // Then
    HiveConnectNetworkConfigSetRequestDTO setRequestDto(setRequest);

    // Expect
    ASSERT_FALSE(setRequestDto.getSSID().has_value());
    ASSERT_FALSE(setRequestDto.getPassword().has_value());

    ASSERT_TRUE(setRequestDto.getRootNode().has_value());
    ASSERT_EQ(setRequestDto.getRootNode().value(), m_isRootNode);

    ASSERT_FALSE(setRequestDto.getMeshEnable().has_value());
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture,
       test_constructor_valid_partial_structs_mesh_enable) {
    // Given
    HiveConnectNetworkConfigSetRequest setRequest;
    setRequest.has_network_access = false;
    setRequest.has_root_node = false;
    setRequest.mesh_enable.use_mesh = m_useMesh;
    setRequest.has_mesh_enable = true;

    // Then
    HiveConnectNetworkConfigSetRequestDTO setRequestDto(setRequest);

    // Expect
    ASSERT_FALSE(setRequestDto.getSSID().has_value());
    ASSERT_FALSE(setRequestDto.getPassword().has_value());
    ASSERT_FALSE(setRequestDto.getRootNode().has_value());

    ASSERT_TRUE(setRequestDto.getMeshEnable().has_value());
    ASSERT_EQ(setRequestDto.getMeshEnable().value(), m_useMesh);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_constructor_valid_complete_structs) {
    // Given
    HiveConnectNetworkConfigSetRequest setRequest;
    HiveConnectNetworkAccess networkAccess;
    snprintf(networkAccess.ssid, NETWORK_SSID_MAX_LENGTH, "%s", m_ssid);
    snprintf(networkAccess.password, NETWORK_PASSWORD_MAX_LENGTH, "%s", m_password);
    setRequest.has_network_access = true;
    setRequest.has_root_node = true;
    setRequest.has_mesh_enable = true;
    setRequest.network_access = networkAccess;
    setRequest.root_node.is_root = m_isRootNode;
    setRequest.mesh_enable.use_mesh = m_useMesh;

    // Then
    HiveConnectNetworkConfigSetRequestDTO setRequestDto(setRequest);

    // Expect
    ASSERT_TRUE(setRequestDto.getSSID().has_value());
    ASSERT_STREQ(setRequestDto.getSSID().value(), m_ssid);
    ASSERT_STREQ(setRequestDto.getPassword().value(), m_password);
    ASSERT_TRUE(setRequestDto.getPassword().has_value());

    ASSERT_TRUE(setRequestDto.getRootNode().has_value());
    ASSERT_EQ(setRequestDto.getRootNode().value(), m_isRootNode);

    ASSERT_TRUE(setRequestDto.getMeshEnable().has_value());
    ASSERT_EQ(setRequestDto.getMeshEnable().value(), m_useMesh);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_set_network_access) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.setSSIDAndPassword(m_ssid, m_password);

    // Expect
    ASSERT_TRUE(setRequestDto.getSSID().has_value());
    ASSERT_STREQ(setRequestDto.getSSID().value(), m_ssid);
    ASSERT_TRUE(setRequestDto.getPassword().has_value());
    ASSERT_STREQ(setRequestDto.getPassword().value(), m_password);

    ASSERT_FALSE(setRequestDto.getRootNode().has_value());
    ASSERT_FALSE(setRequestDto.getMeshEnable().has_value());
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_set_root_node) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.setRootNode(m_isRootNode);

    // Expect
    ASSERT_FALSE(setRequestDto.getSSID().has_value());
    ASSERT_FALSE(setRequestDto.getPassword().has_value());

    ASSERT_TRUE(setRequestDto.getRootNode().has_value());
    ASSERT_EQ(setRequestDto.getRootNode().value(), m_isRootNode);

    ASSERT_FALSE(setRequestDto.getMeshEnable().has_value());
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_set_mesh_enable) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.enableMesh(m_useMesh);

    // Expect
    ASSERT_FALSE(setRequestDto.getSSID().has_value());
    ASSERT_FALSE(setRequestDto.getPassword().has_value());

    ASSERT_FALSE(setRequestDto.getRootNode().has_value());

    ASSERT_TRUE(setRequestDto.getMeshEnable().has_value());
    ASSERT_EQ(setRequestDto.getMeshEnable().value(), m_isRootNode);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_serialize_partial_network_access) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.setSSIDAndPassword(m_ssid, m_password);

    // Expect
    HiveConnectNetworkConfigSetRequest setRequest;
    ASSERT_TRUE(setRequestDto.serialize(setRequest));
    ASSERT_TRUE(setRequest.has_network_access);
    ASSERT_STREQ(setRequestDto.getSSID().value(), setRequest.network_access.ssid);
    ASSERT_STREQ(setRequestDto.getPassword().value(), setRequest.network_access.password);

    ASSERT_FALSE(setRequest.has_root_node);
    ASSERT_FALSE(setRequest.has_mesh_enable);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_serialize_partial_root_node) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.setRootNode(m_isRootNode);

    // Expect
    HiveConnectNetworkConfigSetRequest setRequest;
    ASSERT_TRUE(setRequestDto.serialize(setRequest));
    ASSERT_FALSE(setRequest.has_network_access);

    ASSERT_TRUE(setRequest.has_root_node);
    ASSERT_EQ(setRequest.root_node.is_root, m_isRootNode);
    ASSERT_FALSE(setRequest.has_mesh_enable);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_serialize_partial_mesh_enable) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.enableMesh(m_useMesh);

    // Expect
    HiveConnectNetworkConfigSetRequest setRequest;
    ASSERT_TRUE(setRequestDto.serialize(setRequest));
    ASSERT_FALSE(setRequest.has_network_access);

    ASSERT_FALSE(setRequest.has_root_node);
    ASSERT_TRUE(setRequest.has_mesh_enable);
    ASSERT_EQ(setRequest.mesh_enable.use_mesh, m_useMesh);
}

TEST_F(HiveConnectNetworkConfigSetRequestDTOTestsFixture, test_serialize_complete) {
    // Given
    HiveConnectNetworkConfigSetRequestDTO setRequestDto;

    // Then
    setRequestDto.setSSIDAndPassword(m_ssid, m_password);
    setRequestDto.setRootNode(m_isRootNode);
    setRequestDto.enableMesh(m_useMesh);

    // Expect
    HiveConnectNetworkConfigSetRequest setRequest;
    ASSERT_TRUE(setRequestDto.serialize(setRequest));
    ASSERT_TRUE(setRequest.has_network_access);
    ASSERT_STREQ(setRequestDto.getSSID().value(), setRequest.network_access.ssid);
    ASSERT_STREQ(setRequestDto.getPassword().value(), setRequest.network_access.password);

    ASSERT_TRUE(setRequest.has_root_node);
    ASSERT_EQ(setRequest.root_node.is_root, m_isRootNode);
    ASSERT_TRUE(setRequest.has_mesh_enable);
    ASSERT_EQ(setRequest.mesh_enable.use_mesh, m_useMesh);
}
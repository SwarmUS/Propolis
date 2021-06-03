#include <gtest/gtest.h>
#include "pheromones/HiveConnectNetworkAccessDTO.h"

class HiveConnectNetworkAccessDTOTestFixture : public testing::Test {};

TEST_F(HiveConnectNetworkAccessDTOTestFixture, test_constructor_valid_values) {
    HiveConnectNetworkAccessDTO networkAccessDto("test_ssid", "test_password");

    ASSERT_STREQ(networkAccessDto.getSSID(), "test_ssid");
    ASSERT_STREQ(networkAccessDto.getPassword(), "test_password");
}


TEST_F(HiveConnectNetworkAccessDTOTestFixture, test_constructor_valid_struct) {
    HiveConnectNetworkAccess networkAccess;
    snprintf(networkAccess.ssid, NETWORK_SSID_MAX_LENGTH, "%s", "test_ssid");
    snprintf(networkAccess.password, NETWORK_PASSWORD_MAX_LENGTH, "%s", "test_password");
    HiveConnectNetworkAccessDTO networkAccessDto(networkAccess);

    ASSERT_STREQ(networkAccessDto.getSSID(), "test_ssid");
    ASSERT_STREQ(networkAccessDto.getPassword(), "test_password");
}

TEST_F(HiveConnectNetworkAccessDTOTestFixture, test_constructor_null_pointer) {
    HiveConnectNetworkAccessDTO networkAccessDto(nullptr, nullptr);

    ASSERT_STREQ(networkAccessDto.getSSID(), "(null)");
    ASSERT_STREQ(networkAccessDto.getPassword(), "(null)");
}


TEST_F(HiveConnectNetworkAccessDTOTestFixture, test_constructor_null_overflow) {
    char overflowingSSID[] = "abcdefabcdefabcdefabcdefabcdefa_overflow";
    char ssid[NETWORK_SSID_MAX_LENGTH] = "abcdefabcdefabcdefabcdefabcdefa";
    char overFlowingPassword[] = "abcdefabcdefabcdefabcdefabcdefa_abcdefabcdefabcdefabcdefabcdef_overflow";
    char password[NETWORK_PASSWORD_MAX_LENGTH] = "abcdefabcdefabcdefabcdefabcdefa_abcdefabcdefabcdefabcdefabcdef";
    HiveConnectNetworkAccessDTO networkAccessDto(overflowingSSID, overFlowingPassword);

    ASSERT_STREQ(networkAccessDto.getSSID(), ssid);
    ASSERT_STREQ(networkAccessDto.getPassword(), password);
}



TEST_F(HiveConnectNetworkAccessDTOTestFixture, change_ssid_and_password) {
    HiveConnectNetworkAccessDTO networkAccessDto(nullptr, nullptr);

    networkAccessDto.setSSID("test_ssid");
    networkAccessDto.setPassword("test_password");

    ASSERT_STREQ(networkAccessDto.getSSID(), "test_ssid");
    ASSERT_STREQ(networkAccessDto.getPassword(), "test_password");
}



TEST_F(HiveConnectNetworkAccessDTOTestFixture, serialize) {
    HiveConnectNetworkAccessDTO networkAccessDto("test_ssid", "test_password");

    ASSERT_STREQ(networkAccessDto.getSSID(), "test_ssid");
    ASSERT_STREQ(networkAccessDto.getPassword(), "test_password");

    HiveConnectNetworkAccess networkAccess;
    ASSERT_TRUE(networkAccessDto.serialize(networkAccess));
    ASSERT_STREQ(networkAccessDto.getSSID(), networkAccess.ssid);
    ASSERT_STREQ(networkAccessDto.getPassword(), networkAccess.password);
}

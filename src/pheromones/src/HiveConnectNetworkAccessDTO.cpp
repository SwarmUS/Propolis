#include "HiveConnectNetworkAccessDTO.h"
#include <cstdio>

HiveConnectNetworkAccessDTO::HiveConnectNetworkAccessDTO(const char* ssid, const char* password) {
    setSSID(ssid);
    setPassword(password);
}

HiveConnectNetworkAccessDTO::HiveConnectNetworkAccessDTO(
    const HiveConnectNetworkAccess& hiveConnectNetworkAccessDto) {
    setSSID(hiveConnectNetworkAccessDto.ssid);
    setPassword(hiveConnectNetworkAccessDto.password);
}

const char* HiveConnectNetworkAccessDTO::getSSID() const { return m_ssid; }

const char* HiveConnectNetworkAccessDTO::getPassword() const { return m_password; }

void HiveConnectNetworkAccessDTO::setSSID(const char* ssid) {
    snprintf(m_ssid, NETWORK_SSID_MAX_LENGTH, "%s", ssid);
}

void HiveConnectNetworkAccessDTO::setPassword(const char* password) {
    snprintf(m_password, NETWORK_PASSWORD_MAX_LENGTH, "%s", password);
}

bool HiveConnectNetworkAccessDTO::serialize(HiveConnectNetworkAccess& networkAccess) const {
    snprintf(networkAccess.ssid, NETWORK_SSID_MAX_LENGTH, "%s", m_ssid);
    snprintf(networkAccess.password, NETWORK_PASSWORD_MAX_LENGTH, "%s", m_password);
    return true;
}
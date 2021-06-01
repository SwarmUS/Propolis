#include "HiveConnectNetworkConfigSetRequestDTO.h"

HiveConnectNetworkConfigSetRequestDTO::HiveConnectNetworkConfigSetRequestDTO() {
    m_networkAccess = std::nullopt;
    m_rootNode = std::nullopt;
    m_meshEnable = std::nullopt;
}

void HiveConnectNetworkConfigSetRequestDTO::setSSIDAndPassword(const char* ssid, const char* password) {
    m_networkAccess.emplace(ssid, password);
}

void HiveConnectNetworkConfigSetRequestDTO::setRootNode(bool isRootNode) {
    m_rootNode.emplace(isRootNode);
}

void HiveConnectNetworkConfigSetRequestDTO::enableMesh(bool enable) {
    m_meshEnable.emplace(enable);
}

bool HiveConnectNetworkConfigSetRequestDTO::serialize(HiveConnectNetworkConfigSetRequest& setRequest) {
    bool ret = false;
    setRequest.has_network_access = m_networkAccess.has_value();
    setRequest.has_root_node = m_rootNode.has_value();
    setRequest.has_mesh_enable = m_meshEnable.has_value();

    if (setRequest.has_network_access) {
        ret = m_networkAccess.value().serialize(setRequest.network_access);
    }

    if (setRequest.has_root_node && ret) {
        ret = m_rootNode.value().serialize(setRequest.root_node);
    }

    if (setRequest.has_mesh_enable && ret) {
        ret = m_meshEnable.value().serialize(setRequest.mesh_enable);
    }

    return ret;
}
#include "HiveConnectNetworkConfigSetRequestDTO.h"

HiveConnectNetworkConfigSetRequestDTO::HiveConnectNetworkConfigSetRequestDTO() {
    m_networkAccess = std::nullopt;
    m_rootNode = std::nullopt;
    m_meshEnable = std::nullopt;
}

HiveConnectNetworkConfigSetRequestDTO::HiveConnectNetworkConfigSetRequestDTO(
    const HiveConnectNetworkConfigSetRequest& setRequest) {
    if (setRequest.has_network_access) {
        setSSIDAndPassword(setRequest.network_access.ssid, setRequest.network_access.password);
    }
    if (setRequest.has_root_node) {
        setRootNode(setRequest.root_node.is_root);
    }
    if (setRequest.has_mesh_enable) {
        enableMesh(setRequest.mesh_enable.use_mesh);
    }
}

void HiveConnectNetworkConfigSetRequestDTO::setSSIDAndPassword(const char* ssid,
                                                               const char* password) {
    m_networkAccess.emplace(ssid, password);
}

void HiveConnectNetworkConfigSetRequestDTO::setRootNode(bool isRootNode) {
    m_rootNode.emplace(isRootNode);
}

void HiveConnectNetworkConfigSetRequestDTO::enableMesh(bool enable) {
    m_meshEnable.emplace(enable);
}

std::optional<const char*> HiveConnectNetworkConfigSetRequestDTO::getSSID() const {
    if (m_networkAccess.has_value()) {
        return m_networkAccess.value().getSSID();
    }
    return {};
}

std::optional<const char*> HiveConnectNetworkConfigSetRequestDTO::getPassword() const {
    if (m_networkAccess.has_value()) {
        return m_networkAccess.value().getPassword();
    }
    return {};
}

std::optional<bool> HiveConnectNetworkConfigSetRequestDTO::getRootNode() const {
    if (m_rootNode.has_value()) {
        return m_rootNode.value().isRootNode();
    }
    return {};
}

std::optional<bool> HiveConnectNetworkConfigSetRequestDTO::getMeshEnable() const {
    if (m_meshEnable.has_value()) {
        return m_meshEnable.value().isMeshEnabled();
    }
    return {};
}

bool HiveConnectNetworkConfigSetRequestDTO::serialize(
    HiveConnectNetworkConfigSetRequest& setRequest) {
    bool ret = true;
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
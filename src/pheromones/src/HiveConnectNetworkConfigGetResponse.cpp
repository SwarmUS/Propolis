#include "HiveConnectNetowrkConfigGetResponseDTO.h"

HiveConnectNetworkConfigGetResponseDTO::HiveConnectNetworkConfigGetResponseDTO(
    HiveConnectNetworkAccessDTO networkAccess,
    HiveConnectRootNodeDTO rootNode,
    HiveConnectMeshEnableDTO meshEnable) :
    m_networkAccess(networkAccess.getSSID(), networkAccess.getPassword()),
    m_rootNode(rootNode.isRootNode()),
    m_meshEnable(meshEnable.isMeshEnabled()) {}

HiveConnectNetworkConfigGetResponseDTO::HiveConnectNetworkConfigGetResponseDTO(
    const HiveConnectNetworkConfigGetResponse& getResponse) :
    m_networkAccess(getResponse.network_access),
    m_rootNode(getResponse.root_node),
    m_meshEnable(getResponse.mesh_enable) {}

void HiveConnectNetworkConfigGetResponseDTO::setSSIDAndPassword(const char* ssid,
                                                                const char* password) {
    m_networkAccess.setSSID(ssid);
    m_networkAccess.setPassword(password);
}

void HiveConnectNetworkConfigGetResponseDTO::setRootNode(bool rootNode) {
    m_rootNode.setRootNode(rootNode);
}

void HiveConnectNetworkConfigGetResponseDTO::setMeshEnable(bool meshEnable) {
    m_meshEnable.setMeshEnable(meshEnable);
}

const char* HiveConnectNetworkConfigGetResponseDTO::getSSID() const {
    return m_networkAccess.getSSID();
}

const char* HiveConnectNetworkConfigGetResponseDTO::getPassword() const {
    return m_networkAccess.getPassword();
}

bool HiveConnectNetworkConfigGetResponseDTO::isRootNode() const { return m_rootNode.isRootNode(); }

bool HiveConnectNetworkConfigGetResponseDTO::isMeshEnabled() const {
    return m_meshEnable.isMeshEnabled();
}

bool HiveConnectNetworkConfigGetResponseDTO::serialize(
    HiveConnectNetworkConfigGetResponse& getResponse) const {
    getResponse.has_network_access = true;
    getResponse.has_root_node = true;
    getResponse.has_mesh_enable = true;

    return m_networkAccess.serialize(getResponse.network_access) &&
           m_rootNode.serialize(getResponse.root_node) &&
           m_meshEnable.serialize(getResponse.mesh_enable);
}
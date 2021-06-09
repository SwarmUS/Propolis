#include "HiveConnectRootNodeDTO.h"

HiveConnectRootNodeDTO::HiveConnectRootNodeDTO(bool isRootNode) { m_isRoot = isRootNode; }

HiveConnectRootNodeDTO::HiveConnectRootNodeDTO(const HiveConnectRootNode& hiveConnectRootNodeDto) {
    m_isRoot = hiveConnectRootNodeDto.is_root;
}

bool HiveConnectRootNodeDTO::isRootNode() const { return m_isRoot; }

void HiveConnectRootNodeDTO::setRootNode(bool isRoot) { m_isRoot = isRoot; }

bool HiveConnectRootNodeDTO::serialize(HiveConnectRootNode& rootNode) const {
    rootNode.is_root = m_isRoot;
    return true;
}
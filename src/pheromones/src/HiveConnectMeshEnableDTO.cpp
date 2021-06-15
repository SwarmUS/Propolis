#include "HiveConnectMeshEnableDTO.h"

HiveConnectMeshEnableDTO::HiveConnectMeshEnableDTO(bool meshEnable) { m_meshEnable = meshEnable; }

HiveConnectMeshEnableDTO::HiveConnectMeshEnableDTO(
    const HiveConnectMeshEnable& hiveConnectMeshEnableDto) {
    m_meshEnable = hiveConnectMeshEnableDto.use_mesh;
}

bool HiveConnectMeshEnableDTO::isMeshEnabled() const { return m_meshEnable; }

void HiveConnectMeshEnableDTO::setMeshEnable(bool meshEnable) { m_meshEnable = meshEnable; }

bool HiveConnectMeshEnableDTO::serialize(HiveConnectMeshEnable& meshEnable) const {
    meshEnable.use_mesh = m_meshEnable;
    return true;
}
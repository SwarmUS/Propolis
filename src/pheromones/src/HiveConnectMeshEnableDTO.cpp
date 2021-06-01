#include "HiveConnectMeshEnableDTO.h"

HiveConnectMeshEnableDTO::HiveConnectMeshEnableDTO(bool meshEnable) {
    m_meshEnable = meshEnable;
}

HiveConnectMeshEnableDTO::HiveConnectMeshEnableDTO(const HiveConnectMeshEnableDTO& hiveConnectMeshEnableDto) {
    m_meshEnable = hiveConnectMeshEnableDto.m_meshEnable;
}

bool HiveConnectMeshEnableDTO::isMeshEnabled() const {return m_meshEnable;}

void HiveConnectMeshEnableDTO::setMeshEnable(bool meshEnable) {m_meshEnable = meshEnable;}

bool HiveConnectMeshEnableDTO::serialize(HiveConnectMeshEnable& meshEnable) {
    meshEnable.use_mesh = m_meshEnable;
    return true;
}
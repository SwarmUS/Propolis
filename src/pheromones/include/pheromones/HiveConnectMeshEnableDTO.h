#ifndef PROPOLIS_HIVECONNECTMESHENABLEDTO_H
#define PROPOLIS_HIVECONNECTMESHENABLEDTO_H

#include "message.pb.h"

class HiveConnectMeshEnableDTO {
  public:
    HiveConnectMeshEnableDTO(bool meshEnable);
    HiveConnectMeshEnableDTO(const HiveConnectMeshEnable& hiveConnectMeshEnableDto);

    /**
     * @return the flag to enable mesh
     */
    bool isMeshEnabled() const;
    /**
     * @brief set the flag to enable/disable mesh
     * @param [in] meshEnable the flag value
     */
    void setMeshEnable(bool meshEnable);

    bool serialize(HiveConnectMeshEnable& meshEnable) const;

  private:
    bool m_meshEnable;
};

#endif // PROPOLIS_HIVECONNECTMESHENABLEDTO_H

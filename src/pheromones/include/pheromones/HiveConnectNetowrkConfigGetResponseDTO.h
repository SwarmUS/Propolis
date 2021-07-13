#ifndef PROPOLIS_HIVECONNECTNETOWRKCONFIGGETRESPONSEDTO_H
#define PROPOLIS_HIVECONNECTNETOWRKCONFIGGETRESPONSEDTO_H
#include "message.pb.h"

#include "HiveConnectMeshEnableDTO.h"
#include "HiveConnectNetworkAccessDTO.h"
#include "HiveConnectRootNodeDTO.h"

class HiveConnectNetworkConfigGetResponseDTO {
  public:
    HiveConnectNetworkConfigGetResponseDTO(HiveConnectNetworkAccessDTO networkAccess,
                                           HiveConnectRootNodeDTO rootNode,
                                           HiveConnectMeshEnableDTO meshEnable);
    HiveConnectNetworkConfigGetResponseDTO(const HiveConnectNetworkConfigGetResponse& getResponse);

    void setSSIDAndPassword(const char* ssid, const char* password);
    void setRootNode(bool rootNode);
    void setMeshEnable(bool meshEnable);

    const char* getSSID() const;
    const char* getPassword() const;
    bool isRootNode() const;
    bool isMeshEnabled() const;

    bool serialize(HiveConnectNetworkConfigGetResponse& getResponse) const;

  private:
    HiveConnectNetworkAccessDTO m_networkAccess;
    HiveConnectRootNodeDTO m_rootNode;
    HiveConnectMeshEnableDTO m_meshEnable;
};
#endif // PROPOLIS_HIVECONNECTNETOWRKCONFIGGETRESPONSEDTO_H

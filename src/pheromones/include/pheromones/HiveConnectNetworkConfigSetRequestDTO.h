#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H

#include "message.pb.h"
#include "HiveConnectNetworkAccessDTO.h"
#include "HiveConnectRootNodeDTO.h"
#include "HiveConnectMeshEnableDTO.h"
#include <optional>

class HiveConnectNetworkConfigSetRequestDTO {
  public:
    HiveConnectNetworkConfigSetRequestDTO();

    void setSSIDAndPassword(const char* ssid, const char* password);
    void setRootNode(bool isRootNode);
    void enableMesh(bool enable);

    bool serialize(HiveConnectNetworkConfigSetRequest& setRequest);

  private:
    std::optional<HiveConnectNetworkAccessDTO> m_networkAccess;
    std::optional<HiveConnectRootNodeDTO> m_rootNode;
    std::optional<HiveConnectMeshEnableDTO> m_meshEnable;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H

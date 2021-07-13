#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H

#include "HiveConnectMeshEnableDTO.h"
#include "HiveConnectNetworkAccessDTO.h"
#include "HiveConnectRootNodeDTO.h"
#include "message.pb.h"
#include <optional>

class HiveConnectNetworkConfigSetRequestDTO {
  public:
    HiveConnectNetworkConfigSetRequestDTO() = default;
    HiveConnectNetworkConfigSetRequestDTO(const HiveConnectNetworkConfigSetRequest& setRequest);

    void setSSIDAndPassword(const char* ssid, const char* password);
    void setRootNode(bool isRootNode);
    void enableMesh(bool enable);

    std::optional<const char*> getSSID() const;
    std::optional<const char*> getPassword() const;
    std::optional<bool> getRootNode() const;
    std::optional<bool> getMeshEnable() const;

    bool serialize(HiveConnectNetworkConfigSetRequest& setRequest) const ;

  private:
    // All optionals since a setRequest could contain only a part of the settings to change
    std::optional<HiveConnectNetworkAccessDTO> m_networkAccess;
    std::optional<HiveConnectRootNodeDTO> m_rootNode;
    std::optional<HiveConnectMeshEnableDTO> m_meshEnable;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGSETREQUESTDTO_H

#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGGETREQUESTDTO_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGGETREQUESTDTO_H

#include "message.pb.h"

class HiveConnectNetworkConfigGetRequestDTO {
  public:
    HiveConnectNetworkConfigGetRequestDTO() = default;
    HiveConnectNetworkConfigGetRequestDTO(const HiveConnectNetworkConfigGetRequest& getRequest);

    bool serialize(HiveConnectNetworkConfigGetRequest& getRequest) const;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGGETREQUESTDTO_H

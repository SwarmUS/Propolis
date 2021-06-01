#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSE_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSE_H

#include "message.pb.h"
#include "GenericResponseDTO.h"

class HiveConnectNetworkConfigSetResponseDTO {
  public:
    HiveConnectNetworkConfigSetResponseDTO(const HiveConnectNetworkConfigSetResponse& setResponse);
    HiveConnectNetworkConfigSetResponseDTO(const GenericResponse genericResponse);

    GenericResponseStatusDTO getResponse() const;

    bool serialize(HiveConnectNetworkConfigSetResponse& setResponse);
  private:
    GenericResponseDTO m_genericResponse;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSE_H

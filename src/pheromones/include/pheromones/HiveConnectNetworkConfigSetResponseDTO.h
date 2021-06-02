#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H

#include "message.pb.h"
#include "GenericResponseDTO.h"

class HiveConnectNetworkConfigSetResponseDTO {
  public:
    HiveConnectNetworkConfigSetResponseDTO(const HiveConnectNetworkConfigSetResponse& setResponse);
    HiveConnectNetworkConfigSetResponseDTO(const GenericResponse genericResponse);

    GenericResponseStatusDTO getResponse() const;

    bool serialize(HiveConnectNetworkConfigSetResponse& setResponse) const ;
  private:
    GenericResponseDTO m_genericResponse;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H

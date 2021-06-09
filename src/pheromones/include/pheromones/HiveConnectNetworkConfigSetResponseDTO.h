#ifndef PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H
#define PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H

#include "GenericResponseDTO.h"
#include "message.pb.h"

class HiveConnectNetworkConfigSetResponseDTO {
  public:
    HiveConnectNetworkConfigSetResponseDTO(const HiveConnectNetworkConfigSetResponse& setResponse);
    HiveConnectNetworkConfigSetResponseDTO(const GenericResponse& genericResponse);
    HiveConnectNetworkConfigSetResponseDTO(const GenericResponseDTO& genericResponseDto);

    GenericResponseStatusDTO getResponse() const;

    bool serialize(HiveConnectNetworkConfigSetResponse& setResponse) const;

  private:
    GenericResponseDTO m_genericResponse;
};
#endif // PROPOLIS_HIVECONNECTNETWORKCONFIGSETRESPONSEDTO_H

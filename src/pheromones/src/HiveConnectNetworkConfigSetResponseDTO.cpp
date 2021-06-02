#include "HiveConnectNetworkConfigSetResponseDTO.h"

HiveConnectNetworkConfigSetResponseDTO::HiveConnectNetworkConfigSetResponseDTO(const HiveConnectNetworkConfigSetResponse& setResponse) :
    m_genericResponse(setResponse.response) {}

HiveConnectNetworkConfigSetResponseDTO::HiveConnectNetworkConfigSetResponseDTO(const GenericResponse genericResponse) :
    m_genericResponse(genericResponse) {}

GenericResponseStatusDTO HiveConnectNetworkConfigSetResponseDTO::getResponse() const {
    return m_genericResponse.getStatus();
}

bool HiveConnectNetworkConfigSetResponseDTO::serialize(HiveConnectNetworkConfigSetResponse& setResponse) const {
    setResponse.has_response = true;
    m_genericResponse.serialize(setResponse.response);
    return true;
}
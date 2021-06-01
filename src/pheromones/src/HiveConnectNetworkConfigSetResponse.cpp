#include "HiveConnectNetworkConfigSetResponse.h"

HiveConnectNetworkConfigSetResponseDTO::HiveConnectNetworkConfigSetResponseDTO(const HiveConnectNetworkConfigSetResponse& setResponse) :
    m_genericResponse(setResponse.response) {}

HiveConnectNetworkConfigSetResponseDTO::HiveConnectNetworkConfigSetResponseDTO(const GenericResponse genericResponse) :
    m_genericResponse(genericResponse) {}

GenericResponseStatusDTO HiveConnectNetworkConfigSetResponseDTO::getResponse() const {
    return m_genericResponse.getStatus();
}
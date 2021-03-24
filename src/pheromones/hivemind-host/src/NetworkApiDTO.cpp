#include "NetworkApiDTO.h"

NetworkApiDTO::NetworkApiDTO() { m_apiCall = std::monostate();}

NetworkApiDTO::NetworkApiDTO(const NetworkAPI& networkApi) {
    switch (networkApi.which_call) {
    case NetworkAPI_ipDiscovery_tag:
        m_apiCall = IPDiscoveryDTO(networkApi.call.ipDiscovery);
        break;
    default:
        m_apiCall = std::monostate();
    }
}

NetworkApiDTO::NetworkApiDTO(const IPDiscoveryDTO& ipDiscovery) {
    m_apiCall = ipDiscovery;
}

const NetworkApiDTOType & NetworkApiDTO::getApiCall() const {
    return m_apiCall;
}

void NetworkApiDTO::setAPICall(const NetworkApiDTOType& apiCall) {
    m_apiCall = apiCall;
}

bool NetworkApiDTO::serialize(NetworkAPI& networkApiCall) const {
    if (const auto* ipRequest = std::get_if<IPDiscoveryDTO>(&m_apiCall)) {
        networkApiCall.which_call = NetworkAPI_ipDiscovery_tag;
        return ipRequest->serialize(networkApiCall.call.ipDiscovery);
    }
    return false;
}
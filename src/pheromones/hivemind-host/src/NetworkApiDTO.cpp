#include "NetworkApiDTO.h"

NetworkApiDTO::NetworkApiDTO() { m_apiCall = std::monostate();}

NetworkApiDTO::NetworkApiDTO(const NetworkAPI& networkApi) {
    switch (networkApi.which_call) {
    case NetworkAPI_ipRequest_tag:
        m_apiCall = IPDiscoveryDTO(networkApi.call.ipRequest);
        break;
    default:
        m_apiCall = std::monostate();
    }
}

NetworkApiDTO::NetworkApiDTO(const IPDiscoveryDTO& ipRequest) {
    m_apiCall = ipRequest;
}

const NetworkApiDTOType & NetworkApiDTO::getApiCall() const {
    return m_apiCall;
}

void NetworkApiDTO::setAPICall(const NetworkApiDTOType& apiCall) {
    m_apiCall = apiCall;
}

bool NetworkApiDTO::serialize(NetworkAPI& networkApiCall) {
    if (const auto* ipRequest = std::get_if<IPDiscoveryDTO>(&m_apiCall)) {
        networkApiCall.which_call = NetworkAPI_ipRequest_tag;
        return ipRequest->serialize(networkApiCall.call.ipRequest);
    }
    return false;
}
#include "HiveMindApiRequestDTO.h"

HiveMindApiRequestDTO::HiveMindApiRequestDTO(const HiveMindApiRequest& request) {
    switch (request.which_request) {
    case HiveMindApiRequest_id_tag:
        m_request = IdRequestDTO(request.request.id);
        break;
    default:
        m_request = std::monostate();
    }
}

HiveMindApiRequestDTO::HiveMindApiRequestDTO(const IdRequestDTO& request) : m_request(request) {}

const std::variant<std::monostate, IdRequestDTO>& HiveMindApiRequestDTO::getRequest() const {
    return m_request;
}

void HiveMindApiRequestDTO::setRequest(const std::variant<std::monostate, IdRequestDTO>& request) {
    m_request = request;
}

bool HiveMindApiRequestDTO::serialize(HiveMindApiRequest& request) const {
    if (const auto* idReq = std::get_if<IdRequestDTO>(&m_request)) {
        request.which_request = HiveMindApiRequest_id_tag;
        return idReq->serialize(request.request.id);
    }
    return false;
}

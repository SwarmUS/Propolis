#include "HiveMindApiRequestDTO.h"

HiveMindApiRequestDTO::HiveMindApiRequestDTO(const HiveMindApiRequest& request) :
    m_source(targetToDTO(request.source)) {
    switch (request.which_request) {
    case HiveMindApiRequest_id_tag:
        m_request = IdRequestDTO(request.request.id);
        break;
    default:
        m_request = std::monostate();
    }
}

HiveMindApiRequestDTO::HiveMindApiRequestDTO(UserCallTargetDTO source,
                                             const IdRequestDTO& request) :
    m_source(source), m_request(request) {}

UserCallTargetDTO HiveMindApiRequestDTO::getSource() const { return m_source; }

const std::variant<std::monostate, IdRequestDTO>& HiveMindApiRequestDTO::getRequest() const {
    return m_request;
}

void HiveMindApiRequestDTO::setSource(UserCallTargetDTO source) { m_source = source; }

void HiveMindApiRequestDTO::setRequest(const std::variant<std::monostate, IdRequestDTO>& request) {
    m_request = request;
}

bool HiveMindApiRequestDTO::serialize(HiveMindApiRequest& request) const {
    request.source = dtoToTarget(m_source);
    if (const auto* idReq = std::get_if<IdRequestDTO>(&m_request)) {
        request.which_request = HiveMindApiRequest_id_tag;
        return idReq->serialize(request.request.id);
    }
    return false;
}

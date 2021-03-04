#include "SwarmApiRequestDTO.h"

SwarmApiRequestDTO::SwarmApiRequestDTO(const SwarmApiRequest& request) {
    switch (request.which_request) {
    case SwarmApiRequest_id_tag:
        m_request = IdRequestDTO(request.request.id);
        break;
    default:
        m_request = std::monostate();
    }
}

SwarmApiRequestDTO::SwarmApiRequestDTO(const IdRequestDTO& request) : m_request(request) {}

const std::variant<std::monostate, IdRequestDTO>& SwarmApiRequestDTO::getRequest() const {
    return m_request;
}

void SwarmApiRequestDTO::setRequest(const std::variant<std::monostate, IdRequestDTO>& request) {
    m_request = request;
}

bool SwarmApiRequestDTO::serialize(SwarmApiRequest& request) const {
    if (const auto* idReq = std::get_if<IdRequestDTO>(&m_request)) {
        request.which_request = SwarmApiRequest_id_tag;
        return idReq->serialize(request.request.id);
    }
    return false;
}

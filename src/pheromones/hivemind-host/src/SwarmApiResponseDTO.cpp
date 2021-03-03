#include "SwarmApiResponseDTO.h"

SwarmApiResponseDTO::SwarmApiResponseDTO(const SwarmApiResponse& response) {
    switch (response.which_response) {
    case SwarmApiResponse_id_tag:
        m_response = IdResponseDTO(response.response.id);
        break;
    default:
        m_response = std::monostate();
    }
}

SwarmApiResponseDTO::SwarmApiResponseDTO(const IdResponseDTO& response) : m_response(response) {}

const std::variant<std::monostate, IdResponseDTO>& SwarmApiResponseDTO::getResponse() const {
    return m_response;
}

void SwarmApiResponseDTO::setResponse(const std::variant<std::monostate, IdResponseDTO>& response) {
    m_response = response;
}

bool SwarmApiResponseDTO::serialize(SwarmApiResponse& response) const {
    if (const auto* idReq = std::get_if<IdResponseDTO>(&m_response)) {
        response.which_response = SwarmApiResponse_id_tag;
        return idReq->serialize(response.response.id);
    }
    return false;
}

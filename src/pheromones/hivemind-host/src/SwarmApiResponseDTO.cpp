#include "SwarmApiResponseDTO.h"

SwarmApiResponseDTO::SwarmApiResponseDTO(const SwarmApiResponse& response) {
    switch (response.which_response) {
    case SwarmApiResponse_generic_tag:
        m_response = GenericResponseDTO(response.response.generic);
        break;
    case SwarmApiResponse_id_tag:
        m_response = IdResponseDTO(response.response.id);
        break;
    default:
        m_response = std::monostate();
    }
}

SwarmApiResponseDTO::SwarmApiResponseDTO(const GenericResponseDTO& response) :
    m_response(response) {}

SwarmApiResponseDTO::SwarmApiResponseDTO(const IdResponseDTO& response) : m_response(response) {}

const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& SwarmApiResponseDTO::
    getResponse() const {
    return m_response;
}

void SwarmApiResponseDTO::setResponse(
    const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& response) {
    m_response = response;
}

bool SwarmApiResponseDTO::serialize(SwarmApiResponse& response) const {
    if (const auto* genericResp = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_response = SwarmApiResponse_generic_tag;
        return genericResp->serialize(response.response.generic);
    }
    if (const auto* idResp = std::get_if<IdResponseDTO>(&m_response)) {
        response.which_response = SwarmApiResponse_id_tag;
        return idResp->serialize(response.response.id);
    }
    return false;
}

#include "HiveMindApiResponseDTO.h"

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const HiveMindApiResponse& response) {
    switch (response.which_response) {
    case HiveMindApiResponse_id_tag:
        m_response = IdResponseDTO(response.response.id);
        break;
    default:
        m_response = std::monostate();
    }
}

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const IdResponseDTO& response) :
    m_response(response) {}

const std::variant<std::monostate, IdResponseDTO>& HiveMindApiResponseDTO::getResponse() const {
    return m_response;
}

void HiveMindApiResponseDTO::setResponse(
    const std::variant<std::monostate, IdResponseDTO>& response) {
    m_response = response;
}

bool HiveMindApiResponseDTO::serialize(HiveMindApiResponse& response) const {
    if (const auto* idReq = std::get_if<IdResponseDTO>(&m_response)) {
        response.which_response = HiveMindApiResponse_id_tag;
        return idReq->serialize(response.response.id);
    }
    return false;
}

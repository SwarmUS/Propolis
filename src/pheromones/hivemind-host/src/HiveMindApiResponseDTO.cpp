#include "HiveMindApiResponseDTO.h"

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const HiveMindApiResponse& response) {
    switch (response.which_response) {
    case HiveMindApiResponse_generic_tag:
        m_response = GenericResponseDTO(response.response.generic);
        break;
    case HiveMindApiResponse_id_tag:
        m_response = IdResponseDTO(response.response.id);
        break;
    default:
        m_response = std::monostate();
    }
}

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const GenericResponseDTO& response) :
    m_response(response) {}

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const IdResponseDTO& response) :
    m_response(response) {}

const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& HiveMindApiResponseDTO::
    getResponse() const {
    return m_response;
}

void HiveMindApiResponseDTO::setResponse(
    const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& response) {
    m_response = response;
}

bool HiveMindApiResponseDTO::serialize(HiveMindApiResponse& response) const {
    if (const auto* genResp = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_response = HiveMindApiResponse_generic_tag;
        return genResp->serialize(response.response.generic);
    }
    if (const auto* idResp = std::get_if<IdResponseDTO>(&m_response)) {
        response.which_response = HiveMindApiResponse_id_tag;
        return idResp->serialize(response.response.id);
    }
    return false;
}

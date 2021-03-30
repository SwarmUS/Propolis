#include "HiveMindHostApiResponseDTO.h"

HiveMindHostApiResponseDTO::HiveMindHostApiResponseDTO(const HiveMindHostApiResponse& response) {
    switch (response.which_response) {
    case HiveMindHostApiResponse_generic_tag:
        m_response = GenericResponseDTO(response.response.generic);
        break;
    default:
        m_response = std::monostate();
    }
}

HiveMindHostApiResponseDTO::HiveMindHostApiResponseDTO(const GenericResponseDTO& response) :
    m_response(response) {}


const std::variant<std::monostate, GenericResponseDTO>& HiveMindHostApiResponseDTO::
    getResponse() const {
    return m_response;
}

void HiveMindHostApiResponseDTO::setResponse(
    const std::variant<std::monostate, GenericResponseDTO>& response) {
    m_response = response;
}

bool HiveMindHostApiResponseDTO::serialize(HiveMindHostApiResponse& response) const {
    if (const auto* genResp = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_response = HiveMindHostApiResponse_generic_tag;
        return genResp->serialize(response.response.generic);
    }
    return false;
}

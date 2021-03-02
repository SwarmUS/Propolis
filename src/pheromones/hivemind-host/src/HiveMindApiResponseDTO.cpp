#include "HiveMindApiResponseDTO.h"

HiveMindApiResponseDTO::HiveMindApiResponseDTO(const HiveMindApiResponse& response) :
    m_destination(targetToDTO(response.destination)) {
    switch (response.which_response) {
    case HiveMindApiResponse_id_tag:
        m_response = IdResponseDTO(response.response.id);
        break;
    default:
        m_response = std::monostate();
    }
}

HiveMindApiResponseDTO::HiveMindApiResponseDTO(UserCallTargetDTO destination,
                                               const IdResponseDTO& response) :
    m_destination(destination), m_response(response) {}

UserCallTargetDTO HiveMindApiResponseDTO::getDestination() const { return m_destination; }

const std::variant<std::monostate, IdResponseDTO>& HiveMindApiResponseDTO::getResponse() const {
    return m_response;
}

void HiveMindApiResponseDTO::setDestination(UserCallTargetDTO destination) {
    m_destination = destination;
}

void HiveMindApiResponseDTO::setResponse(
    const std::variant<std::monostate, IdResponseDTO>& response) {
    m_response = response;
}

bool HiveMindApiResponseDTO::serialize(HiveMindApiResponse& response) const {
    response.destination = dtoToTarget(m_destination);
    if (const auto* idReq = std::get_if<IdResponseDTO>(&m_response)) {
        response.which_response = HiveMindApiResponse_id_tag;
        return idReq->serialize(response.response.id);
    }
    return false;
}

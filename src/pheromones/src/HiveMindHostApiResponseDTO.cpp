#include "HiveMindHostApiResponseDTO.h"

HiveMindHostApiResponseDTO::HiveMindHostApiResponseDTO(const HiveMindHostApiResponse& response) {
    switch (response.which_response) {
    case HiveMindHostApiResponse_neighbor_tag:
        m_response = GetNeighborResponseDTO(response.response.neighbor);
        break;
    case HiveMindHostApiResponse_neighbors_list_tag:
        m_response = GetNeighborsListResponseDTO(response.response.neighbors_list);
        break;
    default:
        m_response = std::monostate();
    }
}

HiveMindHostApiResponseDTO::HiveMindHostApiResponseDTO(const GetNeighborResponseDTO& response) :
    m_response(response) {}

HiveMindHostApiResponseDTO::HiveMindHostApiResponseDTO(
    const GetNeighborsListResponseDTO& response) :
    m_response(response) {}

const std::variant<std::monostate, GetNeighborResponseDTO, GetNeighborsListResponseDTO>&
HiveMindHostApiResponseDTO::getResponse() const {
    return m_response;
}

void HiveMindHostApiResponseDTO::setResponse(
    const std::variant<std::monostate, GetNeighborResponseDTO, GetNeighborsListResponseDTO>&
        response) {
    m_response = response;
}

bool HiveMindHostApiResponseDTO::serialize(HiveMindHostApiResponse& response) const {

    if (const auto* resp = std::get_if<GetNeighborResponseDTO>(&m_response)) {
        response.which_response = HiveMindHostApiResponse_neighbor_tag;
        return resp->serialize(response.response.neighbor);
    }

    if (const auto* resp = std::get_if<GetNeighborsListResponseDTO>(&m_response)) {
        response.which_response = HiveMindHostApiResponse_neighbors_list_tag;
        return resp->serialize(response.response.neighbors_list);
    }

    return false;
}

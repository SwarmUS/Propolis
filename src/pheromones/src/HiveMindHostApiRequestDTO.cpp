#include "HiveMindHostApiRequestDTO.h"

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const HiveMindHostApiRequest& request) {
    switch (request.which_request) {
    case HiveMindHostApiRequest_bytes_tag:
        m_request = BytesDTO(request.request.bytes);
        break;
    case HiveMindHostApiRequest_neighbor_tag:
        m_request = GetNeighborRequestDTO(request.request.neighbor);
        break;
    case HiveMindHostApiRequest_neighbors_list_tag:
        m_request = GetNeighborsListRequestDTO(request.request.neighbors_list);
        break;
    default:
        m_request = std::monostate();
    }
}

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const BytesDTO& bytes) : m_request(bytes) {}

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const GetNeighborRequest& req) :
    m_request(req) {}
HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const GetNeighborRequestDTO& req) :
    m_request(req) {}

const std::variant<std::monostate, BytesDTO, GetNeighborRequestDTO, GetNeighborsListRequestDTO>&
HiveMindHostApiRequestDTO::getRequest() const {
    return m_request;
}

void HiveMindHostApiRequestDTO::setRequest(
    const std::variant<std::monostate, BytesDTO, GetNeighborRequestDTO, GetNeighborsListRequestDTO>&
        request) {
    m_request = request;
}

bool HiveMindHostApiRequestDTO::serialize(HiveMindHostApiRequest& request) const {
    if (const auto* bytes = std::get_if<BytesDTO>(&m_request)) {
        request.which_request = HiveMindHostApiRequest_bytes_tag;
        return bytes->serialize(request.request.bytes);
    }

    if (const auto* req = std::get_if<GetNeighborRequestDTO>(&m_request)) {
        request.which_request = HiveMindHostApiRequest_neighbor_tag;
        return req->serialize(request.request.neighbor);
    }

    if (const auto* req = std::get_if<GetNeighborsListRequestDTO>(&m_request)) {
        request.which_request = HiveMindHostApiRequest_neighbors_list_tag;
        return req->serialize(request.request.neighbors_list);
    }

    return false;
}

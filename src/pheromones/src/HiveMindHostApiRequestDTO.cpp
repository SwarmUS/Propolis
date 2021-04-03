#include "HiveMindHostApiRequestDTO.h"

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const HiveMindHostApiRequest& request) {
    switch (request.which_request) {
    case HiveMindHostApiRequest_bytes_tag:
        m_request = BytesDTO(request.request.bytes);
        break;
    default:
        m_request = std::monostate();
    }
}

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const BytesDTO& bytes) : m_request(bytes) {}

const std::variant<std::monostate, BytesDTO>& HiveMindHostApiRequestDTO::getRequest() const {
    return m_request;
}

void HiveMindHostApiRequestDTO::setRequest(const std::variant<std::monostate, BytesDTO>& request) {
    m_request = request;
}

bool HiveMindHostApiRequestDTO::serialize(HiveMindHostApiRequest& request) const {
    if (const auto* bytes = std::get_if<BytesDTO>(&m_request)) {
        request.which_request = HiveMindHostApiRequest_bytes_tag;
        return bytes->serialize(request.request.bytes);
    }

    return false;
}

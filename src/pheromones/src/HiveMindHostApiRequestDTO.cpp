#include "HiveMindHostApiRequestDTO.h"

HiveMindHostApiRequestDTO::HiveMindHostApiRequestDTO(const HiveMindHostApiRequest& request) {
    switch (request.which_request) {
    default:
        m_request = std::monostate();
    }
}

const std::variant<std::monostate>& HiveMindHostApiRequestDTO::getRequest() const {
    return m_request;
}

void HiveMindHostApiRequestDTO::setRequest(const std::variant<std::monostate>& request) {
    m_request = request;
}

bool HiveMindHostApiRequestDTO::serialize(HiveMindHostApiRequest& request) const {
    (void) request;
    (void) this;
    return false;
}

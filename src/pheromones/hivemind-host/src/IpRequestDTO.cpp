#include "IpRequestDTO.h"

IPRequestDTO::IPRequestDTO(const IPRequest& ipRequest) {
    m_ip = ipRequest.ip;
}

IPRequestDTO::IPRequestDTO(uint32_t ipAddress) {
    m_ip = ipAddress;
}

IPRequestDTO::IPRequestDTO() {
    m_ip = std::monostate();
}

const std::variant<std::monostate, uint32_t> & IPRequestDTO::getIP() const {
    return m_ip;
}

void IPRequestDTO::setIP(const std::variant<std::monostate, uint32_t>& ip) {
    m_ip = ip;
}

bool IPRequestDTO::serialize(IPRequest& ipRequest) const {
    if (const auto* ip = std::get_if<uint32_t>(&m_ip)) {
        ipRequest.ip = *ip;
        return true;
    }

    return false;
}
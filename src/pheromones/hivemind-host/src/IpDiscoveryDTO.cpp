#include "IpDiscoveryDTO.h"

IPDiscoveryDTO::IPDiscoveryDTO(const IPDiscovery & ipDiscovery) {
    m_ip = ipDiscovery.ip;
}

IPDiscoveryDTO::IPDiscoveryDTO(uint32_t ipAddress) {
    m_ip = ipAddress;
}

IPDiscoveryDTO::IPDiscoveryDTO() {
    m_ip = std::monostate();
}

const std::variant<std::monostate, uint32_t> & IPDiscoveryDTO::getIP() const {
    return m_ip;
}

void IPDiscoveryDTO::setIP(const std::variant<std::monostate, uint32_t>& ip) {
    m_ip = ip;
}

bool IPDiscoveryDTO::serialize(IPDiscovery & ipDiscovery) const {
    if (const auto* ip = std::get_if<uint32_t>(&m_ip)) {
        ipDiscovery.ip = *ip;
        return true;
    }

    return false;
}
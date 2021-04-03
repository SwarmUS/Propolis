#include "IpDiscoveryDTO.h"

IPDiscoveryDTO::IPDiscoveryDTO(const IPDiscovery& ipDiscovery) : m_ip(ipDiscovery.ip) {}

IPDiscoveryDTO::IPDiscoveryDTO(uint32_t ipAddress) : m_ip(ipAddress) {}

uint32_t IPDiscoveryDTO::getIP() const { return m_ip; }

void IPDiscoveryDTO::setIP(uint32_t ip) { m_ip = ip; }

bool IPDiscoveryDTO::serialize(IPDiscovery& ipDiscovery) const {
    ipDiscovery.ip = m_ip;
    return true;
}
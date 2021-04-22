#include "GetAgentsListResponseDTO.h"

GetAgentsListResponseDTO::GetAgentsListResponseDTO(const GetAgentsListResponse& resp) {
    setAgents(resp.agents, resp.agents_count);
}

GetAgentsListResponseDTO::GetAgentsListResponseDTO(uint16_t* agents,
                                                         uint16_t agentsLength) {
    setAgents(agents, agentsLength);
}

const std::array<uint16_t, GetAgentsListResponseDTO::AGENTS_MAX_SIZE>&
GetAgentsListResponseDTO::getAgents() const {
    return m_agents;
}

std::array<uint16_t, GetAgentsListResponseDTO::AGENTS_MAX_SIZE>& GetAgentsListResponseDTO::
    getRawAgents() {
    return m_agents;
}

uint16_t GetAgentsListResponseDTO::getAgentsLength() const { return m_agentsLength; }

bool GetAgentsListResponseDTO::setRawAgentsLength(uint16_t agentsLength) {
    m_agentsLength = agentsLength < m_agents.size() ? agentsLength : m_agents.size();
    return m_agentsLength == agentsLength;
}

void GetAgentsListResponseDTO::setAgents(const uint16_t* agents,
                                               uint16_t agentsLength) {
    setRawAgentsLength(agentsLength);
    memcpy(m_agents.data(), agents, m_agentsLength);
}

void GetAgentsListResponseDTO::setAgents(const uint32_t* agents,
                                               uint16_t agentsLength) {
    setRawAgentsLength(agentsLength);
    for (uint16_t i = 0; i < m_agentsLength; i++) {
        m_agents[i] = agents[i];
    }
}

bool GetAgentsListResponseDTO::serialize(GetAgentsListResponse& resp) const {
    resp.agents_count = m_agentsLength;
    memcpy(resp.agents, m_agents.data(), m_agentsLength);
    return true;
}

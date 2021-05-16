#include "GreetingDTO.h"

GreetingDTO::GreetingDTO(const Greeting& greeting) : m_agentId(greeting.agent_id) {}

GreetingDTO::GreetingDTO(uint32_t agentId) : m_agentId(agentId) {}

uint16_t GreetingDTO::getId() const { return m_agentId; }

void GreetingDTO::setId(uint32_t agentId) { m_agentId = agentId; }

bool GreetingDTO::serialize(Greeting& greeting) const {
    greeting.agent_id = m_agentId;
    return true;
}

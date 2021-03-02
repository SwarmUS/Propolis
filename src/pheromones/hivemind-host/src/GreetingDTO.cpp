#include "GreetingDTO.h"

GreetingDTO::GreetingDTO(const Greeting& greeting) : m_id(greeting.id) {}

GreetingDTO::GreetingDTO(uint32_t id) : m_id(id) {}

uint32_t GreetingDTO::getId() const { return m_id; }

void GreetingDTO::setId(uint32_t id) { m_id = id; }

bool GreetingDTO::serialize(Greeting& greeting) const {
    greeting.id = m_id;
    return true;
}

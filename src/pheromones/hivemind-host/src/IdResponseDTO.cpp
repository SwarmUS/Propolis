#include "IdResponseDTO.h"

IdResponseDTO::IdResponseDTO(const IdResponse& resp) : m_id(resp.id) {}

IdResponseDTO::IdResponseDTO(uint32_t id) : m_id(id) {}

uint32_t IdResponseDTO::getId() const { return m_id; }

void IdResponseDTO::setId(uint32_t id) { m_id = id; }

bool IdResponseDTO::serialize(IdResponse& resp) const {
    resp.id = m_id;
    return true;
}

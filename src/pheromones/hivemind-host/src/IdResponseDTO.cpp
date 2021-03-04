#include "IdResponseDTO.h"

IdResponseDTO::IdResponseDTO(const IdResponse& resp) : m_id(resp.id) {}

IdResponseDTO::IdResponseDTO(uint16_t id) : m_id(id) {}

uint16_t IdResponseDTO::getId() const { return m_id; }

void IdResponseDTO::setId(uint16_t id) { m_id = id; }

bool IdResponseDTO::serialize(IdResponse& resp) const {
    resp.id = (uint16_t)m_id;
    return true;
}

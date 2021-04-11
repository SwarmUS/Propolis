#include "GetNeighborResponseDTO.h"

GetNeighborResponseDTO::GetNeighborResponseDTO(const GetNeighborResponse resp) :
    m_neighborId(resp.neighbor_id) {
    if (resp.has_position) {
        m_pos = NeighborPositionDTO(resp.position);
    } else {
        m_pos = {};
    }
}

GetNeighborResponseDTO::GetNeighborResponseDTO(uint16_t neighborId,
                                               const std::optional<NeighborPositionDTO>& pos) :
    m_neighborId(neighborId), m_pos(pos) {}

uint16_t GetNeighborResponseDTO::getNeighborId() const { return m_neighborId; }

const std::optional<NeighborPositionDTO>& GetNeighborResponseDTO::getNeighborPosition() const {
    return m_pos;
}

void GetNeighborResponseDTO::setNeighborId(uint16_t id) { m_neighborId = id; }

void GetNeighborResponseDTO::setNeighborPosition(const std::optional<NeighborPositionDTO>& pos) {
    m_pos = pos;
}

bool GetNeighborResponseDTO::serialize(GetNeighborResponse& resp) const {
    resp.neighbor_id = m_neighborId;
    resp.has_position = m_pos.has_value();
    if (m_pos) {
        return m_pos.value().serialize(resp.position);
    }
    return true;
}

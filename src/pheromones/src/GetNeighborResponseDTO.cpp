#include "GetNeighborResponseDTO.h"

GetNeighborResponseDTO::GetNeighborResponseDTO(const GetNeighborResponse resp) :
    m_neighborId(resp.neighbor_id), m_pos(resp.position) {}

GetNeighborResponseDTO::GetNeighborResponseDTO(uint32_t neighborId,
                                               const RelativePositionDTO& pos) :
    m_neighborId(neighborId), m_pos(pos) {}

uint32_t GetNeighborResponseDTO::getNeighborId() const { return m_neighborId; }

const RelativePositionDTO& GetNeighborResponseDTO::getRelativePosition() const { return m_pos; }

void GetNeighborResponseDTO::setNeighborId(uint32_t id) { m_neighborId = id; }

void GetNeighborResponseDTO::setRelativePosition(const RelativePositionDTO& pos) { m_pos = pos; }

bool GetNeighborResponseDTO::serialize(GetNeighborResponse& resp) const {
    resp.neighbor_id = m_neighborId;
    resp.has_position = true;
    return m_pos.serialize(resp.position);
}

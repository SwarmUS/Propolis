#include "GetNeighborRequestDTO.h"

GetNeighborRequestDTO::GetNeighborRequestDTO(const GetNeighborRequest& req) :
    m_neighborId(req.neighbor_id) {}
GetNeighborRequestDTO::GetNeighborRequestDTO(uint16_t neighborId) : m_neighborId(neighborId) {}

uint16_t GetNeighborRequestDTO::getNeighborId() const { return m_neighborId; }

void GetNeighborRequestDTO::setNeighborId(uint16_t id) { m_neighborId = id; }

bool GetNeighborRequestDTO::serialize(GetNeighborRequest& req) const {
    req.neighbor_id = m_neighborId;
    return true;
}

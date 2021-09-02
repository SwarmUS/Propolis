#include "GetNeighborsListResponseDTO.h"

GetNeighborsListResponseDTO::GetNeighborsListResponseDTO(const GetNeighborsListResponse& resp) {
    setNeighbors(resp.neighbors, resp.neighbors_count);
}

GetNeighborsListResponseDTO::GetNeighborsListResponseDTO(uint16_t* neighbors,
                                                         uint16_t neighborsLength) {
    setNeighbors(neighbors, neighborsLength);
}

const std::array<uint16_t, GetNeighborsListResponseDTO::NEIGHBORS_MAX_SIZE>&
GetNeighborsListResponseDTO::getNeighbors() const {
    return m_neighbors;
}

std::array<uint16_t, GetNeighborsListResponseDTO::NEIGHBORS_MAX_SIZE>& GetNeighborsListResponseDTO::
    getRawNeighbors() {
    return m_neighbors;
}

uint16_t GetNeighborsListResponseDTO::getNeighborsLength() const { return m_neighborsLength; }

bool GetNeighborsListResponseDTO::setRawNeighborsLength(uint16_t neighborsLength) {
    m_neighborsLength = neighborsLength < m_neighbors.size() ? neighborsLength : m_neighbors.size();
    return m_neighborsLength == neighborsLength;
}

void GetNeighborsListResponseDTO::setNeighbors(const uint16_t* neighbors,
                                               uint16_t neighborsLength) {
    setRawNeighborsLength(neighborsLength);
    for (uint16_t i = 0; i < m_neighborsLength; i++) {
        m_neighbors[i] = neighbors[i];
    }
}

void GetNeighborsListResponseDTO::setNeighbors(const uint32_t* neighbors,
                                               uint16_t neighborsLength) {
    setRawNeighborsLength(neighborsLength);
    for (uint16_t i = 0; i < m_neighborsLength; i++) {
        m_neighbors[i] = neighbors[i];
    }
}

bool GetNeighborsListResponseDTO::serialize(GetNeighborsListResponse& resp) const {
    resp.neighbors_count = m_neighborsLength;
    for (uint16_t i = 0; i < m_neighborsLength; i++) {
        resp.neighbors[i] = m_neighbors[i];
    }
    return true;
}

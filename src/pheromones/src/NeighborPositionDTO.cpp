#include "NeighborPositionDTO.h"

NeighborPositionDTO::NeighborPositionDTO(const NeighborPosition& pos) :
    m_distance(pos.distance), m_azimuth(pos.azimuth), m_inLOS(pos.in_los) {}

NeighborPositionDTO::NeighborPositionDTO(float distance, float azimuth, bool inLOS) :
    m_distance(distance), m_azimuth(azimuth), m_inLOS(inLOS) {}

float NeighborPositionDTO::getDistance() const { return m_distance; }

bool NeighborPositionDTO::inLOS() const { return m_inLOS; }

float NeighborPositionDTO::getAzimuth() const { return m_azimuth; }

void NeighborPositionDTO::setDistance(float distance) { m_distance = distance; }

void NeighborPositionDTO::setAzimuth(float azimuth) { m_azimuth = azimuth; }

void NeighborPositionDTO::setInLOS(bool inLOS) { m_inLOS = inLOS; }

bool NeighborPositionDTO::serialize(NeighborPosition& pos) const {
    pos.distance = m_distance;
    pos.azimuth = m_azimuth;
    pos.in_los = m_inLOS;
    return true;
}

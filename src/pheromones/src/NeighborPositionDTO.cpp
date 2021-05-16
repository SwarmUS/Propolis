#include "NeighborPositionDTO.h"

NeighborPositionDTO::NeighborPositionDTO(const NeighborPosition& pos) :
    m_distance(pos.distance),
    m_relativeOrientation(pos.relative_orientation),
    m_inLOS(pos.in_los) {}

NeighborPositionDTO::NeighborPositionDTO(float distance, float relativeOrientation, bool inLOS) :
    m_distance(distance), m_relativeOrientation(relativeOrientation), m_inLOS(inLOS) {}

float NeighborPositionDTO::getDistance() const { return m_distance; }

bool NeighborPositionDTO::inLOS() const { return m_inLOS; }

float NeighborPositionDTO::getRelativeOrientation() const { return m_relativeOrientation; }

void NeighborPositionDTO::setDistance(float distance) { m_distance = distance; }

void NeighborPositionDTO::setRelativeOrientation(float orientation) {
    m_relativeOrientation = orientation;
}

void NeighborPositionDTO::setInLOS(bool inLOS) { m_inLOS = inLOS; }

bool NeighborPositionDTO::serialize(NeighborPosition& pos) const {
    pos.distance = m_distance;
    pos.relative_orientation = m_relativeOrientation;
    pos.in_los = m_inLOS;
    return true;
}

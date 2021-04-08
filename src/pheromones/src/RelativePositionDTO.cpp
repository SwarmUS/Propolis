#include "RelativePositionDTO.h"

RelativePositionDTO::RelativePositionDTO(const RelativePosition& pos) :
    m_distance(pos.distance), m_relativeOrientation(pos.relative_orientation), m_inLOS(pos.inLOS) {}

RelativePositionDTO::RelativePositionDTO(float distance, float relativeOrientation, bool inLOS) :
    m_distance(distance), m_relativeOrientation(relativeOrientation), m_inLOS(inLOS) {}

float RelativePositionDTO::getDistance() const { return m_distance; }

bool RelativePositionDTO::inLOS() const { return m_inLOS; }

float RelativePositionDTO::getRelativeOrientation() const { return m_relativeOrientation; }

void RelativePositionDTO::setDistance(float distance) { m_distance = distance; }

void RelativePositionDTO::setRelativeOrientation(float orientation) {
    m_relativeOrientation = orientation;
}

void RelativePositionDTO::setInLOS(bool inLOS) { m_inLOS = inLOS; }

bool RelativePositionDTO::serialize(RelativePosition& pos) const {
    pos.distance = m_distance;
    pos.relative_orientation = m_relativeOrientation;
    pos.inLOS = m_inLOS;
    return true;
}

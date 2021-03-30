
#include <SetCalibrationDistanceDTO.h>

SetCalibrationDistanceDTO::SetCalibrationDistanceDTO(const SetCalibrationDistance& message) {
    m_distance = message.distance;
}

SetCalibrationDistanceDTO::SetCalibrationDistanceDTO(float distance) { m_distance = distance; }

float SetCalibrationDistanceDTO::getDistance() const { return m_distance; }

void SetCalibrationDistanceDTO::setDistance(float distance) { m_distance = distance; }

bool SetCalibrationDistanceDTO::serialize(SetCalibrationDistance& message) const {
    message.distance = m_distance;
    return true;
}


#include <interloc/ConfigureTWRCalibrationDTO.h>
#include <message.pb.h>

ConfigureTWRCalibrationDTO::ConfigureTWRCalibrationDTO(const ConfigureTWRCalibration& message) {
    m_distance = message.distance;
}

ConfigureTWRCalibrationDTO::ConfigureTWRCalibrationDTO(float distance) { m_distance = distance; }

float ConfigureTWRCalibrationDTO::getDistance() const { return m_distance; }

void ConfigureTWRCalibrationDTO::setDistance(float distance) { m_distance = distance; }

bool ConfigureTWRCalibrationDTO::serialize(ConfigureTWRCalibration& message) const {
    message.distance = m_distance;
    return true;
}

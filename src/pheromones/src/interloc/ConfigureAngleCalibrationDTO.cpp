
#include <interloc/ConfigureAngleCalibrationDTO.h>
#include <message.pb.h>
ConfigureAngleCalibrationDTO::ConfigureAngleCalibrationDTO(
    const ConfigureAngleCalibration& message) {
    m_numberOfFrames = message.numberOfFrames;
}

ConfigureAngleCalibrationDTO::ConfigureAngleCalibrationDTO(uint32_t numberOfFrames) {
    m_numberOfFrames = numberOfFrames;
}

uint32_t ConfigureAngleCalibrationDTO::getNumberOfFrames() const { return m_numberOfFrames; }

void ConfigureAngleCalibrationDTO::setNumberOfFrames(uint32_t numberOfFrames) {
    m_numberOfFrames = numberOfFrames;
}

bool ConfigureAngleCalibrationDTO::serialize(ConfigureAngleCalibration& message) const {
    message.numberOfFrames = m_numberOfFrames;
    return true;
}

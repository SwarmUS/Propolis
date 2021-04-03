#include "StartCalibrationDTO.h"

StartCalibrationDTO::StartCalibrationDTO(const StartCalibration& message) {
    m_calibrationMode = calibrationModeToDTO(message.mode);
}

StartCalibrationDTO::StartCalibrationDTO(CalibrationModeDTO mode) : m_calibrationMode(mode) {}

CalibrationModeDTO StartCalibrationDTO::getCalibrationMode() const { return m_calibrationMode; }

void StartCalibrationDTO::setCalibrationMode(CalibrationModeDTO mode) { m_calibrationMode = mode; }

bool StartCalibrationDTO::serialize(StartCalibration& message) const {
    message.mode = dtoToCalibrationMode(m_calibrationMode);

    return true;
}
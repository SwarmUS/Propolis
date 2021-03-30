#include "CalibrationModeDTO.h"

CalibrationModeDTO calibrationModeToDTO(CalibrationMode mode) {
    switch (mode) {

    case CalibrationMode_INITIATOR:
        return CalibrationModeDTO::INITIATOR;

    case CalibrationMode_RESPONDER:
        return CalibrationModeDTO::RESPONDER;

    default:
        return CalibrationModeDTO::UNSUPORTED;
    }
}

/**
 *@brief get the equivalent of a dto calibration mode to a nanopb one
 *
 *@return the nanopb equivalent
 **/
CalibrationMode dtoToCalibrationMode(CalibrationModeDTO mode) {
    switch (mode) {

    case CalibrationModeDTO::INITIATOR:
        return CalibrationMode_INITIATOR;

    case CalibrationModeDTO::RESPONDER:
        return CalibrationMode_RESPONDER;

    default:
        return CalibrationMode_UNSUPORTED;
    }
}
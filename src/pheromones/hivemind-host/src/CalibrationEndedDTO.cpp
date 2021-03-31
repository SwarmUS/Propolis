#include "CalibrationEndedDTO.h"

CalibrationEndedDTO::CalibrationEndedDTO(const CalibrationEnded& message) { (void)message; }

bool CalibrationEndedDTO::serialize(CalibrationEnded& message) const {
    (void)message;
    return true;
}

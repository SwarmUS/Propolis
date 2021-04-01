#include "CalibrationEndedDTO.h"

CalibrationEndedDTO::CalibrationEndedDTO(const CalibrationEnded& message) { (void)message; }

bool CalibrationEndedDTO::serialize(CalibrationEnded& message) {
    (void)message;
    return true;
}

#ifndef __STOPCALIBRATIONDTO_H__
#define __STOPCALIBRATIONDTO_H__

#include <message.pb.h>

/**
 * @brief Class that represents a Stop Calibration protobuf message
 */
class StopCalibrationDTO {
  public:
    StopCalibrationDTO(const StopCalibration& message){};

    /**
     * @brief Serializes to a protobuf stream
     * @param message [out] message to serialize to
     * @return true if successful, false otherwise
     */
    bool serialize(StopCalibration& message) const { return true; };
};

#endif //__STOPCALIBRATIONDTO_H__

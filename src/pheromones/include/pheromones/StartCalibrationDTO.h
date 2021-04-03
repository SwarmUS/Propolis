#ifndef __STARTCALIBRATIONDTO_H__
#define __STARTCALIBRATIONDTO_H__

#include "CalibrationModeDTO.h"
#include <cstdint>
#include <message.pb.h>
#include <variant>

/**
 * @brief Class to represent a start calibration message
 */
class StartCalibrationDTO {
  public:
    StartCalibrationDTO(const StartCalibration& message);
    StartCalibrationDTO(CalibrationModeDTO mode);

    /**
     * @brief Returns the calibration mode
     * @return calibration mode
     */
    CalibrationModeDTO getCalibrationMode() const;

    /**
     * @brief Sets the calibration mode
     * @param mode Calibration mode
     */
    void setCalibrationMode(CalibrationModeDTO mode);

    /**
     *@brief serialize a StartCalibration for nanopb, sets the fields properly before using
     *pb_encode
     *@param message the message to serialize
     *@return true if successful (fields were recognized) false if not */
    bool serialize(StartCalibration& message) const;

  private:
    CalibrationModeDTO m_calibrationMode;
};

#endif //__STARTCALIBRATIONDTO_H__

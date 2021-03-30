#ifndef __SETCALIBRATIONDISTANCEDTO_H__
#define __SETCALIBRATIONDISTANCEDTO_H__

#include <message.pb.h>

/**
 * @brief Class to represent a Set Calibration Distance protobuf message
 */
class SetCalibrationDistanceDTO {
  public:
    SetCalibrationDistanceDTO(const SetCalibrationDistance& message);
    SetCalibrationDistanceDTO(float distance);

    /**
     * @brief Returns the distance in the message
     * @return The distance in meters
     */
    float getDistance() const;

    /**
     * @brief Sets the distance in the message
     * @param distance Distance in meters
     */
    void setDistance(float distance);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(SetCalibrationDistance& message) const;

  private:
    float m_distance;
};

#endif //__SETCALIBRATIONDISTANCEDTO_H__

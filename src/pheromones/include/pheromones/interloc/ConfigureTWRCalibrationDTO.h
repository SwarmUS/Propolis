#ifndef __CONFIGURETWRCALIBRATIONDTO_H__
#define __CONFIGURETWRCALIBRATIONDTO_H__

#include <message.pb.h>

/**
 * @brief Class to represent a Configure TWR Calibration protobuf message
 */
class ConfigureTWRCalibrationDTO {
  public:
    ConfigureTWRCalibrationDTO(const ConfigureTWRCalibration& message);
    ConfigureTWRCalibrationDTO(float distance);

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
    bool serialize(ConfigureTWRCalibration& message) const;

  private:
    float m_distance;
};

#endif //__CONFIGURETWRCALIBRATIONDTO_H__

#ifndef __CONFIGUREANGLECALIBRATIONDTO_H__
#define __CONFIGUREANGLECALIBRATIONDTO_H__

#include <cstdint>
#include <message.pb.h>

/**
 * @brief Class to represent a Configure Angle Calibration protobuf message
 */
class ConfigureAngleCalibrationDTO {
  public:
    ConfigureAngleCalibrationDTO(const ConfigureAngleCalibration& message);
    ConfigureAngleCalibrationDTO(uint32_t numberOfFrames);

    /**
     * @brief Returns the number of frames to read
     * @return Number of frames
     */
    uint32_t getNumberOfFrames() const;

    /**
     * @brief Sets the number of frames to read
     * @param numberOfFrames Number of frames
     */
    void setNumberOfFrames(uint32_t numberOfFrames);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(ConfigureAngleCalibration& message) const;

  private:
    uint32_t m_numberOfFrames;
};

#endif //__CONFIGUREANGLECALIBRATIONDTO_H__

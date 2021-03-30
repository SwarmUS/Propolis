#ifndef __CALIBRATIONMESSAGEDTO_H__
#define __CALIBRATIONMESSAGEDTO_H__

#include "SetCalibrationDistanceDTO.h"
#include "StartCalibrationDTO.h"
#include "StopCalibrationDTO.h"
#include <message.pb.h>

class CalibrationMessageDTO {
  public:
    CalibrationMessageDTO(const Calibration& message);

    CalibrationMessageDTO(const StartCalibrationDTO& call);
    CalibrationMessageDTO(const StopCalibrationDTO& call);
    CalibrationMessageDTO(const SetCalibrationDistanceDTO& call);

    /**
     * @brief Gets the call contained in the message
     * @return The call
     */
    const std::
        variant<std::monostate, StartCalibrationDTO, StopCalibrationDTO, SetCalibrationDistanceDTO>&
        getCall() const;

    /**
     * @brief Sets the call contained in the message
     * @param call The call
     */
    void setCall(const std::variant<std::monostate,
                                    StartCalibrationDTO,
                                    StopCalibrationDTO,
                                    SetCalibrationDistanceDTO>& call);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] The message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(Calibration& message) const;

  private:
    std::variant<std::monostate, StartCalibrationDTO, StopCalibrationDTO, SetCalibrationDistanceDTO>
        m_call;
};

#endif //__CALIBRATIONMESSAGEDTO_H__

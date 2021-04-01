#ifndef __CALIBRATIONMESSAGEDTO_H__
#define __CALIBRATIONMESSAGEDTO_H__

#include "CalibrationEndedDTO.h"
#include "SetCalibrationDistanceDTO.h"
#include "StartCalibrationDTO.h"
#include "StopCalibrationDTO.h"
#include <message.pb.h>

class CalibrationMessageDTO {
  public:
    CalibrationMessageDTO(const CalibrationMessage& message);

    CalibrationMessageDTO(const StartCalibrationDTO& call);
    CalibrationMessageDTO(const StopCalibrationDTO& call);
    CalibrationMessageDTO(const SetCalibrationDistanceDTO& call);
    CalibrationMessageDTO(const CalibrationEndedDTO& call);

    /**
     * @brief Gets the call contained in the message
     * @return The call
     */
    const std::variant<std::monostate,
                       StartCalibrationDTO,
                       StopCalibrationDTO,
                       SetCalibrationDistanceDTO,
                       CalibrationEndedDTO>&
    getCall() const;

    /**
     * @brief Sets the call contained in the message
     * @param call The call
     */
    void setCall(const std::variant<std::monostate,
                                    StartCalibrationDTO,
                                    StopCalibrationDTO,
                                    SetCalibrationDistanceDTO,
                                    CalibrationEndedDTO>& call);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] The message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(CalibrationMessage& message) const;

  private:
    std::variant<std::monostate,
                 StartCalibrationDTO,
                 StopCalibrationDTO,
                 SetCalibrationDistanceDTO,
                 CalibrationEndedDTO>
        m_call;
};

#endif //__CALIBRATIONMESSAGEDTO_H__

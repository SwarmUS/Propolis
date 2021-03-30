#ifndef __CALIBRATIONMESSAGEDTO_H__
#define __CALIBRATIONMESSAGEDTO_H__

#include "StartCalibrationDTO.h"
#include "StopCalibrationDTO.h"
#include <message.pb.h>

class CalibrationMessageDTO {
  public:
    CalibrationMessageDTO(const Calibration& message);

    CalibrationMessageDTO(const StartCalibrationDTO& call);
    CalibrationMessageDTO(const StopCalibrationDTO& call);

    const std::variant<std::monostate, StartCalibrationDTO, StopCalibrationDTO>& getCall();
    void setCall(const std::variant<std::monostate, StartCalibrationDTO, StopCalibrationDTO>& call);

  private:
    std::variant<std::monostate, StartCalibrationDTO, StopCalibrationDTO> m_call;
};

#endif //__CALIBRATIONMESSAGEDTO_H__

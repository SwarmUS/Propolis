
#ifndef __CALIBRATIONENDEDDTO_H__
#define __CALIBRATIONENDEDDTO_H__

#include <message.pb.h>

/**
 * @brief Class that represents a CalibrationEnded protobuf message
 */
class CalibrationEndedDTO {
  public:
    CalibrationEndedDTO(const CalibrationEnded& message);
    CalibrationEndedDTO() = default;

    /**
     * @brief Serializes to a protobuf stream
     * @param message [out] message to serialize to
     * @return true if successful, false otherwise
     */
    bool serialize(CalibrationEnded& message) const;
};

#endif //__CALIBRATIONENDEDDTO_H__

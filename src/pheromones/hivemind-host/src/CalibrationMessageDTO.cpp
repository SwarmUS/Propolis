#include "CalibrationMessageDTO.h"

CalibrationMessageDTO::CalibrationMessageDTO(const CalibrationMessage& message) {
    switch (message.which_call) {
    case CalibrationMessage_startCalib_tag:
        m_call = StartCalibrationDTO(message.call.startCalib);
        break;

    case CalibrationMessage_stopCalib_tag:
        m_call = StopCalibrationDTO(message.call.stopCalib);
        break;

    case CalibrationMessage_setDistance_tag:
        m_call = SetCalibrationDistanceDTO(message.call.setDistance);
        break;

    case CalibrationMessage_calibEnded_tag:
        m_call = CalibrationEndedDTO(message.call.calibEnded);
        break;

    default:
        m_call = std::monostate();
    }
}

CalibrationMessageDTO::CalibrationMessageDTO(const StartCalibrationDTO& call) : m_call(call) {}
CalibrationMessageDTO::CalibrationMessageDTO(const StopCalibrationDTO& call) : m_call(call) {}
CalibrationMessageDTO::CalibrationMessageDTO(const SetCalibrationDistanceDTO& call) :
    m_call(call) {}
CalibrationMessageDTO::CalibrationMessageDTO(const CalibrationEndedDTO& call) : m_call(call) {}

const std::variant<std::monostate,
                   StartCalibrationDTO,
                   StopCalibrationDTO,
                   SetCalibrationDistanceDTO,
                   CalibrationEndedDTO>&
CalibrationMessageDTO::getCall() const {
    return m_call;
}
void CalibrationMessageDTO::setCall(const std::variant<std::monostate,
                                                       StartCalibrationDTO,
                                                       StopCalibrationDTO,
                                                       SetCalibrationDistanceDTO,
                                                       CalibrationEndedDTO>& call) {
    m_call = call;
}

bool CalibrationMessageDTO::serialize(CalibrationMessage& message) const {

    if (const auto* startCalib = std::get_if<StartCalibrationDTO>(&m_call)) {
        message.which_call = CalibrationMessage_startCalib_tag;
        return startCalib->serialize(message.call.startCalib);
    }
    if (const auto* stopCalib = std::get_if<StopCalibrationDTO>(&m_call)) {
        message.which_call = CalibrationMessage_stopCalib_tag;
        return stopCalib->serialize(message.call.stopCalib);
    }
    if (const auto* setDistance = std::get_if<SetCalibrationDistanceDTO>(&m_call)) {
        message.which_call = CalibrationMessage_setDistance_tag;
        return setDistance->serialize(message.call.setDistance);
    }
    if (const auto* calibEnded = std::get_if<CalibrationEndedDTO>(&m_call)) {
        message.which_call = CalibrationMessage_calibEnded_tag;
        return calibEnded->serialize(message.call.calibEnded);
    }

    return false;
}

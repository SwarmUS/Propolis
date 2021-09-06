#include "interloc/InterlocAPIDTO.h"
InterlocAPIDTO::InterlocAPIDTO(const InterlocAPI& message) {
    //    switch (message.which_message) {
    //    case InterlocAPI_calibration_tag:
    //        m_apiCall = CalibrationMessageDTO(message.message.calibration);
    //        break;
    //
    //    default:
    //        m_apiCall = std::monostate();
    //    }
}
//
// InterlocAPIDTO::InterlocAPIDTO(const CalibrationMessageDTO& calibrationMessage) :
//    m_apiCall(calibrationMessage) {}
//
// const std::variant<std::monostate, CalibrationMessageDTO>& InterlocAPIDTO::getAPICall() const {
//    return m_apiCall;
//}
//
// void InterlocAPIDTO::setAPICall(std::variant<std::monostate, CalibrationMessageDTO>& apiCall) {
//    m_apiCall = apiCall;
//}

bool InterlocAPIDTO::serialize(InterlocAPI& message) const {

    //    if (const auto* calibrationMsg = std::get_if<CalibrationMessageDTO>(&m_apiCall)) {
    //        message.which_message = InterlocAPI_calibration_tag;
    //        return calibrationMsg->serialize(message.message.calibration);
    //    }

    return false;
}

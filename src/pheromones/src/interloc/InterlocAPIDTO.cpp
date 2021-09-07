#include "interloc/InterlocAPIDTO.h"
InterlocAPIDTO::InterlocAPIDTO(const InterlocAPI& message) {
    switch (message.which_message) {
    case InterlocAPI_setState_tag:
        m_apiCall = SetInterlocStateDTO(message.message.setState);
        break;

    case InterlocAPI_configure_tag:
        m_apiCall = InterlocConfigurationDTO(message.message.configure);
        break;

    case InterlocAPI_output_tag:
        m_apiCall = InterlocOutputMessageDTO(message.message.output);
        break;

    default:
        m_apiCall = std::monostate();
    }
}

InterlocAPIDTO::InterlocAPIDTO(const SetInterlocStateDTO& setStateMessage) {
    m_apiCall = setStateMessage;
}

InterlocAPIDTO::InterlocAPIDTO(const InterlocConfigurationDTO& interlocConfig) {
    m_apiCall = interlocConfig;
}

InterlocAPIDTO::InterlocAPIDTO(const InterlocOutputMessageDTO& interlocOutputMsg) {
    m_apiCall = interlocOutputMsg;
}

const std::variant<std::monostate,
                   SetInterlocStateDTO,
                   InterlocConfigurationDTO,
                   InterlocOutputMessageDTO>&
InterlocAPIDTO::getAPICall() const {
    return m_apiCall;
}

void InterlocAPIDTO::setAPICall(std::variant<std::monostate,
                                             SetInterlocStateDTO,
                                             InterlocConfigurationDTO,
                                             InterlocOutputMessageDTO>& apiCall) {
    m_apiCall = apiCall;
}

bool InterlocAPIDTO::serialize(InterlocAPI& message) const {

    if (const auto* setStateDTO = std::get_if<SetInterlocStateDTO>(&m_apiCall)) {
        message.which_message = InterlocAPI_setState_tag;
        return setStateDTO->serialize(message.message.setState);
    }

    if (const auto* configDTO = std::get_if<InterlocConfigurationDTO>(&m_apiCall)) {
        message.which_message = InterlocAPI_configure_tag;
        return configDTO->serialize(message.message.configure);
    }

    if (const auto* outputDTO = std::get_if<InterlocOutputMessageDTO>(&m_apiCall)) {
        message.which_message = InterlocAPI_output_tag;
        return outputDTO->serialize(message.message.output);
    }

    return false;
}

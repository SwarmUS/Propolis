#include <interloc/InterlocOutputMessageDTO.h>

InterlocOutputMessageDTO::InterlocOutputMessageDTO(const InterlocOutputMessage& message) {
    switch (message.which_outputMessage) {
    case InterlocOutputMessage_stateChange_tag:
        m_message = InterlocStateChangeDTO(message.outputMessage.stateChange);
        break;

    case InterlocOutputMessage_rawAngleData_tag:
        m_message = InterlocRawAngleDataDTO(message.outputMessage.rawAngleData);
        break;

    case InterlocOutputMessage_interlocDump_tag:
        m_message = InterlocDumpDTO(message.outputMessage.interlocDump);
        break;

    default:
        m_message = std::monostate();
    }
}

InterlocOutputMessageDTO::InterlocOutputMessageDTO(const InterlocStateChangeDTO& message) {
    m_message = message;
}

InterlocOutputMessageDTO::InterlocOutputMessageDTO(const InterlocRawAngleDataDTO& message) {
    m_message = message;
}

InterlocOutputMessageDTO::InterlocOutputMessageDTO(const InterlocDumpDTO& message) {
    m_message = message;
}

const std::
    variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO, InterlocDumpDTO>&
    InterlocOutputMessageDTO::getMessage() const {
    return m_message;
}

void InterlocOutputMessageDTO::setMessage(const std::variant<std::monostate,
                                                             InterlocStateChangeDTO,
                                                             InterlocRawAngleDataDTO,
                                                             InterlocDumpDTO>& message) {
    m_message = message;
}

bool InterlocOutputMessageDTO::serialize(InterlocOutputMessage& message) const {
    if (const auto* outputMessage = std::get_if<InterlocStateChangeDTO>(&m_message)) {
        message.which_outputMessage = InterlocOutputMessage_stateChange_tag;
        return outputMessage->serialize(message.outputMessage.stateChange);
    }

    if (const auto* outputMessage = std::get_if<InterlocRawAngleDataDTO>(&m_message)) {
        message.which_outputMessage = InterlocOutputMessage_rawAngleData_tag;
        return outputMessage->serialize(message.outputMessage.rawAngleData);
    }

    if (const auto* outputMessage = std::get_if<InterlocDumpDTO>(&m_message)) {
        message.which_outputMessage = InterlocOutputMessage_interlocDump_tag;
        return outputMessage->serialize(message.outputMessage.interlocDump);
    }

    return false;
}

#include "MessageDTO.h"

MessageDTO::MessageDTO(const Message& message) {

    m_destinationId = message.destinationId;
    m_sourceId = message.sourceId;

    switch (message.which_message) {

    case Message_request_tag:
        m_message = RequestDTO(message.message.request);
        break;

    default:
        m_message = std::monostate();
    }
}

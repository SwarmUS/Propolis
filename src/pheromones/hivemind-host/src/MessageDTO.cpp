#include "MessageDTO.h"

MessageDTO::MessageDTO(const Message& message) :
    m_sourceId(message.sourceId), m_destinationId(message.destinationId) {

    switch (message.which_message) {

    case Message_request_tag:
        m_message = RequestDTO(message.message.request);
        break;

    default:
        m_message = std::monostate();
    }
}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationiId, const RequestDTO& request) :
    m_sourceId(sourceId), m_destinationId(destinationiId), m_message(request) {}

const std::variant<std::monostate, RequestDTO>& MessageDTO::getMessage() const { return m_message; }

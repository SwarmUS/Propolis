#include "MessageDTO.h"

MessageDTO::MessageDTO(const Message& message) :
    m_sourceId(message.sourceId), m_destinationId(message.destinationId) {

    switch (message.which_message) {

    case Message_request_tag:
        m_message = RequestDTO(message.message.request);
        break;

    case Message_response_tag:
        m_message = ResponseDTO(message.message.response);
        break;

    default:
        m_message = std::monostate();
    }
}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const RequestDTO& request) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(request) {}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const ResponseDTO& response) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(response) {}

const std::variant<std::monostate, RequestDTO, ResponseDTO>& MessageDTO::getMessage() const {
    return m_message;
}

void MessageDTO::setSourceId(uint32_t id) { m_sourceId = id; }

void MessageDTO::setDestinationId(uint32_t id) { m_destinationId = id; }

void MessageDTO::setMessage(const std::variant<std::monostate, RequestDTO, ResponseDTO>& message) {
    m_message = message;
}

bool MessageDTO::serialize(Message& message) const {
    message.sourceId = m_sourceId;
    message.destinationId = m_destinationId;

    if (const RequestDTO* request = std::get_if<RequestDTO>(&m_message)) {
        message.which_message = Message_request_tag;
        return request->serialize(message.message.request);
    }

    if (const ResponseDTO* response = std::get_if<ResponseDTO>(&m_message)) {
        message.which_message = Message_response_tag;
        return response->serialize(message.message.response);
    }

    return false;
}

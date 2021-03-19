#include "MessageDTO.h"

MessageDTO::MessageDTO(const Message& message) :
    m_sourceId(message.source_id), m_destinationId(message.destination_id) {

    switch (message.which_message) {

    case Message_request_tag:
        m_message = RequestDTO(message.message.request);
        break;

    case Message_response_tag:
        m_message = ResponseDTO(message.message.response);
        break;

    case Message_greeting_tag:
        m_message = GreetingDTO(message.message.greeting);
        break;

    case Message_buzz_tag:
        m_message = BuzzMessage(message.message.buzz);
        break;

    default:
        m_message = std::monostate();
    }
}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const RequestDTO& request) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(request) {}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const ResponseDTO& response) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(response) {}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const GreetingDTO& greeting) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(greeting) {}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const BuzzMessageDTO& msg) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(msg) {}

MessageDTO::MessageDTO(uint32_t sourceId, uint32_t destinationId, const NetworkApiDTO& networkAPI) :
    m_sourceId(sourceId), m_destinationId(destinationId), m_message(networkAPI) {}

uint32_t MessageDTO::getSourceId() const { return m_sourceId; }

uint32_t MessageDTO::getDestinationId() const { return m_destinationId; }

const std::variant<std::monostate, RequestDTO, ResponseDTO, GreetingDTO, BuzzMessageDTO, NetworkApiDTO>&
MessageDTO::getMessage() const {
    return m_message;
}

void MessageDTO::setSourceId(uint32_t id) { m_sourceId = id; }

void MessageDTO::setDestinationId(uint32_t id) { m_destinationId = id; }

void MessageDTO::setMessage(
    const std::variant<std::monostate, RequestDTO, ResponseDTO, GreetingDTO, BuzzMessageDTO, NetworkApiDTO>&
        message) {
    m_message = message;
}

bool MessageDTO::serialize(Message& message) const {
    message.source_id = m_sourceId;
    message.destination_id = m_destinationId;

    if (const auto* request = std::get_if<RequestDTO>(&m_message)) {
        message.which_message = Message_request_tag;
        return request->serialize(message.message.request);
    }

    if (const auto* response = std::get_if<ResponseDTO>(&m_message)) {
        message.which_message = Message_response_tag;
        return response->serialize(message.message.response);
    }

    if (const auto* greeting = std::get_if<GreetingDTO>(&m_message)) {
        message.which_message = Message_greeting_tag;
        return greeting->serialize(message.message.greeting);
    }

    if (const auto* buzzMsg = std::get_if<BuzzMessageDTO>(&m_message)) {
        message.which_message = Message_buzz_tag;
        return buzzMsg->serialize(message.message.buzz);
    }

    if (const auto* networkAPI = std::get_if<NetworkApiDTO>(&m_message)) {
        message.which_message = Message_network_tag;
        return networkAPI->serialize(message.message.network);
    }

    return false;
}

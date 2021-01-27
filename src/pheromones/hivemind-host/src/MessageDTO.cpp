#include "MessageDTO.h"

MessageDTO MessageDTO::encode(const Message& message) {
    MessageDTO messageDTO;
    messageDTO.destinationId = message.destinationId;
    messageDTO.sourceId = message.sourceId;

    switch (message.which_message) {

    case Message_request_tag:
        messageDTO.message = RequestDTO::encode(message.message.request);
    }

    return messageDTO;
}

MessageDTO::MessageDTO(const Message& message) {

    m_destinationId = message.destinationId;
    m_sourceId = message.sourceId;

    switch (message.which_message) {

    case Message_request_tag:
        m_message = RequestDTO(message.message.request);
    }
}

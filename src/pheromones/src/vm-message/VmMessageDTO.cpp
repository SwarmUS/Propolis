#include "vm-message/VmMessageDTO.h"

VmMessageDTO::VmMessageDTO(const VmMessage message) {
    switch (message.which_message) {
    case VmMessage_buzz_tag:
        m_message = BuzzMessagesDTO(message.message.buzz);
        break;
    default:
        m_message = std::monostate();
    }
}
VmMessageDTO::VmMessageDTO(const BuzzMessagesDTO& message) { m_message = message; }

const std::variant<std::monostate, BuzzMessagesDTO>& VmMessageDTO::getMessage() const {
    return m_message;
}

void VmMessageDTO::setMessage(std::variant<std::monostate, BuzzMessagesDTO>& message) {
    m_message = message;
}

bool VmMessageDTO::serialize(VmMessage& message) const {

    if (const auto* buzzMessage = std::get_if<BuzzMessagesDTO>(&m_message)) {
        message.which_message = VmMessage_buzz_tag;
        return buzzMessage->serialize(message.message.buzz);
    }
    return false;
}

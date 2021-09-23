#include "vm-message/BuzzMessagesDTO.h"

BuzzMessagesDTO::BuzzMessagesDTO(const BuzzMessages& messages) {
    setMessages(messages.messages, messages.messages_count);
}

BuzzMessagesDTO::BuzzMessagesDTO(BuzzMessageDTO* messages, uint16_t messagesLength) {
    setMessages(messages, messagesLength);
}

const std::array<BuzzMessageDTO, BuzzMessagesDTO::MESSAGES_MAX_SIZE>& BuzzMessagesDTO::getMessages()
    const {
    return m_messages;
}

std::array<BuzzMessageDTO, BuzzMessagesDTO::MESSAGES_MAX_SIZE>& BuzzMessagesDTO::getRawMessages() {
    return m_messages;
}

uint16_t BuzzMessagesDTO::getMessagesLength() const { return m_messagesLength; }

bool BuzzMessagesDTO::setRawMessagesLength(uint16_t messagesLength) {
    m_messagesLength = messagesLength < m_messages.size() ? messagesLength : m_messages.size();
    return m_messagesLength == messagesLength;
}

void BuzzMessagesDTO::setMessages(const BuzzMessage* messages, uint16_t messagesLength) {
    setRawMessagesLength(messagesLength);
    for (uint16_t i = 0; i < m_messagesLength; i++) {
        m_messages[i] = BuzzMessageDTO(messages[i]);
    }
}

void BuzzMessagesDTO::setMessages(const BuzzMessageDTO* messages, uint16_t messagesLength) {
    setRawMessagesLength(messagesLength);
    for (uint16_t i = 0; i < m_messagesLength; i++) {
        m_messages[i] = messages[i];
    }
}

bool BuzzMessagesDTO::appendMessage(const BuzzMessageDTO& message) {

    uint16_t idx = m_messagesLength;
    if (setRawMessagesLength(m_messagesLength + 1)) {
        m_messages[idx] = message;
        return true;
    }
    return false;
}

bool BuzzMessagesDTO::serialize(BuzzMessages& msg) const {
    msg.messages_count = m_messagesLength;
    for (uint16_t i = 0; i < m_messagesLength; i++) {
        if (!m_messages[i].serialize(msg.messages[i])) {
            return false;
        }
    }
    return true;
}

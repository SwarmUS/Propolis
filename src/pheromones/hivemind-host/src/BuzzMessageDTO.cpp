#include "BuzzMessageDTO.h"

BuzzMessageDTO::BuzzMessageDTO(const uint8_t* payload, uint16_t payloadLength) {
    setPayload(payload, payloadLength);
}

BuzzMessageDTO::BuzzMessageDTO(const BuzzMessage& msg) {
    setPayload(msg.payload.bytes, msg.payload.size);
}

uint16_t BuzzMessageDTO::getPayloadLength() const { return m_payloadLength; }

const std::array<uint8_t, BuzzMessageDTO::PAYLOAD_MAX_SIZE>& BuzzMessageDTO::getPayload() const {
    return m_payload;
}

void BuzzMessageDTO::setPayload(const uint8_t* payload, uint16_t payloadLength) {
    m_payloadLength = payloadLength < PAYLOAD_MAX_SIZE ? payloadLength : PAYLOAD_MAX_SIZE;
    for (uint16_t i = 0; i < m_payloadLength; i++) {
        m_payload[i] = payload[i];
    }
}

std::array<uint8_t, BuzzMessageDTO::PAYLOAD_MAX_SIZE>& BuzzMessageDTO::getRawPayload() {
    return m_payload;
}

bool BuzzMessageDTO::setRawPayloadLength(uint16_t payloadLength) {
    m_payloadLength = payloadLength < PAYLOAD_MAX_SIZE ? payloadLength : PAYLOAD_MAX_SIZE;
    return m_payloadLength == payloadLength;
}

bool BuzzMessageDTO::serialize(BuzzMessage& msg) const {
    msg.payload.size = m_payloadLength;

    for (uint16_t i = 0; i < m_payloadLength; i++) {
        msg.payload.bytes[i] = m_payload[i];
    }

    return true;
}

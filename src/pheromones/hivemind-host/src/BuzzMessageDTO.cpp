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
    memcpy(m_payload, payload, payloadLength);
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
    memcpy(msg.payload.bytes, m_payload, m_payloadLength);

    return true;
}

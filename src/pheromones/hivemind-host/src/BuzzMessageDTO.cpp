#include "BuzzMessageDTO.h"

BuzzMessageDTO::BuzzMessageDTO(const uint8_t* payload, uint16_t payloadLenght) {
    setPayload(payload, payloadLenght);
}

BuzzMessageDTO::BuzzMessageDTO(const BuzzMessage& msg) {
    setPayload(msg.payload.bytes, msg.payload.size);
}

uint16_t BuzzMessageDTO::getPayloadLength() { return m_payloadLength; }

void BuzzMessageDTO::setPayload(const uint8_t* payload, uint16_t payloadLenght) {
    m_payloadLength = payloadLenght < PAYLOAD_MAX_SIZE ? payloadLenght : PAYLOAD_MAX_SIZE;
    for (uint16_t i = 0; i < m_payloadLength; i++) {
        m_payload[i] = payload[i];
    }
}

bool BuzzMessageDTO::serialize(BuzzMessage& msg) const {
    msg.payload.size = m_payloadLength;

    for (uint16_t i = 0; i < m_payloadLength; i++) {
        msg.payload.bytes[i] = m_payload[i];
    }

    return true;
}

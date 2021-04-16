#include "BytesDTO.h"

BytesDTO::BytesDTO(const Bytes& bytes) :
    m_packetId(bytes.packet_id), m_packetNumber(bytes.packet_no), m_lastPacket(bytes.last_packet) {
    setPayload(bytes.payload.bytes, bytes.payload.size);
}

BytesDTO::BytesDTO(uint32_t byteReqId,
                   uint32_t packetNumber,
                   bool lastPacket,
                   uint8_t* payload,
                   uint16_t payloadLength) :
    m_packetId(byteReqId), m_packetNumber(packetNumber), m_lastPacket(lastPacket) {
    setPayload(payload, payloadLength);
}

uint32_t BytesDTO::getPacketId() const { return m_packetId; }

uint32_t BytesDTO::getPacketNumber() const { return m_packetNumber; }

bool BytesDTO::isLastPacket() const { return m_lastPacket; }

const std::array<uint8_t, BytesDTO::PAYLOAD_MAX_SIZE>& BytesDTO::getPayload() const {
    return m_payload;
}

std::array<uint8_t, BytesDTO::PAYLOAD_MAX_SIZE>& BytesDTO::getRawPayload() { return m_payload; }

uint16_t BytesDTO::getPayloadLength() const { return m_payloadLength; }

void BytesDTO::setPacketId(uint32_t packetId) { m_packetId = packetId; }

void BytesDTO::setNumberId(uint32_t packetNumber) { m_packetNumber = packetNumber; }

void BytesDTO::setLastPacket(bool lastPacket) { m_lastPacket = lastPacket; }

bool BytesDTO::setRawPayloadLength(uint16_t payloadLength) {
    m_payloadLength = payloadLength < m_payload.size() ? payloadLength : m_payload.size();
    return m_payloadLength == payloadLength;
}

void BytesDTO::setPayload(const uint8_t* payload, uint16_t payloadLength) {
    setRawPayloadLength(payloadLength);
    memcpy(m_payload.data(), payload, m_payloadLength);
}

bool BytesDTO::serialize(Bytes& bytes) const {
    bytes.last_packet = m_lastPacket;
    bytes.packet_id = m_packetId;
    bytes.packet_no = m_packetNumber;
    bytes.payload.size = m_payloadLength;
    memcpy(bytes.payload.bytes, m_payload.data(), m_payloadLength);
    return true;
}

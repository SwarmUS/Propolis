#ifndef __BYTESDTO_H_
#define __BYTESDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class BytesDTO {
  public:
    static constexpr uint16_t PAYLOAD_MAX_SIZE = BYTES_PAYLOAD_SIZE;

    BytesDTO(const Bytes& bytes);

    BytesDTO(uint32_t byteReqId,
             uint32_t packetNumber,
             bool lastPacket,
             uint8_t* payload,
             uint16_t payloadLength);

    /**
     *@brief get the packet id, a packet id regroups multiple packet number and the receiver will
     *regroup the different packet number.
     *@return the packet id */
    uint32_t getPacketId() const;

    /**
     *@brief get the packet number, you can send multiple packet with contiguous number with one id
     *and the receiver will reappend thoses.
     *@return the packet number */
    uint32_t getPacketNumber() const;

    /**
     *@brief if the packet is the last one
     *@return a boolean, true if the last one, false if not*/
    bool isLastPacket() const;

    /**
     *@brief get the payload array
     *@return a ref to the payload array*/
    const std::array<uint8_t, PAYLOAD_MAX_SIZE>& getPayload() const;

    /**
     *@brief get the raw payload, not const. Can be used to write on it, call setRawPayloadLength
     *@return the raw value of the payload */
    std::array<uint8_t, PAYLOAD_MAX_SIZE>& getRawPayload();

    uint16_t getPayloadLength() const;

    /**
     *@brief set the packet id
     *@param [in] packetId the packet id*/
    void setPacketId(uint32_t packetId);

    /**
     *@brief set the packet number
     *@param [in] packetNumber the packet number*/
    void setNumberId(uint32_t packetNumber);

    /**
     *@brief set if the packet is the last one
     *@param [in] lastPacket if it's the last packet*/
    void setLastPacket(bool lastPacket);

    /**
     *@brief set the payload length after a write with the raw payload
     *@return true if the length is smaller than the max length, false otherwise*/
    bool setRawPayloadLength(uint16_t payloadLength);

    /**
     *@brief set the payload
     *@param [in] payload a pointer to the payload to set
     *@param [in] payloadLength the length of the provided payload*/
    void setPayload(const uint8_t* payload, uint16_t payloadLength);

    /**
     *@brief serialize a Bytes for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] bytes the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(Bytes& bytes) const;

  private:
    std::array<uint8_t, PAYLOAD_MAX_SIZE> m_payload;
    uint16_t m_payloadLength;
    uint32_t m_packetId;
    uint32_t m_packetNumber;
    bool m_lastPacket;
};

#endif // __BYTESDTO_H_

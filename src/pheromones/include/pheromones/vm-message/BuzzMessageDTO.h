#ifndef __BUZZMESSAGEDTO_H_
#define __BUZZMESSAGEDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class BuzzMessageDTO {
  public:
    static constexpr uint16_t PAYLOAD_MAX_SIZE = BUZZ_PAYLOAD_SIZE;

    BuzzMessageDTO();
    BuzzMessageDTO(const uint8_t* payload, uint16_t payloadLength);

    BuzzMessageDTO(const BuzzMessage& msg);

    /**
     *@brief get the payload length
     *@return the length of the payload*/
    uint16_t getPayloadLength() const;

    /**
     *@brief get the payload array
     *@return a ref to the payload array*/
    const std::array<uint8_t, PAYLOAD_MAX_SIZE>& getPayload() const;

    /**
     *@brief get the raw payload, not const. Can be used to write on it, call setRawPayloadLength
     *@return the raw value of the payload */
    std::array<uint8_t, PAYLOAD_MAX_SIZE>& getRawPayload();

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
     *@brief serialize a BuzzMessage for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] msg the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(BuzzMessage& msg) const;

  private:
    std::array<uint8_t, PAYLOAD_MAX_SIZE> m_payload;
    uint16_t m_payloadLength;
};

#endif // __BUZZMESSAGEDTO_H_

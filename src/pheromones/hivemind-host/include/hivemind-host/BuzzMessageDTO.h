#ifndef __BUZZMESSAGEDTO_H_
#define __BUZZMESSAGEDTO_H_

#include "hivemind-host/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class BuzzMessageDTO {
  public:
    static constexpr uint16_t PAYLOAD_MAX_SIZE = BUZZ_PAYLOAD_SIZE;

    BuzzMessageDTO(const uint8_t* payload, uint16_t payloadLenght);

    BuzzMessageDTO(const BuzzMessage& msg);

    /**
     *@brief get the payload length
     *@return the length of the payload*/
    uint16_t getPayloadLength();

    /**
     *@brief get the payload array
     *@return a ref to the payload array*/
    const std::array<uint8_t, PAYLOAD_MAX_SIZE>& getPayload();

    /**
     *@brief set the payload
     *@param [in] payload a pointer to the payload to set
     *@param [in] payloadLength the length of the provided payload*/
    void setPayload(const uint8_t* payload, uint16_t payloadLenght);

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

#ifndef __MESSAGEDTO_H_
#define __MESSAGEDTO_H_

#include "RequestDTO.h"
#include "ResponseDTO.h"
#include <cstdint>
#include <message.pb.h>
#include <variant>

class MessageDTO {
  public:
    MessageDTO() = default;

    MessageDTO(const Message& message);

    MessageDTO(uint32_t m_sourceId, uint32_t destinationId, const RequestDTO& request);

    MessageDTO(uint32_t m_sourceId, uint32_t destinationId, const ResponseDTO& response);

    /**
     *@brief gets the source id
     *
     *@return the source id
     */
    uint32_t getSourceId() const;

    /**
     *@brief gets the destination id
     *
     *@return the destination id
     */
    uint32_t getDestinationId() const;

    /**
     *@brief gets the message currently stored
     *
     *@return a reference to the stored message
     */
    const std::variant<std::monostate, RequestDTO, ResponseDTO>& getMessage() const;

    /**
     *@brief set the source id

     *@param [in] id the new id
     */
    void setSourceId(uint32_t id);

    /**
     *@brief set the destination id

     *@param [in] id the new id
     */
    void setDestinationId(uint32_t id);

    /**
     *@brief set the message type

     *@param [in] message the type of message to set
     */
    void setMessage(const std::variant<std::monostate, RequestDTO, ResponseDTO>& message);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] message the message to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(Message& message) const;

  private:
    uint32_t m_sourceId;

    uint32_t m_destinationId;

    std::variant<std::monostate, RequestDTO, ResponseDTO> m_message;
};

#endif // __MESSAGEDTO_H_

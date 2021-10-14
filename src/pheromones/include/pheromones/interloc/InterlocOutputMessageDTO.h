#ifndef __INTERLOCOUTPUTMESSAGEDTO_H__
#define __INTERLOCOUTPUTMESSAGEDTO_H__

#include "InterlocDumpDTO.h"
#include "InterlocRawAngleDataDTO.h"
#include "InterlocStateChangeDTO.h"
#include <message.pb.h>
#include <variant>

class InterlocOutputMessageDTO {
  public:
    InterlocOutputMessageDTO(const InterlocOutputMessage& message);
    InterlocOutputMessageDTO(const InterlocStateChangeDTO& message);
    InterlocOutputMessageDTO(const InterlocRawAngleDataDTO& message);
    InterlocOutputMessageDTO(const InterlocDumpDTO& message);

    /**
     * Gives the specific output message contained in the DTO
     * @return Output Message
     */
    const std::
        variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO, InterlocDumpDTO>&
        getMessage() const;

    /**
     * Sets the message to be contained in the serialized protobuf stream
     * @param message Output Message
     */
    void setMessage(const std::variant<std::monostate,
                                       InterlocStateChangeDTO,
                                       InterlocRawAngleDataDTO,
                                       InterlocDumpDTO>& message);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocOutputMessage& message) const;

  private:
    std::variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO, InterlocDumpDTO>
        m_message;
};

#endif //__INTERLOCOUTPUTMESSAGEDTO_H__

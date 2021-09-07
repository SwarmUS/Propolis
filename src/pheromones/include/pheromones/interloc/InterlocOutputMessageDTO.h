#ifndef __INTERLOCOUTPUTMESSAGEDTO_H__
#define __INTERLOCOUTPUTMESSAGEDTO_H__

#include "InterlocRawAngleDataDTO.h"
#include "InterlocStateChangeDTO.h"
#include <message.pb.h>
#include <variant>

class InterlocOutputMessageDTO {
  public:
    InterlocOutputMessageDTO(const InterlocOutputMessage& message);
    InterlocOutputMessageDTO(const InterlocStateChangeDTO& message);
    InterlocOutputMessageDTO(const InterlocRawAngleDataDTO& message);

    const std::variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO>&
    getMessage() const;

    void setMessage(
        const std::variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO>&
            message);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocOutputMessage& message) const;

  private:
    std::variant<std::monostate, InterlocStateChangeDTO, InterlocRawAngleDataDTO> m_message;
};

#endif //__INTERLOCOUTPUTMESSAGEDTO_H__

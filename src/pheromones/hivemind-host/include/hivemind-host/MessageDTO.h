#ifndef __MESSAGEDTO_H_
#define __MESSAGEDTO_H_

#include "RequestDTO.h"
#include <cstdint>
#include <message.pb.h>
#include <variant>

class MessageDTO {
  public:
    MessageDTO(const Message& message);

    MessageDTO(uint32_t m_sourceId, uint32_t m_destinationiId, const RequestDTO& request);

    bool serialize(Message& message) const;

    const std::variant<std::monostate, RequestDTO>& getMessage() const;

    uint32_t m_sourceId;

    uint32_t m_destinationId;

    std::variant<std::monostate, RequestDTO> m_message;
};

#endif // __MESSAGEDTO_H_

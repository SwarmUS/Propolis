#ifndef __MESSAGEDTO_H_
#define __MESSAGEDTO_H_

#include "RequestDTO.h"
#include <cstdint>
#include <message.pb.h>
#include <variant>

class MessageDTO {
  public:
    MessageDTO(const Message& message);

  private:
    uint32_t m_sourceId;

    uint32_t m_destinationId;

    std::variant<std::monostate, RequestDTO> m_message;
};

#endif // __MESSAGEDTO_H_

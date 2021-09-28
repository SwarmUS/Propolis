#ifndef VMMESSAGEDTO_H_
#define VMMESSAGEDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <message.pb.h>
#include <pheromones/vm-message/BuzzMessagesDTO.h>
#include <variant>

class VmMessageDTO {
  public:
    VmMessageDTO(const VmMessage message);
    VmMessageDTO(const BuzzMessagesDTO& message);

    /**@brief Gets the vm message*/
    const std::variant<std::monostate, BuzzMessagesDTO>& getMessage() const;

    /**@brief sets the vm message*/
    void setMessage(std::variant<std::monostate, BuzzMessagesDTO>& message);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] The message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(VmMessage& message) const;

  private:
    std::variant<std::monostate, BuzzMessagesDTO> m_message;
};

#endif // VMMESSAGEDTO_H_

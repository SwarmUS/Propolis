#ifndef __INTERLOCAPIDTO_H__
#define __INTERLOCAPIDTO_H__

#include "InterlocConfigurationDTO.h"
#include "InterlocOutputMessageDTO.h"
#include "SetInterlocStateDTO.h"
#include <message.pb.h>

class InterlocAPIDTO {
  public:
    InterlocAPIDTO(const InterlocAPI& message);
    InterlocAPIDTO(const SetInterlocStateDTO& setStateMessage);
    InterlocAPIDTO(const InterlocConfigurationDTO& interlocConfig);
    InterlocAPIDTO(const InterlocOutputMessageDTO& interlocOutputMsg);

    /**
     * @brief Gets the API call
     * @return API call
     */
    const std::variant<std::monostate,
                       SetInterlocStateDTO,
                       InterlocConfigurationDTO,
                       InterlocOutputMessageDTO>&
    getAPICall() const;

    /**
     * @brief Sets the API call
     * @param apiCall API call
     */
    void setAPICall(std::variant<std::monostate,
                                 SetInterlocStateDTO,
                                 InterlocConfigurationDTO,
                                 InterlocOutputMessageDTO>& apiCall);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] The message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(InterlocAPI& message) const;

  private:
    std::variant<std::monostate,
                 SetInterlocStateDTO,
                 InterlocConfigurationDTO,
                 InterlocOutputMessageDTO>
        m_apiCall;
};

#endif //__INTERLOCAPIDTO_H__

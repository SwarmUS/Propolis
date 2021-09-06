#ifndef __INTERLOCAPIDTO_H__
#define __INTERLOCAPIDTO_H__

#include <message.pb.h>

class InterlocAPIDTO {
  public:
    InterlocAPIDTO(const InterlocAPI& message);
    // InterlocAPIDTO(const CalibrationMessageDTO& calibrationMessage);

    //    /**
    //     * @brief Gets the API call
    //     * @return API call
    //     */
    //    const std::variant<std::monostate, CalibrationMessageDTO>& getAPICall() const;
    //
    //    /**
    //     * @brief Sets the API call
    //     * @param apiCall API call
    //     */
    //    void setAPICall(std::variant<std::monostate, CalibrationMessageDTO>& apiCall);
    //
    /**
     * @brief Serializes to a protobuf message
     * @param message [out] The message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(InterlocAPI& message) const;
    //
    //  private:
    //    std::variant<std::monostate, CalibrationMessageDTO> m_apiCall;
};

#endif //__INTERLOCAPIDTO_H__

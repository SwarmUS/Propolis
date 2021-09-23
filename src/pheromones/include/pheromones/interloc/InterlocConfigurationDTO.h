#ifndef __INTERLOCCONFIGURATIONDTO_H__
#define __INTERLOCCONFIGURATIONDTO_H__

#include "ConfigureAngleCalibrationDTO.h"
#include "ConfigureTWRCalibrationDTO.h"
#include <message.pb.h>
#include <variant>

/**
 * @brief Class representing an Interloc Configuration Message. (Can only be deserialized as these
 * are input messages not sent via Propolis)
 */
class InterlocConfigurationDTO {
  public:
    InterlocConfigurationDTO(const InterlocConfiguration& message);
    InterlocConfigurationDTO(const ConfigureAngleCalibrationDTO& configureDTO);
    InterlocConfigurationDTO(const ConfigureTWRCalibrationDTO& configureDTO);

    /**
     * @brief Returns the inner configuration message
     * @return The configuration message
     */
    const std::variant<std::monostate, ConfigureAngleCalibrationDTO, ConfigureTWRCalibrationDTO>&
    getConfigurationMessage() const;

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocConfiguration& message) const;

  private:
    std::variant<std::monostate, ConfigureAngleCalibrationDTO, ConfigureTWRCalibrationDTO>
        m_configMessage;
};

#endif //__INTERLOCCONFIGURATIONDTO_H__

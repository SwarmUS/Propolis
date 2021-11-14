#include <interloc/InterlocConfigurationDTO.h>
#include <message.pb.h>

InterlocConfigurationDTO::InterlocConfigurationDTO(const InterlocConfiguration& message) {
    switch (message.which_configurationMessage) {

    case InterlocConfiguration_configureAngleCalibration_tag:
        m_configMessage =
            ConfigureAngleCalibrationDTO(message.configurationMessage.configureAngleCalibration);
        break;

    case InterlocConfiguration_configureTWRCalibration_tag:
        m_configMessage =
            ConfigureTWRCalibrationDTO(message.configurationMessage.configureTWRCalibration);
        break;

    case InterlocConfiguration_configureInterlocDumps_tag:
        m_configMessage =
            ConfigureInterlocDumpsDTO(message.configurationMessage.configureInterlocDumps);
        break;

    case InterlocConfiguration_configureAngleParameters_tag:
        m_configMessage =
            ConfigureAngleParametersDTO(message.configurationMessage.configureAngleParameters);
        break;

    default:
        m_configMessage = std::monostate();
    }
}

InterlocConfigurationDTO::InterlocConfigurationDTO(
    const ConfigureAngleCalibrationDTO& configureDTO) {
    m_configMessage = configureDTO;
}

InterlocConfigurationDTO::InterlocConfigurationDTO(const ConfigureTWRCalibrationDTO& configureDTO) {
    m_configMessage = configureDTO;
}

InterlocConfigurationDTO::InterlocConfigurationDTO(const ConfigureInterlocDumpsDTO& configureDTO) {
    m_configMessage = configureDTO;
}

InterlocConfigurationDTO::InterlocConfigurationDTO(
    const ConfigureAngleParametersDTO& configureDTO) {
    m_configMessage = configureDTO;
}

const std::variant<std::monostate,
                   ConfigureAngleCalibrationDTO,
                   ConfigureTWRCalibrationDTO,
                   ConfigureInterlocDumpsDTO,
                   ConfigureAngleParametersDTO>&
InterlocConfigurationDTO::getConfigurationMessage() const {
    return m_configMessage;
}

bool InterlocConfigurationDTO::serialize(InterlocConfiguration& message) const {
    if (const auto* configMessage = std::get_if<ConfigureAngleCalibrationDTO>(&m_configMessage)) {
        message.which_configurationMessage = InterlocConfiguration_configureAngleCalibration_tag;
        return configMessage->serialize(message.configurationMessage.configureAngleCalibration);
    }

    if (const auto* configMessage = std::get_if<ConfigureTWRCalibrationDTO>(&m_configMessage)) {
        message.which_configurationMessage = InterlocConfiguration_configureTWRCalibration_tag;
        return configMessage->serialize(message.configurationMessage.configureTWRCalibration);
    }

    if (const auto* configMessage = std::get_if<ConfigureInterlocDumpsDTO>(&m_configMessage)) {
        message.which_configurationMessage = InterlocConfiguration_configureInterlocDumps_tag;
        return configMessage->serialize(message.configurationMessage.configureInterlocDumps);
    }

    if (const auto* configMessage = std::get_if<ConfigureAngleParametersDTO>(&m_configMessage)) {
        message.which_configurationMessage = InterlocConfiguration_configureAngleParameters_tag;
        return configMessage->serialize(message.configurationMessage.configureAngleParameters);
    }

    return false;
}

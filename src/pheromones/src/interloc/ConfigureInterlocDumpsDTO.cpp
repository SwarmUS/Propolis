#include "interloc/ConfigureInterlocDumpsDTO.h"
#include <message.pb.h>

ConfigureInterlocDumpsDTO::ConfigureInterlocDumpsDTO(const ConfigureInterlocDumps& message) {
    m_enabled = message.enable;
}

ConfigureInterlocDumpsDTO::ConfigureInterlocDumpsDTO(bool enabled) { m_enabled = enabled; }

bool ConfigureInterlocDumpsDTO::getEnabled() const { return m_enabled; }

void ConfigureInterlocDumpsDTO::setEnabled(bool enabled) { m_enabled = enabled; }

bool ConfigureInterlocDumpsDTO::serialize(ConfigureInterlocDumps& message) const {
    message.enable = m_enabled;
    return true;
}

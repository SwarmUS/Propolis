#include "interloc/ConfigureAngleParametersDTO.h"

ConfigureAngleParametersDTO::ConfigureAngleParametersDTO(const ConfigureAngleParameters& message) {
    m_pairId = message.anglePairId;

    m_antennasLength = message.antennas_count;
    for (unsigned int i = 0; i < message.antennas_count; i++) {
        m_antennas[i] = message.antennas[i];
    }

    m_slopeDecisionLength = message.slopeDecision_count;
    for (unsigned int i = 0; i < message.slopeDecision_count; i++) {
        m_slopeDecision[i] = message.slopeDecision[i];
    }

    m_tdoaNormalizationFactor = message.tdoaNormalizationFactor;
    m_tdoaSlopesLength = message.tdoaSlopes_count;
    for (unsigned int i = 0; i < message.tdoaSlopes_count; i++) {
        m_tdoaSlopes[i] = message.tdoaSlopes[i];
    }
    m_tdoaInterceptsLength = message.tdoaIntercepts_count;
    for (unsigned int i = 0; i < message.tdoaIntercepts_count; i++) {
        m_tdoaIntercepts[i] = message.tdoaIntercepts[i];
    }

    m_pdoaNormalizationFactor = message.pdoaNormalizationFactor;
    m_pdoaSlope = message.pdoaSlope;
    m_pdoaInterceptsLength = message.pdoaIntercepts_count;
    for (unsigned int i = 0; i < message.pdoaIntercepts_count; i++) {
        m_pdoaIntercepts[i] = message.pdoaIntercepts[i];
    }
    m_pdoaOriginsLength = message.pdoaOrigins_count;
    for (unsigned int i = 0; i < message.pdoaOrigins_count; i++) {
        m_pdoaOrigins[i] = message.pdoaOrigins[i];
    }
}

bool ConfigureAngleParametersDTO::serialize(ConfigureAngleParameters& message) const {
    (void)message;

    // Prevent clang from requesting static method
    (void)m_pdoaOrigins;

    // Should never be called
    return false;
}

uint8_t ConfigureAngleParametersDTO::getPairId() const { return m_pairId; }

const std::array<uint8_t, INTERLOC_ANTENNAS_PER_PAIR>& ConfigureAngleParametersDTO::getAntennas()
    const {
    return m_antennas;
}

uint8_t ConfigureAngleParametersDTO::getAntennasLength() const { return m_antennasLength; }

const std::array<uint8_t, INTERLOC_MAX_ANTENNA_PAIRS>& ConfigureAngleParametersDTO::
    getSlopeDecision() const {
    return m_slopeDecision;
}

uint8_t ConfigureAngleParametersDTO::getSlopeDecisionLength() const {
    return m_slopeDecisionLength;
}

float ConfigureAngleParametersDTO::getTdoaNormalizationFactor() const {
    return m_tdoaNormalizationFactor;
}

const std::array<float, INTERLOC_MAX_TDOA_SLOPES>& ConfigureAngleParametersDTO::getTdoaSlopes()
    const {
    return m_tdoaSlopes;
}

uint8_t ConfigureAngleParametersDTO::getTdoaSlopesLength() const { return m_tdoaSlopesLength; }

const std::array<float, INTERLOC_MAX_TDOA_SLOPES>& ConfigureAngleParametersDTO::getTdoaIntercepts()
    const {
    return m_tdoaIntercepts;
}

uint8_t ConfigureAngleParametersDTO::getTdoaInterceptsLength() const {
    return m_tdoaInterceptsLength;
}

float ConfigureAngleParametersDTO::getPdoaNormalizationFactor() const {
    return m_pdoaNormalizationFactor;
}

float ConfigureAngleParametersDTO::getPdoaSlope() const { return m_pdoaSlope; }

const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& ConfigureAngleParametersDTO::getPdoaIntercepts()
    const {
    return m_pdoaIntercepts;
}

uint8_t ConfigureAngleParametersDTO::getPdoaInterceptsLength() const {
    return m_pdoaInterceptsLength;
}

const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& ConfigureAngleParametersDTO::getPdoaOrigins()
    const {
    return m_pdoaOrigins;
}

uint8_t ConfigureAngleParametersDTO::getPdoaOriginsLength() const { return m_pdoaOriginsLength; }

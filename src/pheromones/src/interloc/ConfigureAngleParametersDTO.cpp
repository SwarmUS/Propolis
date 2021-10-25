#include "interloc/ConfigureAngleParametersDTO.h"

ConfigureAngleParametersDTO::ConfigureAngleParametersDTO(const ConfigureAngleParameters& message) {
    m_pairId = message.anglePairId;

    m_antennasLength =
        message.antennas_count <= INTERLOC_ANTENNAS_PER_PAIR ? message.antennas_count : 0;
    for (unsigned int i = 0; i < m_antennasLength; i++) {
        m_antennas[i] = message.antennas[i];
    }

    m_slopeDecisionLength =
        message.slopeDecision_count <= INTERLOC_MAX_ANTENNA_PAIRS ? message.slopeDecision_count : 0;
    for (unsigned int i = 0; i < m_slopeDecisionLength; i++) {
        m_slopeDecision[i] = message.slopeDecision[i];
    }

    m_tdoaNormalizationFactor = message.tdoaNormalizationFactor;
    m_tdoaSlopesLength =
        message.tdoaSlopes_count <= INTERLOC_MAX_TDOA_SLOPES ? message.tdoaSlopes_count : 0;
    for (unsigned int i = 0; i < m_tdoaSlopesLength; i++) {
        m_tdoaSlopes[i] = message.tdoaSlopes[i];
    }
    m_tdoaInterceptsLength =
        message.tdoaIntercepts_count <= INTERLOC_MAX_TDOA_SLOPES ? message.tdoaIntercepts_count : 0;
    for (unsigned int i = 0; i < m_tdoaInterceptsLength; i++) {
        m_tdoaIntercepts[i] = message.tdoaIntercepts[i];
    }

    m_pdoaNormalizationFactor = message.pdoaNormalizationFactor;
    m_pdoaSlope = message.pdoaSlope;
    m_pdoaInterceptsLength =
        message.pdoaIntercepts_count <= INTERLOC_MAX_PDOA_SLOPES ? message.pdoaIntercepts_count : 0;
    for (unsigned int i = 0; i < m_pdoaInterceptsLength; i++) {
        m_pdoaIntercepts[i] = message.pdoaIntercepts[i];
    }
    m_pdoaOriginsLength =
        message.pdoaOrigins_count <= INTERLOC_MAX_PDOA_SLOPES ? message.pdoaOrigins_count : 0;
    for (unsigned int i = 0; i < m_pdoaOriginsLength; i++) {
        m_pdoaOrigins[i] = message.pdoaOrigins[i];
    }
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

bool ConfigureAngleParametersDTO::serialize(ConfigureAngleParameters& message) const {
    message.anglePairId = m_pairId;

    message.antennas_count = m_antennasLength;
    for (unsigned int i = 0; i < m_antennasLength; i++) {
        message.antennas[i] = m_antennas[i];
    }

    message.slopeDecision_count = m_slopeDecisionLength;
    for (unsigned int i = 0; i < m_slopeDecisionLength; i++) {
        message.slopeDecision[i] = m_slopeDecision[i];
    }

    message.tdoaNormalizationFactor = m_tdoaNormalizationFactor;
    message.tdoaSlopes_count = m_tdoaSlopesLength;
    for (unsigned int i = 0; i < m_tdoaSlopesLength; i++) {
        message.tdoaSlopes[i] = m_tdoaSlopes[i];
    }
    message.tdoaIntercepts_count = m_tdoaInterceptsLength;
    for (unsigned int i = 0; i < m_tdoaInterceptsLength; i++) {
        message.tdoaIntercepts[i] = m_tdoaIntercepts[i];
    }

    message.pdoaNormalizationFactor = m_pdoaNormalizationFactor;
    message.pdoaSlope = m_pdoaSlope;
    message.pdoaIntercepts_count = m_pdoaInterceptsLength;
    for (unsigned int i = 0; i < m_pdoaInterceptsLength; i++) {
        message.pdoaIntercepts[i] = m_pdoaIntercepts[i];
    }
    message.pdoaOrigins_count = m_pdoaOriginsLength;
    for (unsigned int i = 0; i < m_pdoaOriginsLength; i++) {
        message.pdoaOrigins[i] = m_pdoaOrigins[i];
    }

    return true;
}
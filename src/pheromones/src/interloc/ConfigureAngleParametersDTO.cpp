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

    m_pdoaSlopesLength =
        message.pdoaSlopes_count <= INTERLOC_MAX_PDOA_SLOPES ? message.pdoaSlopes_count : 0;
    for (unsigned int i = 0; i < m_pdoaSlopesLength; i++) {
        m_pdoaSlopes[i] = message.pdoaSlopes[i];
    }
    m_pdoaInterceptsLength =
        message.pdoaIntercepts_count <= INTERLOC_MAX_PDOA_SLOPES ? message.pdoaIntercepts_count : 0;
    for (unsigned int i = 0; i < m_pdoaInterceptsLength; i++) {
        m_pdoaIntercepts[i] = message.pdoaIntercepts[i];
    }

    m_pdoaNormalizationFactor = message.pdoaNormalizationFactor;
    m_boardOientationOffset = message.boardOrientationOffset;
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

const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& ConfigureAngleParametersDTO::getPdoaSlopes()
    const {
    return m_pdoaSlopes;
}

uint8_t ConfigureAngleParametersDTO::getPdoaSlopesLength() const { return m_pdoaSlopesLength; }

float ConfigureAngleParametersDTO::getPdoaNormalizationFactor() const {
    return m_pdoaNormalizationFactor;
}

uint8_t ConfigureAngleParametersDTO::getPdoaInterceptsLength() const {
    return m_pdoaInterceptsLength;
}

const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& ConfigureAngleParametersDTO::getPdoaIntercepts()
    const {
    return m_pdoaIntercepts;
}

float ConfigureAngleParametersDTO::getBoardOrientationOffset() const {
    return m_boardOientationOffset;
}

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

    message.pdoaSlopes_count = m_pdoaSlopesLength;
    for (unsigned int i = 0; i < m_pdoaSlopesLength; i++) {
        message.pdoaSlopes[i] = m_pdoaSlopes[i];
    }
    message.pdoaNormalizationFactor = m_pdoaNormalizationFactor;
    message.pdoaIntercepts_count = m_pdoaInterceptsLength;
    for (unsigned int i = 0; i < m_pdoaInterceptsLength; i++) {
        message.pdoaIntercepts[i] = m_pdoaIntercepts[i];
    }

    message.boardOrientationOffset = m_boardOientationOffset;

    return true;
}
#ifndef __CONFIGUREANGLEPARAMETERSDTO_H__
#define __CONFIGUREANGLEPARAMETERSDTO_H__

#include <array>
#include <cstdint>
#include <message.pb.h>
#include <pheromones/PheromonesSettings.h>

class ConfigureAngleParametersDTO {
  public:
    ConfigureAngleParametersDTO(const ConfigureAngleParameters& message);

    uint8_t getPairId() const;
    const std::array<uint8_t, INTERLOC_ANTENNAS_PER_PAIR>& getAntennas() const;
    uint8_t getAntennasLength() const;
    const std::array<uint8_t, INTERLOC_MAX_ANTENNA_PAIRS>& getSlopeDecision() const;
    uint8_t getSlopeDecisionLength() const;
    float getTdoaNormalizationFactor() const;
    const std::array<float, INTERLOC_MAX_TDOA_SLOPES>& getTdoaSlopes() const;
    uint8_t getTdoaSlopesLength() const;
    const std::array<float, INTERLOC_MAX_TDOA_SLOPES>& getTdoaIntercepts() const;
    uint8_t getTdoaInterceptsLength() const;
    float getPdoaNormalizationFactor() const;
    float getPdoaSlope() const;
    const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& getPdoaIntercepts() const;
    uint8_t getPdoaInterceptsLength() const;
    const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& getPdoaOrigins() const;
    uint8_t getPdoaOriginsLength() const;

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(ConfigureAngleParameters& message) const;

  private:
    uint8_t m_pairId;

    std::array<uint8_t, INTERLOC_ANTENNAS_PER_PAIR> m_antennas;
    uint8_t m_antennasLength;
    std::array<uint8_t, INTERLOC_MAX_ANTENNA_PAIRS> m_slopeDecision;
    uint8_t m_slopeDecisionLength;

    float m_tdoaNormalizationFactor;
    std::array<float, INTERLOC_MAX_TDOA_SLOPES> m_tdoaSlopes;
    uint8_t m_tdoaSlopesLength;
    std::array<float, INTERLOC_MAX_TDOA_SLOPES> m_tdoaIntercepts;
    uint8_t m_tdoaInterceptsLength;

    float m_pdoaNormalizationFactor;
    float m_pdoaSlope;
    std::array<float, INTERLOC_MAX_PDOA_SLOPES> m_pdoaIntercepts;
    uint8_t m_pdoaInterceptsLength;
    std::array<float, INTERLOC_MAX_PDOA_SLOPES> m_pdoaOrigins;
    uint8_t m_pdoaOriginsLength;
};

#endif //__CONFIGUREANGLEPARAMETERSDTO_H__

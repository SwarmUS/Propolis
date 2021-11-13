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

    const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& getPdoaSlopes() const;
    uint8_t getPdoaSlopesLength() const;

    const std::array<float, INTERLOC_MAX_PDOA_SLOPES>& getPdoaIntercepts() const;
    uint8_t getPdoaInterceptsLength() const;

    float getPdoaNormalizationFactor() const;

    float getBoardOrientationOffset() const;

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

    std::array<float, INTERLOC_MAX_PDOA_SLOPES> m_pdoaSlopes;
    uint8_t m_pdoaSlopesLength;
    std::array<float, INTERLOC_MAX_PDOA_SLOPES> m_pdoaIntercepts;
    uint8_t m_pdoaInterceptsLength;
    float m_pdoaNormalizationFactor;

    float m_boardOientationOffset;
};

#endif //__CONFIGUREANGLEPARAMETERSDTO_H__

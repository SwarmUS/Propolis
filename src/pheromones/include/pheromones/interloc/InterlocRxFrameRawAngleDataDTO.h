#ifndef __INTERLOCRXFRAMERAWANGLEDATADTO_H__
#define __INTERLOCRXFRAMERAWANGLEDATADTO_H__

#include "InterlocRxFrameInfoDTO.h"
#include <array>
#include <cstdint>
#include <message.pb.h>
#include <pheromones/PheromonesSettings.h>

class InterlocRxFrameRawAngleDataDTO {
  public:
    static constexpr uint8_t INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH = INTERLOC_BEEBOARDS_SIZE;

    InterlocRxFrameRawAngleDataDTO(const InterlocRxFrameRawAngleData& message);
    InterlocRxFrameRawAngleDataDTO();
    InterlocRxFrameRawAngleDataDTO(uint32_t frameId,
                                   const InterlocRxFrameInfoDTO* frameInfos,
                                   uint8_t frameInfosLength);

    uint32_t getFrameId() const;
    uint8_t getFrameInfosLength() const;
    const std::array<InterlocRxFrameInfoDTO, INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH>& getFrameInfos()
        const;

    void setFrameId(uint32_t frameId);
    void setFrameInfos(const InterlocRxFrameInfoDTO* frameInfos, uint8_t frameInfosLength);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocRxFrameRawAngleData& message) const;

  private:
    uint32_t m_frameId;
    uint8_t m_frameInfosLength;
    std::array<InterlocRxFrameInfoDTO, INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH> m_frameInfos;
};

#endif //__INTERLOCRXFRAMERAWANGLEDATADTO_H__

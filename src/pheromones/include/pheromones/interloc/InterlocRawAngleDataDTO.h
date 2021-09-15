#ifndef __INTERLOCRAWANGLEDATADTO_H__
#define __INTERLOCRAWANGLEDATADTO_H__

#include "InterlocRxFrameRawAngleDataDTO.h"
#include <array>
#include <message.pb.h>
#include <pheromones/PheromonesSettings.h>

class InterlocRawAngleDataDTO {
  public:
    static constexpr uint8_t INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE = INTERLOC_RAW_ANGLE_FRAMES_SIZE;

    InterlocRawAngleDataDTO();
    InterlocRawAngleDataDTO(const InterlocRawAngleData& message);
    InterlocRawAngleDataDTO(const InterlocRxFrameRawAngleDataDTO* frames, uint8_t framesLength);

    uint8_t getFramesLength() const;
    std::array<InterlocRxFrameRawAngleDataDTO, INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE>& getFrames();

    void setFrames(const InterlocRxFrameRawAngleDataDTO* frames, uint8_t framesLength);
    void setFramesLength(uint8_t framesLength);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocRawAngleData& message) const;

  private:
    uint8_t m_frameLength;
    std::array<InterlocRxFrameRawAngleDataDTO, INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE> m_frames;
};

#endif //__INTERLOCRAWANGLEDATADTO_H__

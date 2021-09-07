#include <interloc/InterlocRawAngleDataDTO.h>

InterlocRawAngleDataDTO::InterlocRawAngleDataDTO(const InterlocRawAngleData& message) {
    m_frameLength = message.frames_count;
    for (uint8_t i = 0; i < m_frameLength; i++) {
        m_frames[i] = InterlocRxFrameRawAngleDataDTO(message.frames[i]);
    }
}

InterlocRawAngleDataDTO::InterlocRawAngleDataDTO(const InterlocRxFrameRawAngleDataDTO* frames,
                                                 uint8_t framesLength) {
    setFrames(frames, framesLength);
}
void InterlocRawAngleDataDTO::setFrames(const InterlocRxFrameRawAngleDataDTO* frames,
                                        uint8_t framesLength) {
    m_frameLength = framesLength < INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE
                        ? framesLength
                        : INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE;

    for (uint8_t i = 0; i < m_frameLength; i++) {
        m_frames[i] = frames[i];
    }
}

bool InterlocRawAngleDataDTO::serialize(InterlocRawAngleData& message) const {
    message.frames_count = m_frameLength;

    for (uint8_t i = 0; i < m_frameLength; i++) {
        if (!m_frames[i].serialize(message.frames[i])) {
            return false;
        }
    }

    return true;
}

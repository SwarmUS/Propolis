#include <interloc/InterlocRawAngleDataDTO.h>

InterlocRawAngleDataDTO::InterlocRawAngleDataDTO() { m_frameLength = 0; }

InterlocRawAngleDataDTO::InterlocRawAngleDataDTO(const InterlocRawAngleData& message) {
    // If frames_count is bigger than maximum size, there was a problem in the transmission, so
    // just discard all data
    m_frameLength =
        message.frames_count <= INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE ? message.frames_count : 0;

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

        // Deep copy
        m_frames[i].setFrameInfos(frames[i].getFrameInfos().data(),
                                  frames[i].getFrameInfosLength());
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

uint8_t InterlocRawAngleDataDTO::getFramesLength() const { return m_frameLength; }

const std::array<InterlocRxFrameRawAngleDataDTO,
                 InterlocRawAngleDataDTO::INTERLOC_RAW_ANGLE_FRAMES_MAX_SIZE>&
InterlocRawAngleDataDTO::getFrames() const {
    return m_frames;
}

#include <interloc/InterlocRxFrameRawAngleDataDTO.h>
#include <message.pb.h>

InterlocRxFrameRawAngleDataDTO::InterlocRxFrameRawAngleDataDTO(
    const InterlocRxFrameRawAngleData& message) {
    m_frameId = message.frameId;
    m_frameInfosLength = message.frameInfos_count;

    for (uint8_t i = 0; i < m_frameInfosLength; i++) {
        m_frameInfos[i] = InterlocRxFrameInfoDTO(message.frameInfos[i]);
    }
}

InterlocRxFrameRawAngleDataDTO::InterlocRxFrameRawAngleDataDTO() {
    m_frameId = 0;
    m_frameInfosLength = 0;
}

InterlocRxFrameRawAngleDataDTO::InterlocRxFrameRawAngleDataDTO(
    uint32_t frameId, const InterlocRxFrameInfoDTO* frameInfos, uint8_t frameInfosLength) {
    m_frameId = frameId;
    setFrameInfos(frameInfos, frameInfosLength);
}

void InterlocRxFrameRawAngleDataDTO::setFrameId(uint32_t frameId) { m_frameId = frameId; }

void InterlocRxFrameRawAngleDataDTO::setFrameInfos(const InterlocRxFrameInfoDTO* frameInfos,
                                                   uint8_t frameInfosLength) {
    m_frameInfosLength = frameInfosLength < INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH
                             ? frameInfosLength
                             : INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH;

    for (uint8_t i = 0; i < m_frameInfosLength; i++) {
        m_frameInfos[i] = frameInfos[i];
    }
}

bool InterlocRxFrameRawAngleDataDTO::serialize(InterlocRxFrameRawAngleData& message) const {
    message.frameId = m_frameId;
    message.frameInfos_count = m_frameInfosLength;

    for (uint8_t i = 0; i < m_frameInfosLength; i++) {
        if (!m_frameInfos[i].serialize(message.frameInfos[i])) {
            return false;
        }
    }

    return true;
}

uint32_t InterlocRxFrameRawAngleDataDTO::getFrameId() const { return m_frameId; }

uint8_t InterlocRxFrameRawAngleDataDTO::getFrameInfosLength() const { return m_frameInfosLength; }

const std::array<InterlocRxFrameInfoDTO,
                 InterlocRxFrameRawAngleDataDTO::INTERLOC_BEEBOARDS_SIZE_MAX_LENGTH>&
InterlocRxFrameRawAngleDataDTO::getFrameInfos() const {
    return m_frameInfos;
}

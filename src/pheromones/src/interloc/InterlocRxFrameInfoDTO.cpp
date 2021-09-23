#include <interloc/InterlocRxFrameInfoDTO.h>
#include <message.pb.h>

InterlocRxFrameInfoDTO::InterlocRxFrameInfoDTO(const InterlocRxFrameInfo& message) {
    m_beeboardPort = message.beeboardPort;
    m_rxTimestamp = message.rxTimestamp;
    m_sfdAngle = message.sfdAngle;
    m_accumulatorAngle = message.accumulatorAngle;
}

InterlocRxFrameInfoDTO::InterlocRxFrameInfoDTO() {
    m_beeboardPort = 0;
    m_rxTimestamp = 0;
    m_sfdAngle = 0;
    m_accumulatorAngle = 0;
}

void InterlocRxFrameInfoDTO::setBeeboardPort(uint32_t port) { m_beeboardPort = port; }

void InterlocRxFrameInfoDTO::setRxTimestamp(uint64_t timestamp) { m_rxTimestamp = timestamp; }

void InterlocRxFrameInfoDTO::setSfdAngle(float angle) { m_sfdAngle = angle; }

void InterlocRxFrameInfoDTO::setAccumulatorAngle(float angle) { m_accumulatorAngle = angle; }

uint32_t InterlocRxFrameInfoDTO::getBeeboardPort() const { return m_beeboardPort; }

uint64_t InterlocRxFrameInfoDTO::getRxTimestamp() const { return m_rxTimestamp; }

float InterlocRxFrameInfoDTO::getSfdAngle() const { return m_sfdAngle; }

float InterlocRxFrameInfoDTO::getAccumulatorAngle() const { return m_accumulatorAngle; }

bool InterlocRxFrameInfoDTO::serialize(InterlocRxFrameInfo& message) const {
    message.beeboardPort = m_beeboardPort;
    message.rxTimestamp = m_rxTimestamp;
    message.sfdAngle = m_sfdAngle;
    message.accumulatorAngle = m_accumulatorAngle;

    return true;
}

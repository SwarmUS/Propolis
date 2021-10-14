
#include <interloc/InterlocDumpDTO.h>

InterlocDumpDTO::InterlocDumpDTO(const InterlocDump& message) {
    // If positionUpdates_count is bigger than maximum size, there was a problem in the
    // transmission, so just discard all data
    m_updatesLength =
        message.positionUpdates_count <= MAX_UPDATES_SIZE ? message.positionUpdates_count : 0;

    for (uint8_t i = 0; i < m_updatesLength; i++) {
        m_updates[i] = GetNeighborResponseDTO(message.positionUpdates[i]);
    }
}

InterlocDumpDTO::InterlocDumpDTO(const GetNeighborResponseDTO* updates, uint8_t updatesLength) {
    setUpdates(updates, updatesLength);
}

uint8_t InterlocDumpDTO::getUpdatesLength() const { return m_updatesLength; }

const std::array<GetNeighborResponseDTO, InterlocDumpDTO::MAX_UPDATES_SIZE>& InterlocDumpDTO::
    getUpdates() const {
    return m_updates;
}

void InterlocDumpDTO::setUpdates(const GetNeighborResponseDTO* updates, uint8_t updatesLength) {
    m_updatesLength = updatesLength <= MAX_UPDATES_SIZE ? updatesLength : MAX_UPDATES_SIZE;

    for (uint8_t i = 0; i < m_updatesLength; i++) {
        m_updates[i] = updates[i];
    }
}

bool InterlocDumpDTO::serialize(InterlocDump& message) const {
    message.positionUpdates_count = m_updatesLength;

    for (uint8_t i = 0; i < m_updatesLength; i++) {
        if (!m_updates[i].serialize(message.positionUpdates[i])) {
            return false;
        }
    }

    return true;
}

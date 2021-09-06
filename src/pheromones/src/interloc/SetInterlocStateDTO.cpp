#include "interloc/SetInterlocStateDTO.h"

SetInterlocStateDTO::SetInterlocStateDTO(const SetInterlocState& message) {
    m_state = interlocStateToDTO(message.state);
}

SetInterlocStateDTO::SetInterlocStateDTO(InterlocStateDTO state) { m_state = state; }

InterlocStateDTO SetInterlocStateDTO::getState() const { return m_state; }

void SetInterlocStateDTO::setState(InterlocStateDTO state) { m_state = state; }

bool SetInterlocStateDTO::serialize(SetInterlocState& message) const {
    message.state = dtoToInterlocState(m_state);
    return true;
}

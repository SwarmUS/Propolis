#include "interloc/InterlocStateChangeDTO.h"

InterlocStateChangeDTO::InterlocStateChangeDTO(const InterlocStateChange& message) {
    m_previousState = interlocStateToDTO(message.previousState);
    m_newState = interlocStateToDTO(message.newState);
}

InterlocStateChangeDTO::InterlocStateChangeDTO(InterlocStateDTO previousState,
                                               InterlocStateDTO newState) {
    m_previousState = previousState;
    m_newState = newState;
}

InterlocStateDTO InterlocStateChangeDTO::getPreviousState() const { return m_previousState; }

InterlocStateDTO InterlocStateChangeDTO::getNewState() const { return m_newState; }

void InterlocStateChangeDTO::setPreviousState(InterlocStateDTO state) { m_previousState = state; }

void InterlocStateChangeDTO::setNewState(InterlocStateDTO state) { m_newState = state; }

bool InterlocStateChangeDTO::serialize(InterlocStateChange& message) {
    message.previousState = dtoToInterlocState(m_previousState);
    message.newState = dtoToInterlocState(m_newState);
    return true;
}

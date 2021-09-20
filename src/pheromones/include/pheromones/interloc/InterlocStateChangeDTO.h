#ifndef __INTERLOCSTATECHANGEDTO_H__
#define __INTERLOCSTATECHANGEDTO_H__

#include "InterlocStateDTO.h"
#include <message.pb.h>

/**
 * @brief Class representing an Interloc State Change message. Used to notify host when the global
 * interloc state machine changes states.
 */
class InterlocStateChangeDTO {
  public:
    InterlocStateChangeDTO(const InterlocStateChange& message);
    InterlocStateChangeDTO(InterlocStateDTO previousState, InterlocStateDTO newState);

    /**
     * Returns the previous state
     * @return State
     */
    InterlocStateDTO getPreviousState() const;

    /**
     * Returns the new state
     * @return State
     */
    InterlocStateDTO getNewState() const;

    /**
     * Sets the previous state
     * @param state State
     */
    void setPreviousState(InterlocStateDTO state);

    /**
     * Sets the new state
     * @param state State
     */
    void setNewState(InterlocStateDTO state);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocStateChange& message) const;

  private:
    InterlocStateDTO m_previousState;
    InterlocStateDTO m_newState;
};

#endif //__INTERLOCSTATECHANGEDTO_H__

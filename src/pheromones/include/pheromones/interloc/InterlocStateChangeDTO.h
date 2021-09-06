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

    InterlocStateDTO getPreviousState() const;
    InterlocStateDTO getNewState() const;

    void setPreviousState(InterlocStateDTO state);
    void setNewState(InterlocStateDTO state);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocStateChange& message);

  private:
    InterlocStateDTO m_previousState;
    InterlocStateDTO m_newState;
};

#endif //__INTERLOCSTATECHANGEDTO_H__

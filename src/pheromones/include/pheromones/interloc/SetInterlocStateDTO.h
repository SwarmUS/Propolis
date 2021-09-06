#ifndef __SETINTERLOCSTATEDTO_H__
#define __SETINTERLOCSTATEDTO_H__

#include "InterlocStateDTO.h"
#include <cstdint>
#include <message.pb.h>
#include <variant>

/**
 * @brief Class to represent a set interloc state message
 */
class SetInterlocStateDTO {
  public:
    SetInterlocStateDTO(const SetInterlocState& message);
    SetInterlocStateDTO(InterlocStateDTO state);

    /**
     * @brief Returns the state
     * @return state
     */
    InterlocStateDTO getState() const;

    /**
     * @brief Sets the state
     * @param state state
     */
    void setState(InterlocStateDTO state);

    /**
     *@brief serialize a SetInterlocState for nanopb, sets the fields properly before using
     *pb_encode
     *@param message the message to serialize
     *@return true if successful (fields were recognized) false if not */
    bool serialize(SetInterlocState& message) const;

  private:
    InterlocStateDTO m_state;
};

#endif //__SETINTERLOCSTATEDTO_H__

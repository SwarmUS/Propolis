#ifndef __CALIBRATIONMODEDTO_H__
#define __CALIBRATIONMODEDTO_H__

#include <message.pb.h>

enum class InterlocStateDTO {
    UNSUPPORTED,
    STANDBY,
    OPERATING,
    ANGLE_CALIB_SENDER,
    ANGLE_CALIB_RECEIVER,
    TWR_CALIB_INITIATOR,
    TWR_CALIB_RESPONDER
};

/**
 *@brief get the equivalent of a nanobp interloc state to a dto
 *
 *@return the dto equivalent
 **/
InterlocStateDTO interlocStateToDTO(InterlocState state);

/**
 *@brief get the equivalent of a dto interloc state to a nanopb one
 *
 *@return the nanopb equivalent
 **/
InterlocState dtoToInterlocState(InterlocStateDTO state);

#endif //__CALIBRATIONMODEDTO_H__

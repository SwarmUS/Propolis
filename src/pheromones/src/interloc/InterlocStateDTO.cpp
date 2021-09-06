#include "interloc/InterlocStateDTO.h"

InterlocStateDTO interlocStateToDTO(InterlocState state) {
    switch (state) {
    case InterlocState_STANDBY:
        return InterlocStateDTO::STANDBY;

    case InterlocState_OPERATING:
        return InterlocStateDTO::OPERATING;

    case InterlocState_ANGLE_CALIB_SENDER:
        return InterlocStateDTO::ANGLE_CALIB_SENDER;

    case InterlocState_ANGLE_CALIB_RECEIVER:
        return InterlocStateDTO::ANGLE_CALIB_RECEIVER;

    case InterlocState_TWR_CALIB_INITIATOR:
        return InterlocStateDTO::TWR_CALIB_INITIATOR;

    case InterlocState_TWR_CALIB_RESPONDER:
        return InterlocStateDTO::TWR_CALIB_RESPONDER;

    default:
        return InterlocStateDTO::UNSUPPORTED;
    }
}

InterlocState dtoToInterlocState(InterlocStateDTO state) {
    switch (state) {
    case InterlocStateDTO::STANDBY:
        return InterlocState_STANDBY;

    case InterlocStateDTO::OPERATING:
        return InterlocState_OPERATING;

    case InterlocStateDTO::ANGLE_CALIB_SENDER:
        return InterlocState_ANGLE_CALIB_SENDER;

    case InterlocStateDTO::ANGLE_CALIB_RECEIVER:
        return InterlocState_ANGLE_CALIB_RECEIVER;

    case InterlocStateDTO::TWR_CALIB_INITIATOR:
        return InterlocState_TWR_CALIB_INITIATOR;

    case InterlocStateDTO::TWR_CALIB_RESPONDER:
        return InterlocState_TWR_CALIB_RESPONDER;

    default:
        return InterlocState_UNSUPORTED;
    }
}
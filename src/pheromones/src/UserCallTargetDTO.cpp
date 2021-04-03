#include "UserCallTargetDTO.h"

UserCallTargetDTO targetToDTO(UserCallTarget status) {
    switch (status) {
    case UserCallTarget_HOST:
        return UserCallTargetDTO::HOST;
    case UserCallTarget_BUZZ:
        return UserCallTargetDTO::BUZZ;
    case UserCallTarget_UNKNOWN:
    default:
        return UserCallTargetDTO::UNKNOWN;
    }
}

UserCallTarget dtoToTarget(UserCallTargetDTO status) {
    switch (status) {

    case UserCallTargetDTO::HOST:
        return UserCallTarget_HOST;

    case UserCallTargetDTO::BUZZ:
        return UserCallTarget_BUZZ;
    case UserCallTargetDTO::UNKNOWN:
    default:
        return UserCallTarget_UNKNOWN;
    }
}

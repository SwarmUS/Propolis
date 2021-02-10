#include "UserCallDestinationDTO.h"

UserCallDestinationDTO destinationToDTO(UserCallDestination status) {
    switch (status) {
    case UserCallDestination_HOST:
        return UserCallDestinationDTO::HOST;
    case UserCallDestination_BUZZ:
        return UserCallDestinationDTO::BUZZ;
    case UserCallDestination_UNKNOWN:
    default:
        return UserCallDestinationDTO::UNKNOWN;
    }
}

UserCallDestination dtoToDestination(UserCallDestinationDTO status) {
    switch (status) {

    case UserCallDestinationDTO::HOST:
        return UserCallDestination_HOST;

    case UserCallDestinationDTO::BUZZ:
        return UserCallDestination_BUZZ;
    case UserCallDestinationDTO::UNKNOWN:
    default:
        return UserCallDestination_UNKNOWN;
    }
}

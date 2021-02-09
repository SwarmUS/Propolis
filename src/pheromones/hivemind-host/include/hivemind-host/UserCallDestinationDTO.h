#ifndef __USERCALLDESTINATION_H_
#define __USERCALLDESTINATION_H_

#include <user-call.pb.h>

/**@brief The destination of a user call*/
enum class UserCallDestinationDTO { UNKNOWN, HOST, BUZZ };

/**
 *@brief get the equivalent of a nanobp destination to a dto
 *
 *@return the dto equivalent
 **/
UserCallDestinationDTO destinationToDTO(UserCallDestination status);

/**
 *@brief get the equivalent of a dto destination to a nanopb one
 *
 *@return the nanopb equivalent
 **/
UserCallDestination dtoToDestination(UserCallDestinationDTO status);

#endif // __USERCALLDESTINATION_H_

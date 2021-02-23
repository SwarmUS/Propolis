#ifndef __USERCALLDESTINATION_H_
#define __USERCALLDESTINATION_H_

#include <message.pb.h>

/**@brief The target of a user call once it reached a robot ID, distinguishes the differents
 * consumers of those messages*/
enum class UserCallTargetDTO { UNKNOWN, HOST, BUZZ };

/**
 *@brief get the equivalent of a nanobp target to a dto
 *
 *@return the dto equivalent
 **/
UserCallTargetDTO targetToDTO(UserCallTarget status);

/**
 *@brief get the equivalent of a dto target to a nanopb one
 *
 *@return the nanopb equivalent
 **/
UserCallTarget dtoToTarget(UserCallTargetDTO status);

#endif // __USERCALLDESTINATION_H_

#ifndef __CALIBRATIONMODEDTO_H__
#define __CALIBRATIONMODEDTO_H__

#include <message.pb.h>

enum class CalibrationModeDTO {UNSUPORTED, INITIATOR, RESPONDER};

/**
 *@brief get the equivalent of a nanobp calibration mode to a dto
 *
 *@return the dto equivalent
 **/
CalibrationModeDTO targetToDTO(CalibrationMode mode);

/**
 *@brief get the equivalent of a dto calibration mode to a nanopb one
 *
 *@return the nanopb equivalent
 **/
CalibrationMode dtoToTarget(CalibrationModeDTO mode);

#endif //__CALIBRATIONMODEDTO_H__

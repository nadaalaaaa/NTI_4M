/*
 * STEPPER_config.c
 *
 * Created: 01/03/2023 18:00:49
 *  Author: dell
 */ 
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"

SMMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] ={
	{0,1,2,3}
};
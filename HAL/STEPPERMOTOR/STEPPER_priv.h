/*
 * STEPPER_priv.h
 *
 * Created: 01/03/2023 17:59:22
 *  Author: dell
 */ 


#ifndef STEPPER_PRIV_H_
#define STEPPER_PRIV_H_

typedef struct STMmotor
{
	
	
	u8 firstMotorPin;
	
	u8 secondMotorPin;

    u8 thirdMotorPin;
    u8 forthMotorPin;
}SMMotor;

extern SMMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] ;



#endif /* STEPPER_PRIV_H_ */
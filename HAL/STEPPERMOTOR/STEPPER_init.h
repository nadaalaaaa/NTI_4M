/*
 * STEPPER_init.h
 *
 * Created: 01/03/2023 17:58:49
 *  Author: dell
 */ 


#ifndef STEPPER_INIT_H_
#define STEPPER_INIT_H_


#define full_step 1
#define half_step 2

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

void Stepper_MotorInit(void);

void Stepper_MotorCW( u8 u8MotorNumber);

void Stepper_MotorCCW( u8 u8MotorNumber);




#endif /* STEPPER_INIT_H_ */
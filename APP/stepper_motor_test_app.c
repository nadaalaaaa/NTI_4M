/*
 * stepperMotor.c
 *
 * Created: 26/02/2023 09:03:46
 * Author : dell
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "STEPPER_config.h"
#include "STEPPER_init.h"
#include "STEPPER_priv.h"

int main(void)
{Stepper_MotorInit();
	
	Stepper_MotorCW(0);
	Stepper_MotorCCW(0);
    while (1) 
    {
    }
}


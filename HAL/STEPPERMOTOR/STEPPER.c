/*
 * STEPPER.c
 *
 * Created: 01/03/2023 17:58:33
 *  Author: dell
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

void Stepper_MotorInit(void){
	for( u8 i = 0 ; i < NUMBER_OF_MOTORS ; i++ )
	{
		#if STEPPER_Port==PORT_A
		dio_vidConfigChannel(DIO_PORTA, ArrayOfMotor[i].firstMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTA, ArrayOfMotor[i].secondMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTA, ArrayOfMotor[i].thirdMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTA, ArrayOfMotor[i].forthMotorPin, STD_HIGH);
		#elif STEPPER_Port==PORT_B
		dio_vidConfigChannel(DIO_PORTB, ArrayOfMotor[i].firstMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTB, ArrayOfMotor[i].secondMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTB, ArrayOfMotor[i].thirdMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTB, ArrayOfMotor[i].forthMotorPin, STD_HIGH);
		#elif  STEPPER_Port==PORT_C
		dio_vidConfigChannel(DIO_PORTC, ArrayOfMotor[i].firstMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTC, ArrayOfMotor[i].secondMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTC, ArrayOfMotor[i].thirdMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTC, ArrayOfMotor[i].forthMotorPin, STD_HIGH);
		#elif  STEPPER_Port==PORT_D
		dio_vidConfigChannel(DIO_PORTD, ArrayOfMotor[i].firstMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTD, ArrayOfMotor[i].secondMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTD, ArrayOfMotor[i].thirdMotorPin, STD_HIGH);
		dio_vidConfigChannel(DIO_PORTD, ArrayOfMotor[i].forthMotorPin, STD_HIGH);
		#endif
	}
}

void Stepper_MotorCW( u8 u8MotorNumber){
	#if STEP_MODE == half_step
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x09;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x08;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x0C;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x04;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x06;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x02;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW);
		//PORTD = 0x03;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x01;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	   //PORTD = 0x09;		/* Last step to initial position */
	  _delay_ms(period);
	  _delay_ms(1000);
	  
	  
	#elif STEP_MODE == full_step
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x0C;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
	//PORTD = 0x06;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW);
	//PORTD = 0x03;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;		/* Last step to initial position */
	_delay_ms(period);
	_delay_ms(1000);
	#endif
}

void Stepper_MotorCCW( u8 u8MotorNumber){
	#if STEP_MODE == half_step
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;
	_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x01;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW);
		//PORTD = 0x03;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
		//PORTD = 0x02;
		_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
	//PORTD = 0x06;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
	//PORTD = 0x04;
	_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x0C;
		_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x08;
		_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;
	_delay_ms(period);
	 _delay_ms(1000);
	#elif STEP_MODE == full_step
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW);
	//PORTD = 0x03;
	_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_LOW );
	//PORTD = 0x06;
	_delay_ms(period);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_HIGH);
		dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
		//PORTD = 0x0C;
		_delay_ms(period);
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].firstMotorPin,STD_HIGH );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].secondMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].thirdMotorPin,STD_LOW );
	dio_vidWriteChannel(STEPPER_Port,  ArrayOfMotor[u8MotorNumber].forthMotorPin,STD_HIGH );
	//PORTD = 0x09;
	_delay_ms(period);
	 _delay_ms(1000);
	#endif
}
/*
 * PWM_TMR0.c
 *
 * Created: 26/02/2023 14:05:52
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "TIMR00_priv.h"
#include "TIMR0_config.h"
#include "TIMR0_int.h"
#include "TIMR1_priv.h"
#include "TIMR1_config.h"
#include "TIMR1_init.h"
#include "TIMR2_priv.h"
#include "TIMR2_config.h"
#include "TIMR2_int.h"
#include "led.h"
#include "led_config.h"
#include "GIE.h"



/* timer0 overflow interrupt */

u8 counts=0;
void fun(void){
	if(counts==40){led_toggle(led1); counts=0; }
	else counts++;
	
}

int main( void )
{ 
	
	led_init(led1); //PD0
	TIMER1_void_Init();
	dio_vidConfigChannel(DIO_PORTD,5,OUTPUT);//oc1A
	while(1)
	{
		for(u8 j=0;j<=255;j++){
			TIMER1_void_SetCompareValA(j);
		}
	}
	
	
}

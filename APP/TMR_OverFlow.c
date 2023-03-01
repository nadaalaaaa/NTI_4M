/*
 * timer.c
 *
 * Created: 26/02/2023 10:39:57
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



u8 counts=0;
void fun(void){
	if(counts==5){led_toggle(led1); counts=0; TIMER0_void_SetTimerReg(66);}
	else counts++;
	
}

int main( void )
{  TIMER0_void_SetOVCallBack(fun ) ;
	led_init(led1); //PD0
	TIMER0_void_Init();
	TIMER0_void_SetTimerReg(66);
	TIMER0_void_EnableOVInt();
	GIE_enable();
	/*TIMER2_void_SetOVCallBack(fun ) ;
	led_init(led1); //PD0
	TIMER2_void_Init();
	TIMER2_void_SetTimerReg(66);
	TIMER2_void_EnableOVInt();
	GIE_enable();*/
	/*TIMER1_void_SetOVCallBack(fun ) ;
	led_init(led1); //PD0
	TIMER1_void_Init();
	TIMER1_void_SetTimerReg(66);
	TIMER1_void_EnableOVInt();
	GIE_enable();*/
	while(1);
}
/*
 * timer_CTC_APP.c
 *
 * Created: 26/02/2023 12:04:05
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
#include "led.h"
#include "led_config.h"
#include "GIE.h"

/* timer0 overflow interrupt */

u8 counts=0;
void fun(void){
	if(counts==5){led_toggle(led1); counts=0; }
	else counts++;
	
}

int main( void )
{  TIMER0_void_SetCTCCallBack(fun) ;
	led_init(led1); //PD0
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(250);
	TIMER0_void_EnableCTCInt();
	GIE_enable();
	
	while(1);
}
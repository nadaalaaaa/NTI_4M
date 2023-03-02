/*
 * externalinterrupt.c
 *
 * Created: 24/02/2023 10:26:33
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "button.h"
#include "button_config.h"
#include "led.h"
#include "led_config.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "EXTI0_Config.h"
#include "EXTI0_int.h"
#include "EXTI0_private.h"
#include "EXTI1_Config.h"
#include "EXTI1_int.h"
#include "EXTI1_private.h"
#include "EXTI2_Config.h"
#include "EXTI2_int.h"
#include "EXTI2_private.h"


void test(void){
	led_toggle(led1);
	_delay_ms(500);
}
void test1(void){
	
		led_toggle(led2);
		_delay_ms(500);

	
}

int main(void)
{      EXT0_voidCallBack(test);
	EXT0_voidInit ();
	EXT0_voidEnable();
	Enable_GIE0 ();
	led_init(led1); //PORTA.5 source
	led_init(led2); //PORTA.6 source
	while(1);
}
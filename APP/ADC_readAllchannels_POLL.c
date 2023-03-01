/*
 * adcAllChannels.c
 *
 * Created: 25/02/2023 19:36:40
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "ADC_config.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "lcd.h"
#include "lcd_config.h"
#include "GIE.h"
#include "EXTI0_Config.h"
#include "EXTI0_int.h"
#include "EXTI0_private.h"

u16 value;
void test(u16 vall){
	value=vall;
}
void test1(void){
	//ADC_voidStartConversion();
	//toggleled
}
int main(void)
{ADC_voidInit();
	ADC_voidEnable();
	ADC_voidAutoTrigger();
	lcd_init();
	
	while(1)
	{ ADC_ReadALLChannels();
		//ADC_ReadSpecificChannels(2);
	}
	return 0;
}



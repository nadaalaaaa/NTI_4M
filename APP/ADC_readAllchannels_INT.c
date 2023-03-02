/*
 * ADCallChannelsINT.c
 *
 * Created: 25/02/2023 20:09:30
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

u16 value;
void test(u16 vall){
	value=vall;
	ADC_ReadALLChannels();
}
int main(void)
{
	ADC_voidCallBack(test);
	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidAutoTrigger();
	ADC_voidInterrputEnable();
	GIE_enable();
	lcd_init();
	
	while(1)
	{   
		ADC_voidStartConversion();
		
	}
	return 0;
}




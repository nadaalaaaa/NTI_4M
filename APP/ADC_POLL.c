/*
 * adc.c
 *
 * Created: 24/02/2023 15:15:12
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

int main(void)
{
	
	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidAutoTrigger();
	lcd_init();
	
	while(1)
	{   lcd_displyStr("ADC value");	/* Write string on 1st line of LCD */
		ADC_voidStartConversion();
		lcd_sendCmd(0xc4);	
		value=ADC_u16ReadADCInMV();
		LCDConvertINTtoSTR(value);
		_delay_us(500);
		lcd_displyStr("  ");
		lcd_sendCmd(CLEAR_COMMAND);
	}
	return 0;
}


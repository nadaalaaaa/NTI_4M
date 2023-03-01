/*
 * autotrigger.c
 *
 * Created: 25/02/2023 15:53:41
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
{EXT0_voidCallBack(test1);
	ADC_voidCallBack(test);
	ADC_voidInit();
	
	ADC_voidAutoTrigger();
	ADC_voidInterrputEnable();
	lcd_init();
	EXT0_voidInit ();
	ADC_voidEnable();
	EXT0_voidEnable();
	GIE_enable();
	
	while(1)
	{   lcd_displyStr("ADC value");	/* Write string on 1st line of LCD */
		
		lcd_sendCmd(0xc4);
		//value=ADC_u16ReadADCInMV();
		LCDConvertINTtoSTR(value);
		_delay_us(500);
		lcd_displyStr("  ");
		lcd_sendCmd(CLEAR_COMMAND);
	}
	return 0;
}


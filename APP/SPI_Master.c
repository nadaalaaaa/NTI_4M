/*
 * SPI.c
 *
 * Created: 04/03/2023 08:59:22
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "GIE.h"
#include "lcd.h"
#include "lcd_config.h"
#include "SPI.h"
#include "SPI_config.h"
#include "SPI_priv.h"
#include "button_config.h"
#include "button.h"

u8 val='A';
u8 fun(void){
	return val;
}
///////////////master
int main(void)
{  ISR_voidCallBack(fun);
	 lcd_init();
	button_init(button1);
	button_init(button2);
	button_init(button3);
	lcd_sendCmd(CLEAR_COMMAND);
	//lcd_displyChar('A');
    SPI_Master_Init();
	GIE_enable();
	SPI_voidSendDataISR(val);
    while (1) 
    {/*if(button_get_status(button1)==pressed){
		SPI_Msend_Byte('A');
		_delay_ms(500);
		}
		if(button_get_status(button2)==pressed){
			SPI_Msend_Byte('B');
			_delay_ms(500);
		}
		if(button_get_status(button3)==pressed){
			SPI_Msend_Byte('C');
			_delay_ms(500);
		}*/
    }
}


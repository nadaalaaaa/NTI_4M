/*
 * SPI_slave.c
 *
 * Created: 04/03/2023 11:09:58
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
#include "led.h"
#include "led_config.h"
u8 res;
void fun(u8 byte){
	res=byte;
}

//////////////slave
int main(void)
{   ISR_voidCallBack(fun);
	u8 val;
	lcd_init();
	led_init();
	led_off(led1);
	led_off(led2);
	led_off(led3);
	lcd_sendCmd(CLEAR_COMMAND);
	//lcd_displyChar('B');
    SPI_Slave_Init();
	GIE_enable();
	res=SPI_u8ReadDataISR();
	lcd_displyChar(res);
    while (1) 
    {//val=SPI_Sreceive_Byte();
		//lcd_displyChar(val);
		/*if(val=='A'){
			led_on(led1);
			_delay_ms(500);
		}
		if(val=='B'){
			led_on(led2);
			_delay_ms(500);
		}
		if(val=='C'){
			led_on(led3);
			_delay_ms(500);
		}*/
    }
}


/*
 * I2C_SLAVE.c
 *
 * Created: 05/03/2023 13:52:13
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "lcd.h"
#include "lcd_config.h"
#include "I2C.h"
#include "I2C_config.h"
#include "I2C_priv.h"
#include "GIE.h"


int main(void)
{lcd_init();
	s8 count=0;
	s8 x=0;
	s8 Ack_status;
    I2C_SlaveInit(0x20); ////////slave address
	lcd_sendCmd(CLEAR_COMMAND);
    while (1) 
    
	{
		x=I2C_Slave_Listen();
		lcd_displyChar('a');
		switch(x){
		case 0: 
		do
		{  count = I2C_Slave_Receive();	/* Receive data byte*/
			lcd_displyChar(count);
			_delay_ms(500);
			} while (count != -1);			/* Receive until STOP/REPEATED START */
			count = 0;
		break;
		case 1:
		do
		{
			Ack_status = I2C_Slave_Transmit(count);/* Send data byte */
			count++;
		} while (Ack_status == 0);
		break;
		default: 
		break;
	}
    }
}


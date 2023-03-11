/*
 * Internal_eeprom.c
 *
 * Created: 11/03/2023 10:28:41
 * Author : dell
 */ 
#define F_CPU 8000000
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "lcd.h"
#include "lcd_config.h"
#include "EEPROM.h"
#include "EEPROM_Reg.h"


int main(void)
{u8 z;
	lcd_init();
   u8 arr[5]={1,4,2,7,5};
	   for(u8 i=0;i<5;i++){
		   EEPROM_write(i, arr[i]);
	   }
	   for(u8 j=0;j<5;j++){
		   z=EEPROM_read(j);
		   LCDConvertINTtoSTR(z);
		   _delay_ms(500);
		   lcd_sendCmd(CLEAR_COMMAND);
	   }
    while (1) 
    {
    }
}


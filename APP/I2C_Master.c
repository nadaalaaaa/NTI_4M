/*
 * I2C.c
 *
 * Created: 05/03/2023 09:24:33
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
{
    u8 arr[5]={3,4,5,6,7};
		I2C_BITRATE();
    I2C_Init();
    I2C_Start(0xA0); /////address of master if any one want send to me
   I2C_Write_M(0x20);

    while (1) 
    {  
		
		for (u8 i=0;i<5;i++)
	    {
		    I2C_Write_M(arr[i]);
		    _delay_ms(500);
	    }
		I2C_Stopcond();
    }
}


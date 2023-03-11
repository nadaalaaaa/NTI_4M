/*
 * Counter.c
 *
 * Created: 11/03/2023 08:41:16
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
#include "TIMR0_config.h"
#include "TIMR00_priv.h"
#include "TIMR0_int.h"


int main(void)
{
    lcd_init();
    lcd_sendCmd(CLEAR_COMMAND);
	dio_vidConfigChannel(DIO_PORTB, 0,INPUT); //ENABLE COUNTER PIN
    TIMER0_void_Init();
    u8 val=0;
    while (1)
    {
	    val= TIMER0_GetTimerReg(); //GET NUMBER OF COUNTS FROM TCNT0 REG
	    LCDConvertINTtoSTR((u16)val); //DISPLAY NUMBER OF COUNTS
		lcd_sendCmd(CLEAR_COMMAND);
	    
    }
}

